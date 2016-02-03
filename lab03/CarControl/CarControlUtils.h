#pragma once

#include "stdafx.h"
#include "Car.h"

void ShowInfo(CCar const &car);

void ProcessCommand(std::string &userCommand, CCar &car);

void ProcessEngineOffCommand(CCar &car);

void ProcessEngineOnCommand(CCar &car);

void ProcessSetGearCommand(std::string &userCommand, CCar &car);

void ProcessSetSpeedCommand(std::string &userCommand, CCar &car);