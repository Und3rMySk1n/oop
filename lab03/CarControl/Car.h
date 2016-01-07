#pragma once

class CCar
{
public:
	enum class Gear
	{
		rear = -1,
		neutral = 0,
		first = 1,
		second = 2,
		third = 3,
		fourth = 4,
		fifth = 5
	};

	bool IsEngineOn()const;
	Gear GetGear()const;
	int GetSpeed()const;
private:
	bool m_engineIsOn = false;
	Gear m_gear = Gear::neutral;
	int m_speed = 0;
};