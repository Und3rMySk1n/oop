#pragma once

#include "stdafx.h"

std::string ExpandTemplate(std::string const &tpl, std::map<std::string, std::string>const &params);

std::string EscapeStringForRegular(std::string const &originalString);