//Includes header file for TechClocks and other include files
#include <iostream>
#include "TechClocks.h";
using namespace std;

//Constructor class for TechClocks
TechClocks::TechClocks(int t_hours, int t_minutes, int t_seconds) {
	this->m_realHour = t_hours;
	this->m_realMinute = t_minutes;
	this->m_realSecond = t_seconds;
}

//Returns real hour in object TechClocks
int TechClocks::getHour() {
	return this->m_realHour;
}

//Returns real minutes in object TechClocks
int TechClocks::getMinute() {
	return this->m_realMinute;
}

//Returns real seconds in object TechClocks
int TechClocks::getSecond() {
	return this->m_realSecond;
}

//Sets hour in object TechClocks
void TechClocks::setHour(unsigned int t_hour) {
	this->m_realHour = t_hour;
}

//Sets minute in object TechClocks
void TechClocks::setMinute(unsigned int t_minute) {
	this->m_realMinute = t_minute;
}

//Sets second in object TechClocks
void TechClocks::setSecond(unsigned int t_second) {
	this->m_realSecond = t_second;
}

//Adds one hour to the objects hour variable
void TechClocks::addOneHour() {
	//Declare variables
	unsigned int STATIC_ZERO = 0;
	unsigned int STATIC_ONE = 1;
	unsigned int STATIC_TWENTY_THREE = 23;

	//Adds one hour to both clocks and appropriately determines how to handle when realhour exceeds 23.
	this->m_realHour = this->m_realHour + STATIC_ONE;
	if (this->m_realHour > STATIC_TWENTY_THREE) {
		this->m_realHour = STATIC_ZERO;
	}
}

//Adds one minute to the objects minute variable
void TechClocks::addOneMinute(){
	//Declare variables
	unsigned int STATIC_ZERO = 0;
	unsigned int STATIC_ONE = 1;
	unsigned int STATIC_SIXTY = 60;
	//Adds one minute to both clocks and appropriately determines how to handle when realminute exceeds 60.
	m_realMinute = m_realMinute + STATIC_ONE;
	if (this->m_realMinute >= STATIC_SIXTY) {
		this->m_realMinute = STATIC_ZERO;
		addOneHour();
	}
}

//Adds one second to the objects second variable
void TechClocks::addOneSecond() {
	//Declare variables
	unsigned int STATIC_ZERO = 0;
	unsigned int STATIC_ONE = 1;
	unsigned int STATIC_SIXTY = 60;

	//Adds one second to both clocks and appropriately determines how to handle when realseconds exceeds 60.
	m_realSecond = m_realSecond + STATIC_ONE;
	if (m_realSecond >= STATIC_SIXTY) {
		m_realSecond = STATIC_ZERO;
		addOneMinute();
	}
}

//Prints out two digit string given int variable
string TechClocks::twoDigitString(unsigned int t_n) {
	//Declare Variables
	unsigned int STATIC_TEN = 10;
	unsigned int STATIC_ZERO = 0;

	//Checks to see if the parameter is equal to 0, and if so returns 00.
	if (t_n == STATIC_ZERO) {
		return "00";
	}

	//Checks to see if the parameter is less than 10, and if so returns 0 added to the userString variable.
	if (t_n < STATIC_TEN) {
		string userString = to_string(t_n);
		return "0" + userString;
	}

	//Converts parameter to string and returns userString.
	string userString = to_string(t_n);
	return userString;
}

//Prints out the correct format for the border of clocks
string TechClocks::nCharString(size_t t_n, char t_c) {
	//Delcare variables to use in method.
	string userString;
	unsigned int i;

	//For loop which iterates depending on the parameter size. This prints the parameter char c.
	for (i = 0; i < t_n; i++) {
		userString.push_back(t_c);
	}

	//Returns userString that was built during the above loop.
	return userString;
}

