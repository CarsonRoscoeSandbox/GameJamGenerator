#pragma once

#include "targetver.h"
#include <iostream>
#include <stdio.h>
#include <tchar.h>
#include <string>
#include <sstream>
#include <locale>
#include <fstream>
#include <stdlib.h>
#include <windows.h>
#include <vector>

const std::string CURVEBALLFILE = "Curveballs.txt";
const std::string GENREFILE = "Genres.txt";
const std::string THEMEFILE = "Themes.txt";

int getInt();
std::string getString();
bool getBool();
std::string getRandomLine(std::string fileName);
void displayScreen();