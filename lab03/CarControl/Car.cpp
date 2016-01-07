#include "stdafx.h"
#include "Car.h"

using Gear = CCar::Gear;

bool CCar::IsEngineOn()const
{
	return m_engineIsOn;
}

Gear CCar::GetGear()const
{
	return m_gear;
}

int CCar::GetSpeed()const
{
	return m_speed;
}