//Formats the 24-hour tech clock object
string TechClocks::formatTime24(unsigned int t_timeHours, unsigned int t_timeMinutes, unsigned int t_timeSeconds) {
	//Delcare variables to construct the formatted time based on ta 24 hour scale.
	string displayHours;
	string displayMinutes;
	string displaySeconds;
	string displayTime;
	unsigned int STATIC_ZERO = 0;
	unsigned int STATIC_TEN = 10;
	unsigned int STATIC_TWENTY_FOUR = 24;
	unsigned int STATIC_SIXTY = 60;

	//Compares each input depending on hours, minutes, or seconds and its restrictions.
	if (t_timeHours == STATIC_ZERO || t_timeHours == STATIC_TWENTY_FOUR) {
		displayHours = twoDigitString(t_timeHours);
	}
	if (t_timeMinutes == STATIC_ZERO || t_timeMinutes == STATIC_SIXTY) {
		displayMinutes = twoDigitString(t_timeMinutes);
	}
	if (t_timeSeconds == STATIC_ZERO ||t_timeSeconds == STATIC_SIXTY) {
		displaySeconds = twoDigitString(t_timeSeconds);
	}
	if (t_timeHours > STATIC_ZERO && t_timeHours < STATIC_TEN) {
		displayHours = twoDigitString(t_timeHours);
	}
	if (t_timeMinutes > STATIC_ZERO && t_timeMinutes < STATIC_TEN) {
		displayMinutes = twoDigitString(t_timeMinutes);
	}
	if (t_timeSeconds > STATIC_ZERO && t_timeSeconds < STATIC_TEN) {
		displaySeconds = twoDigitString(t_timeSeconds);
	}
	if (t_timeHours >= STATIC_TEN && t_timeHours < STATIC_TWENTY_FOUR) {
		displayHours = twoDigitString(t_timeHours);
	}
	if (t_timeMinutes >= STATIC_TEN && t_timeMinutes < STATIC_SIXTY) {
		displayMinutes = twoDigitString(t_timeMinutes);
	}
	if (t_timeSeconds >= STATIC_TEN && t_timeSeconds < STATIC_SIXTY) {
		displaySeconds = twoDigitString(t_timeSeconds);
	}

	//Constructs the appropriate string to set the correct format.
	displayTime = displayHours + ":" + displayMinutes + ":" + displaySeconds;
	return displayTime;
}

//Formats the 12-hour tech clcok object
string TechClocks::formatTime12(unsigned int t_timeHours, unsigned int t_timeMinutes, unsigned int t_timeSeconds) {
	//Declare variables to use to format time into a 12-hour status.
	string displayHours;
	string displayMinutes;
	string displaySeconds;
	string displayTime;
	unsigned int tempHours;
	unsigned int STATIC_ZERO = 0;
	unsigned int STATIC_TEN = 10;
	unsigned int STATIC_TWELVE = 12;
	unsigned int STATIC_TWENTY_FOUR = 24;
	unsigned int STATIC_SIXTY = 60;

	//If statements which compare the parameters passed to the appropriate format given different use cases.
	if (t_timeHours == STATIC_ZERO) {
		displayHours = twoDigitString(t_timeHours);
	}
	if (t_timeMinutes == STATIC_ZERO || t_timeMinutes == STATIC_SIXTY) {
		displayMinutes = twoDigitString(t_timeMinutes);
	}
	if (t_timeSeconds == STATIC_ZERO || t_timeSeconds == STATIC_SIXTY) {
		displaySeconds = twoDigitString(t_timeSeconds);
	}
	if (t_timeHours > STATIC_ZERO && t_timeHours < STATIC_TEN) {
		displayHours = twoDigitString(t_timeHours);
	}
	if (t_timeMinutes > STATIC_ZERO && t_timeMinutes < STATIC_TEN) {
		displayMinutes = twoDigitString(t_timeMinutes);
	}
	if (t_timeSeconds > STATIC_ZERO && t_timeSeconds < STATIC_TEN) {
		displaySeconds = twoDigitString(t_timeSeconds);
	}
	if (t_timeHours >= STATIC_TEN && t_timeHours <= STATIC_TWELVE) {
		displayHours = twoDigitString(t_timeHours);
	}
	if (t_timeMinutes >= STATIC_TEN && t_timeMinutes < STATIC_SIXTY) {
		displayMinutes = twoDigitString(t_timeMinutes);
	}
	if (t_timeSeconds >= STATIC_TEN && t_timeSeconds < STATIC_SIXTY) {
		displaySeconds = twoDigitString(t_timeSeconds);
	}
	if (t_timeHours > STATIC_TWELVE && t_timeHours < STATIC_TWENTY_FOUR) {
		tempHours = t_timeHours - STATIC_TWELVE;
		displayHours = twoDigitString(tempHours);
	}

	//Compares whether the time given is in AM or PM depnding on the hour given.
	if (t_timeHours >= STATIC_ZERO && t_timeHours < STATIC_TWELVE) {
		displayTime = displayHours + ":" + displayMinutes + ":" + displaySeconds + " A M";
	}
	else {
		displayTime = displayHours + ":" + displayMinutes + ":" + displaySeconds + " P M";
	}

	//Returns the final formatted string.
	return displayTime;
}

