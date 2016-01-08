#pragma once

class CCar
{
public:
	enum class Gear
	{
		reverse = -1,
		neutral = 0,
		first = 1,
		second = 2,
		third = 3,
		fourth = 4,
		fifth = 5
	};

	enum class Direction
	{
		backward = -1,
		stop = 0,
		forward = 1
	};

	bool IsEngineOn() const;
	Gear GetGear() const;
	int GetSpeed() const;
	Direction GetDirection() const;

	bool TurnOnEngine();
	bool TurnOffEngine();
private:
	bool m_engineIsOn = false;
	Gear m_gear = Gear::neutral;
	int m_speed = 0;
};