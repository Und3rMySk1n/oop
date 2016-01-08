#include "stdafx.h"
#include "Car.h"

using Gear = CCar::Gear;
using Direction = CCar::Direction;

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
	if (m_speed == 0)
	{
		return Direction::stop;
	}
	else if (m_gear == Gear::reverse)
	{
		return Direction::backward;
	}
	else
	{
		return Direction::forward;
	}	
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