//Prints the menu of both clocks in correct format
void TechClocks::printMenu(const char* t_strings[], unsigned int t_numStrings, unsigned char t_width) {
	//Declare variables
	unsigned int i;
	unsigned int j;
	unsigned int REQUIRED_LENGTH = 7;

	//Prints first line of characters for the display of the menu.
	cout << nCharString(t_numStrings, t_width);
	cout << endl;

	//For loop which populates the menu with the given actions defined in main() function, which will be controlled
	//by the user input.
	for (i = 0; i < sizeof(t_strings); i++) {
		cout << t_width << " " << i + 1 << " " << "-" << " " << t_strings[i];
		for (j = 0; j < t_numStrings - strlen(t_strings[i]); j++) {
			if (j == t_numStrings - strlen(t_strings[i]) - REQUIRED_LENGTH) {
				cout << t_width;
			}
			else {
				cout << " ";
			}
		}
		cout << endl;
	}

	//Prints out the bottom of the menu with specified characters.
	cout << nCharString(t_numStrings, t_width);
	cout << endl;
	cout << endl;
}

//Gets the menu choice from user which is set to 4
unsigned int TechClocks::getMenuChoice(unsigned int t_maxChoice) {
	//Delcare variable to run the while loop and the user's input. Returns the input as an integer.
	unsigned int counter = 0;
	unsigned int userChoice;
	unsigned int STATIC_ONE = 1;
	unsigned int STATIC_ZERO = 0;

	///Outputs to console what the user must do in order to satisfy this requirement.
	cout << "Please enter a number between (1-4) based on the menu given above. If you would like to quit, please press 4" << endl;

	//While loop which checks to see if the userChoice satisfies the if-statement. If it does, return integer, else immediately exit program.
	while (counter == STATIC_ZERO) {
		cin >> userChoice;
		if (userChoice >= STATIC_ONE && userChoice <= t_maxChoice) {
			return userChoice;
		}
		else {
			return 4;
		}
	}
}

//Displays the clocks with hours, minutes, and seconds with appropriate format.
void TechClocks::displayClocks(unsigned int t_displayHours, unsigned int t_displayMinutes, unsigned int t_displaySeconds) {
	unsigned int STATIC_TWENTY_SEVEN = 27;
	unsigned int STATIC_ONE = 1;
	unsigned int STATIC_EIGHT = 8;
	unsigned int STATIC_SIX = 6;
	unsigned int STATIC_SEVEN = 7;
	unsigned int STATIC_NINE = 9;
	unsigned int STATIC_THREE = 3;
	char BORDER_STAR = '*';
	char BORDER_SPACE = ' ';

	//Displays the 12 hour clock and 24 hour clock given the following formatted output lines below.
	cout << nCharString(STATIC_TWENTY_SEVEN, BORDER_STAR) << nCharString(STATIC_THREE, BORDER_SPACE) << nCharString(STATIC_TWENTY_SEVEN, BORDER_STAR) << endl;
	cout << nCharString(STATIC_ONE, BORDER_STAR) << nCharString(STATIC_SIX, BORDER_SPACE) << "12-HOUR CLOCK" << nCharString(STATIC_SIX, BORDER_SPACE);
	cout << nCharString(STATIC_ONE, BORDER_STAR) << nCharString(STATIC_THREE, BORDER_SPACE) << nCharString(STATIC_ONE, BORDER_STAR) << nCharString(STATIC_SIX, BORDER_SPACE) << "24-HOUR CLOCK" << nCharString(STATIC_SIX, BORDER_SPACE) << nCharString(STATIC_ONE, BORDER_STAR) << endl;
	cout << endl;
	cout << nCharString(STATIC_ONE, BORDER_STAR) << nCharString(STATIC_SIX, BORDER_SPACE) << formatTime12(t_displayHours, t_displayMinutes, t_displaySeconds) << nCharString(STATIC_SEVEN, BORDER_SPACE) << nCharString(STATIC_ONE, BORDER_STAR) << nCharString(STATIC_THREE, BORDER_SPACE);
	cout << nCharString(STATIC_ONE, BORDER_STAR) << nCharString(STATIC_EIGHT, BORDER_SPACE) << formatTime24(t_displayHours, t_displayMinutes, t_displaySeconds) << nCharString(STATIC_NINE, BORDER_SPACE) << nCharString(STATIC_ONE, BORDER_STAR) << endl;
	cout << nCharString(STATIC_TWENTY_SEVEN, BORDER_STAR) << nCharString(STATIC_THREE, BORDER_SPACE) << nCharString(STATIC_TWENTY_SEVEN, BORDER_STAR) << endl;
	cout << endl;
}


