#include "stdafx.h"
#include "Car.h"
#include <map>

using namespace std;

using Gear = CCar::Gear;
using Direction = CCar::Direction;
typedef map<Gear, CCar::allowedSpeedRange> SpeedRangeType;

SpeedRangeType const CCar::gearSpeedRange = { { Gear::reverse, { 0, 20 } }, 
											  { Gear::neutral, { 0, 150 } },
											  { Gear::first,   { 0, 30 } },
											  { Gear::second,  { 20, 50 } },
											  { Gear::third,   { 30, 60 } },
											  { Gear::fourth,  { 40, 90 } },
											  { Gear::fifth,   { 50, 150 } } };

bool CCar::IsEngineOn() const
{
	return m_engineIsOn;
}

Gear CCar::GetGear() const
{
	return m_gear;
}

int CCar::GetSpeed() const
{
	return m_speed;
}

Direction CCar::GetDirection() const
{
	return m_direction;
}

bool CCar::TurnOnEngine()
{
	if (!m_engineIsOn)
	{
		m_engineIsOn = true;
		return true;
	}
	else
	{
		return false;
	}
}

bool CCar::TurnOffEngine()
{
	if ((m_engineIsOn) && (m_gear == Gear::neutral) && (m_speed == 0))
	{
		m_engineIsOn = false;
		return true;
	}
	else
	{
		return false;
	}
}

bool CCar::IsSpeedAllowedForGear(int const speed, Gear const gear)
{
	if ((speed >= gearSpeedRange.at(gear).minSpeed) && (speed <= gearSpeedRange.at(gear).maxSpeed))
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool CCar::SetGear(Gear newGear)
{
	Gear currentGear = GetGear();
	Direction currentDirection = GetDirection();
	int currentSpeed = GetSpeed();

	if (IsEngineOn())
	{
		if (currentGear == newGear)
		{
			return true;
		}

		switch (newGear)
		{
		case Gear::reverse:
			if (((currentGear == Gear::neutral) || (currentGear == Gear::first)) && (currentSpeed == 0))
			{
				m_gear = newGear;
				return true;
			}
			else
			{
				return false;
			}
			break;
		case Gear::neutral:
			m_gear = newGear;
			return true;
			break;
		default:
			if ((currentDirection != Direction::backward) && (IsSpeedAllowedForGear(currentSpeed, newGear)))
			{
				m_gear = newGear;
				return true;
			}
			else
			{
				return false;
			}
			break;
		}
	}
	else
	{
		if (newGear == Gear::neutral)
		{
			m_gear = newGear;
			return true;
		}
		else
		{
			return false;
		}
	}
}

bool CCar::SetSpeed(int newSpeed)
{
	Gear currentGear = GetGear();
	int currentSpeed = GetSpeed();
	if ((!IsSpeedAllowedForGear(newSpeed, currentGear)) ||
		((currentGear == Gear::neutral)) && (newSpeed > currentSpeed))
	{
		return false;
	}

	m_speed = newSpeed;
	if (newSpeed == 0)
	{
		m_direction = Direction::stop;
	}
	else
	{
		if (currentGear == Gear::reverse)
		{
			m_direction = Direction::backward;
		}
		else
		{
			m_direction = Direction::forward;
		}
	}

	return true;
}