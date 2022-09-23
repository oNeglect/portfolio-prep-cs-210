#pragma once
#ifndef TECH_CLOCKS_H
#define TECH_CLOCKS_H

#include <iostream>
#include <string>
using namespace std;

class TechClocks {
	//Public attributes for class TechClocks (declarations)
public:
	TechClocks(int t_realHour = 0, int t_realMinute = 0, int t_realSeconds = 0);
	int getHour();
	int getMinute();
	int getSecond();
	void setHour(unsigned int t_userHour);
	void setMinute(unsigned int t_userMinute);
	void setSecond(unsigned int t_userSecond);
	void addOneHour();
	void addOneMinute();
	void addOneSecond();
	string twoDigitString(unsigned int t_n);
	string nCharString(size_t t_n, char t_c);
	string formatTime24(unsigned int t_timeHours, unsigned int t_timeMinutes, unsigned int t_timeSeconds);
	string formatTime12(unsigned int t_timeHours, unsigned int t_timeMinutes, unsigned int t_timeSeconds);
	void printMenu(const char* t_strings[], unsigned int t_numStrings, unsigned char t_width);
	unsigned int getMenuChoice(unsigned int t_maxChoice);
	void displayClocks(unsigned int t_displayHours, unsigned int t_displayMinutes, unsigned int t_displaySeconds);

//Private atttributes for class TechClocks (variables)
private:
	int m_realHour;
	int m_realMinute;
	int m_realSecond;
};
#endif
