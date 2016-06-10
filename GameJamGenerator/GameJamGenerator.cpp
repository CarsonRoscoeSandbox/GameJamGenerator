// GameJamGenerator.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

int hours = 0;
int curveBalls = 0;
int curveballsGiven = 0;
std::string theme = "";
std::string genre = "";
std::vector<std::string> curveBallVector;
SYSTEMTIME startTime;

int main(int argc, char* argv[])
{
	std::cout << "Welcome to GameJam Generator!" << std::endl;
	std::cout << "Let's get started. How many hours will this GameJam go on for?" << std::endl;
	hours = getInt();
	std::cout << hours << " hours huh! That's fantastic! Would you like us to throw curveballs? [Y/N]" << std::endl;
	if (getBool()) {
		std::cout << "Awesome! How many curveballs?" << std::endl;
		curveBalls = getInt();
		if (curveBalls < 0) {
			std::cout << "You can't trick me. We'll just assign you 3 cause you won't play nice." << std::endl;
			curveBalls = 3;
		} else if (curveBalls == 0) {
			std::cout << "That's no fun :/ Oh well. Live your life." << std::endl;
		} else if (curveBalls < 3) {
			std::cout << curveBalls << " curveballs is a solid amount." << std::endl;
		} else if (curveBalls < 8) {
			std::cout << curveBalls << " curveballs! You're really going all out!" << std::endl;
		} else {
			std::cout << curveBalls << " curveballs! OH GOD that's a lot!" << std::endl;
		}
	}
	std::cout << "Time for your Genre and Theme!" << std::endl << "Your genre is..." << std::endl;
	genre = getRandomLine(GENREFILE);
	std::cout << genre << std::endl;
	std::cout << "And your theme is..." << std::endl;
	theme = getRandomLine(THEMEFILE);
	std::cout << theme << std::endl;
	std::cout << "When you are ready to start, press enter" << std::endl;
	std::cin;
	
	GetSystemTime(&startTime);
	while (true) {
		displayScreen();
	}

	getInt();
    return 0;
}

int getInt() {
	std::string input = "";
	int result;
	while (true) {
		getline(std::cin, input);
		std::stringstream iss(input);
		if (iss >> result) {
			return result;
		}
		else {
			std::cout << "Invalid number. Please try again" << std::endl;
		}
	}
}

std::string getString() {
	std::string input = "";
	getline(std::cin, input);
	return input;
}

bool getBool() {
	std::string input = "";
	std::locale loc;
	int result;
	while (true) {
		getline(std::cin, input);
		if (input.at(0) == 'y' || input.at(0) == 'Y') {
			return true;
		} else if (input.at(0) == 'n' || input.at(0) == 'N') {
			return false;
		}
		std::cout << "Invalid answer. Please type Y or N, or anything that starts with Y or N." << std::endl;
	}
}

std::string getRandomLine(std::string fileName) {
	std::ifstream infile(fileName);
	srand(time(NULL));
	int randomLine = rand() % std::count(std::istreambuf_iterator<char>(infile), std::istreambuf_iterator<char>(), '\n'), i = 0;
	infile.seekg(0, std::ios::beg);
	std::string line = "";
	for (line = "", i = 0; getline(infile, line); i++) {
		if (i == randomLine) {
			return line;
		}
	}
	return  "[Error]";
}

void displayScreen() {
	SYSTEMTIME currentTime;
	SYSTEMTIME leftTime;
	GetSystemTime(&currentTime);

	int endHour = startTime.wHour + hours;
	int days = 0;
	while (endHour > 24) {
		endHour -= 24;
		days++;
	}
	SYSTEMTIME endTime;
	GetSystemTime(&endTime);
	endTime.wDay = startTime.wDay + days;
	endTime.wHour = endHour;
	endTime.wSecond = startTime.wSecond;

	system("cls");
	std::cout << "START TIME:   " << startTime.wHour << ":" << startTime.wMinute << ":" << startTime.wSecond << std::endl;
	std::cout << "CURRENT TIME: " << currentTime.wHour << ":" << currentTime.wMinute << ":" << currentTime.wSecond << std::endl;
	std::cout << "TIME LEFT: " << endTime.wHour - currentTime.wHour << ":" << endTime.wMinute - currentTime.wMinute << ":" << endTime.wSecond - currentTime.wSecond;
	std::cout << "GENRE: " << genre << std::endl;
	std::cout << "THEME: " << theme << std::endl;
	if (curveBalls > 0) {
		std::cout << "CURVEBALLS: " << curveballsGiven << "/" << curveBalls << std::endl;
		for (auto curveBall : curveBallVector) {
			std::cout << "-" << curveBall << std::endl;
		}
	}

	Sleep(1000);
}