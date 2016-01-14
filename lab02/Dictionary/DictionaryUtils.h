#pragma once

#include "stdafx.h"
#include <stdio.h>
#include <iostream>
#include <string>
#include <map>
#include <fstream>

std::string GetTranslation(std::map<std::string, std::string> &dictionary, const std::string &word);

void AddTranslation(std::map<std::string, std::string> &dictionary, const std::string &word, const std::string &translation);

bool ReadDictionaryFromFile(std::ifstream &dictionaryFile, std::map<std::string, std::string> &dictionary);

bool WriteDictionaryToFile(std::ofstream &dictionaryFile, std::map<std::string, std::string> const &dictionary);