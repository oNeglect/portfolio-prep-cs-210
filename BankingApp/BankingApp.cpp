#include <iostream>
#include <conio.h>
#include <stdexcept>
#include <string>
#include<cmath>
#include <cstdlib>
#include <iomanip>
#include <algorithm> 
using namespace std;

#include "BankingApp.h"

//Constructor for BankingApp class
BankingApp::BankingApp() {
	m_initialInvestment = 0;
	m_monthlyDeposit = 0;
	m_interestRate = 0;
	m_numberOfYears = 0;
	m_printOtherTable = false;
}

//Sets the initial Investment with user input in double data type
void BankingApp::setInitialInvestment(double t_initialInvestment) {
	this->m_initialInvestment = t_initialInvestment;
}

//Sets the monthly deposit variable with user input in double data type
void BankingApp::setMonthlyDeposit(double t_monthlyDeposit) {
	this->m_monthlyDeposit = t_monthlyDeposit;
}

//Sets the interest rate variable with user input in double data type
void BankingApp::setInterestRate(double t_interestRate) {
	this->m_interestRate = t_interestRate;
}

//Sets the number of years variable with user input in int data type
void BankingApp::setNumberOfYears(int t_numberOfYears) {
	this->m_numberOfYears = t_numberOfYears;
}

//Sets the variable to which table to print to either true of false
void BankingApp::setOtherTable(bool t_printOtherTable) {
	this->m_printOtherTable = t_printOtherTable;
}

//Returns the initial investment amount in double data type
double BankingApp::getInitialInvestment() {
	return this->m_initialInvestment;
}

//Returns the monthly deposit amount in double data type
double BankingApp::getMonthlyDeposit() {
	return this->m_monthlyDeposit;
}

//Returns the interest rate amount in double data type
double BankingApp::getInterestRate() {
	return this->m_interestRate;
}

//Returns the number of years amount in int data type
int BankingApp::getNumberOfYears() {
	return this->m_numberOfYears;
}

//Returns the value of of which table to print depending on true or false
bool BankingApp::getOtherTable() {
	return this->m_printOtherTable;
}

//Display menu for user to input and set initial investment, monthly deposit, interest rate, and number of years
//with proper formatting and outputs two menus. The first menu shows those inputs, and the second shows the inputs
//on the menu
void BankingApp::displayDataInput() {
	//Declare variables
	int counter = 0;
	unsigned int STATIC_ZERO = 0;
	unsigned int STATIC_ONE = 1;
	unsigned int i;
	string stringInitialInvestment;
	string stringMonthlyDeposit;
	string stringInterestRate;
	string stringNumberOfYears;


	//Prints interface for user to start inputting data entry points for initial investment, monthly deposit
	//annual interest, and number of years to find compounded amounts and interest rate amounts
	cout << "**********************************" << endl;
	cout << "********** " << "Data Input" << " ************" << endl;
	cout << "Initial Investment Amount:" << endl;
	cout << "Monthly Deposit:" << endl;
	cout << "Annual Interest:" << endl;
	cout << "Number of years:" << endl;
	cout << "Press any key to continue . . ." << endl;
	_getch(); //Pauses program and waits for user to hit any key to continue
	cout << endl;

	//Requires user to enter the input for initial investment
	cout << "Please enter an initial investment amount greater than zero" << endl;

	//Attemps to try and find initial investment amount given certain parameters. Once this input is found,
	//the program will continue
	while (counter == STATIC_ZERO) {
		try {
			//Checks input from user for initialInvestment
			getline(cin, stringInitialInvestment);

			//If the initial investment is less than zero, throw the runtime error and execute catch portion of code
			for (i = STATIC_ZERO; i < stringInitialInvestment.length(); i++) {
				if (isalpha(stringInitialInvestment.at(i)) || stringInitialInvestment.at(i) == ' ' ||
					(stringInitialInvestment.at(STATIC_ZERO) == '0' && stringInitialInvestment.length() - STATIC_ONE > STATIC_ZERO) ||
					ispunct(stringInitialInvestment.at(i)) && stringInitialInvestment.at(i) != '.' || count(stringInitialInvestment.begin(), stringInitialInvestment.end(), '.') > STATIC_ONE ||
					stringInitialInvestment.at(stringInitialInvestment.length() - STATIC_ONE) == '.') {
					throw runtime_error("Invalid input, please input a number greater than or equal to zero");
				}
			}

			//If initital investment variable is empty, then output to user to enter another variable, else set initial investment 
			//private variable equal to a converted double of the string initial investment variable
			if (stringInitialInvestment.empty()) {
				throw runtime_error("Invalid input, please input a number greater than or equal to zero");
			}
			else {
				setInitialInvestment(stod(stringInitialInvestment));
				counter++;
			}
		}

		//Outputs the error message when user input is less than zero
		catch (runtime_error& excpt) {
			cout << excpt.what() << endl;
		}
	}

	//Add endl for easier readibility after user input
	cout << endl;

	//Set counter back to zero to reuse in program
	counter = STATIC_ZERO;

	//Requires user to enter the input for initial investment
	cout << "Please enter a monthly deposit amount greater than or equal to zero" << endl;

	//Attemps to try and find monthly deposit amount given certain parameters. Once this input is found,
	//the program will continue
	while (counter == STATIC_ZERO) {
		try {

			//Checks input from user for monthly deposit
			getline(cin, stringMonthlyDeposit);

			//If the monthly deposit is less than zero, throw the runtime error and execute catch portion of code
			for (i = STATIC_ZERO; i < stringMonthlyDeposit.length(); i++) {
				if (isalpha(stringMonthlyDeposit.at(i)) || stringMonthlyDeposit.at(i) == ' ' ||
					(stringMonthlyDeposit.at(STATIC_ZERO) == '0' && stringMonthlyDeposit.length() - STATIC_ONE > STATIC_ZERO) ||
					ispunct(stringMonthlyDeposit.at(i)) && stringMonthlyDeposit.at(i) != '.' || count(stringMonthlyDeposit.begin(), stringMonthlyDeposit.end(), '.') > STATIC_ONE ||
					stringMonthlyDeposit.at(stringMonthlyDeposit.length() - STATIC_ONE) == '.') {
					throw runtime_error("Invalid input, please input a number greater than or equal to zero");
				}
			}


			//If monthly deposit variable is empty, then output to user to enter another variable, else set monthly deposit 
			//private variable equal to a converted double of the string monthly deposit variable
			if (stringMonthlyDeposit.empty()) {
				throw runtime_error("Invalid input, please input a number greater than or equal to zero");
			}
			else {
				setMonthlyDeposit(stod(stringMonthlyDeposit));
				counter++;
			}
		}

		//Outputs the error message when user input is less than zero
		catch (runtime_error& excpt) {
			cout << excpt.what() << endl;
		}
	}

	//Add endl for easier readibility after user input
	cout << endl;

	//Set counter back to zero to reuse in program
	counter = STATIC_ZERO;

	//Requires user to enter the input for interest rate
	cout << "Please enter a interest rate amount greater than or equal to zero" << endl;

	//Attemps to try and find interest rate amount given certain parameters. Once this input is found,
	//the program will continue
	while (counter == STATIC_ZERO) {
		try {

			//Checks input from user for interest rate
			getline(cin, stringInterestRate);

			//If the interest rate is less than zero, throw the runtime error and execute catch portion of code
			for (i = STATIC_ZERO; i < stringInterestRate.length(); i++) {
				if (isalpha(stringInterestRate.at(i)) || stringInterestRate.at(i) == ' ' ||
					(stringInterestRate.at(STATIC_ZERO) == '0' && stringInterestRate.length() - STATIC_ONE > STATIC_ZERO) ||
					ispunct(stringInterestRate.at(i)) && stringInterestRate.at(i) != '.' || count(stringInterestRate.begin(), stringInterestRate.end(), '.') > STATIC_ONE ||
					stringInterestRate.at(stringInterestRate.length() - STATIC_ONE) == '.') {
					throw runtime_error("Invalid input, please input a number greater than or equal to zero");
				}
			}

			//If interest rate variable is empty, then output to user to enter another variable, else set interest rate 
			//private variable equal to a converted double of the string interest rate variable
			if (stringInterestRate.empty()) {
				throw runtime_error("Invalid input, please input a number greater than or equal to zero");
			}
			else {
				setInterestRate(stod(stringInterestRate));
				counter++;
			}

		}
		//Outputs the error message when user input is less than zero
		catch (runtime_error& excpt) {
			cout << excpt.what() << endl;
		}

	}
	//Add endl for easier readibility after user input
	cout << endl;

	//Set counter back to zero to reuse in program
	counter = STATIC_ZERO;

	//Requires user to enter the input for number of years
	cout << "Please enter a year amount greater than zero" << endl;

	//Attemps to try and find number of years amount given certain parameters. Once this input is found,
	//the program will continue
	while (counter == STATIC_ZERO) {
		try {

			//Checks input from user for number of years
			getline(cin, stringNumberOfYears);

			//If the number of years is less than zero, throw the runtime error and execute catch portion of code
			for (i = STATIC_ZERO; i < stringNumberOfYears.length(); i++) {
				if (isalpha(stringNumberOfYears.at(i)) || stringNumberOfYears.at(i) == ' ' ||
					(stringNumberOfYears.at(STATIC_ZERO) == '0' && stringNumberOfYears.length() - STATIC_ONE > STATIC_ZERO) ||
					stringNumberOfYears.at(STATIC_ZERO) == '0' || ispunct(stringNumberOfYears.at(i))) {
					throw runtime_error("Invalid input, please input a number greater than zero");
				}
			}

			//Sets number of years attribute from the user's input and adds one to counter to break out of while loop.
			if (stringNumberOfYears.empty()) {
				cout << "Invalid input, please input a number greater than zero" << endl;
			}
			else {
				setNumberOfYears(stoi(stringNumberOfYears));
				counter++;
			}

		}
		//Outputs the error message when user input is less than zero
		catch (runtime_error& excpt) {
			cout << excpt.what() << endl;
		}
	}

	//Add endl for easier readibility after user input
	cout << endl;

	//Formats output by two decimal places
	std::cout << std::fixed;
	std::cout << std::setprecision(2);

	//Prints interface for user to start inputting data entry points for initial investment, monthly deposit
	//annual interest, and number of years to find compounded amounts and interest rate amounts. Out also
	//Depends on whether the first character in string is a decimal point or not and handlees appropriately
	cout << "**********************************" << endl;
	cout << "********** " << "Data Input" << " ************" << endl;
	if (stringInitialInvestment.at(STATIC_ZERO) == '.') {
		cout << "Initial Investment Amount:" << "  $" << getInitialInvestment() << endl;
	}
	else {
		cout << "Initial Investment Amount:" << "  $" << getInitialInvestment() << endl;
	}
	if (stringMonthlyDeposit.at(STATIC_ZERO) == '.') {
		cout << "Monthly Deposit:" << "  $" << getMonthlyDeposit() << endl;
	}
	else {
		cout << "Monthly Deposit:" << "  $" << getMonthlyDeposit() << endl;
	}
	cout << "Annual Interest:" << "  %" << getInterestRate() << endl;
	cout << "Number of years:" << " " << getNumberOfYears() << endl;
	cout << "Press any key to continue . . ." << endl;
	_getch(); //Pauses program and waits for user to hit any key to continue
	cout << endl;
}


//Displays the static report with calculations including monthly deposits formatted properly
void BankingApp::displayStaticReportWith() {
	//Output the header of table for balance and interest without additional monthly deposits
	cout << "      " << "Balance and Interest With Additional Monthly Deposits     " << endl;
	cout << "================================================================" << endl;
	cout << "  Year      " << "  Year End Balance    " << "  Year End Earned Interest" << endl;
	cout << "----------------------------------------------------------------" << endl;

	//Call method which calculates and outputs balance with monthly deposits, returns double if need to use.
	calculateBalanceWithMonthlyDeposit(getInitialInvestment(), getMonthlyDeposit(), getInterestRate(), getNumberOfYears());
}

//Displays the static report with calculations including monthly deposits formatted properly
void BankingApp::displayStaticReportWithout() {
	//Output the header of table for balance and interest without additional monthly deposits
	cout << "    " << "Balance and Interest Without Additional Monthly Deposits     " << endl;
	cout << "================================================================" << endl;
	cout << "  Year      " << "   Year End Balance    " << "Year End Earned Interest" << endl;
	cout << "----------------------------------------------------------------" << endl;

	//Call method which calculates and outputs balance without monthly deposits, returns double if need to use.
	calculateBalanceWithoutMonthlyDeposit(getInitialInvestment(), getInterestRate(), getNumberOfYears());

	//After printing this table, set the variable for bool equal to true to be able to distinguish which format to print
	setOtherTable(true);

	//End line added for readibility
	cout << endl;
}

void BankingApp::printDetails(int t_year, double t_yearEndBalance, double t_interestEarned) {
	//Declare variables
	int STATIC_ZERO = 0;
	int STATIC_ONE = 1;
	int STATIC_TWO = 2;
	int STATIC_THREE = 3;
	//Formats output by two decimal places
	std::cout << std::setprecision(STATIC_TWO);

	//Checks on bool variable, if false, prints format for without monthly deposit, else prints table format for with 
	//monthly deposits
	//Max digit decltype equal to 10 max digits total for output using numeric limits to be stored in double variable
	//format aligned to the right
	if (getOtherTable() == false) {
		std::cout << std::right << std::setw(std::numeric_limits<decltype(t_year)>::max_digits10) << "     " << t_year << "     ";
		std::cout << std::right << std::setw(std::numeric_limits<decltype(t_yearEndBalance)>::max_digits10) << "$" + to_string(t_yearEndBalance).substr(STATIC_ZERO, to_string(t_yearEndBalance).find('.')) << to_string(t_yearEndBalance).substr(to_string(t_yearEndBalance).find("."), STATIC_THREE) << "        ";
		std::cout << std::right << std::setw(std::numeric_limits<decltype(t_yearEndBalance)>::max_digits10) << "$" + to_string(t_interestEarned).substr(STATIC_ZERO, to_string(t_interestEarned).find('.')) << to_string(t_interestEarned).substr(to_string(t_interestEarned).find("."), STATIC_THREE) << "        " << endl;
	}
	else {
		std::cout << std::right << std::setw(std::numeric_limits<decltype(t_year)>::max_digits10) << "     " << t_year << "    ";
		std::cout << std::right << std::setw(std::numeric_limits<decltype(t_yearEndBalance)>::max_digits10) << "$" + to_string(t_yearEndBalance).substr(STATIC_ZERO, to_string(t_yearEndBalance).find('.')) << to_string(t_yearEndBalance).substr(to_string(t_yearEndBalance).find("."), STATIC_THREE) << "          ";
		std::cout << std::right << std::setw(std::numeric_limits<decltype(t_yearEndBalance)>::max_digits10) << "$" + to_string(t_interestEarned).substr(STATIC_ZERO, to_string(t_interestEarned).find('.')) << to_string(t_interestEarned).substr(to_string(t_interestEarned).find("."), STATIC_THREE) << "       " << endl;
	}
}

//Calculates the balance which includes monthly deposit compounded monthly meaning number of times compounded equals 12.
//This returns a double in the proper format given user inputs
double BankingApp::calculateBalanceWithMonthlyDeposit(double t_initialInvestment, double t_monthlyDeposit, double t_interestRate, int t_numberOfYears) {
	//Delcare variables
	double nPeriod = 12.00;
	double conversionRate = t_interestRate / 100.00;
	double openingBalance = t_initialInvestment;
	double closingBalance = 0;
	double totalAmount = 0;
	double interestEarnedThisMonth = 0;
	double interestEarnedThisYear = 0;
	double STATIC_ONE = 1;
	double STATIC_ZERO = 0;
	double STATIC_TWELVE = 12;
	double STATIC_VALUE = 0.5;
	double STATIC_ONE_HUNDRED = 100;
	int i;

	//Checks if user input monthly deposit as zero and if so, returns calculate without monthly deposit
	if (t_monthlyDeposit == STATIC_ZERO) {
		return calculateBalanceWithoutMonthlyDeposit(t_initialInvestment, t_interestRate, t_numberOfYears);
	}

	//For loop which iterates and calculates the opening and closing balances compounded monthly
	for (i = STATIC_ZERO; i < (t_numberOfYears * nPeriod) + STATIC_ONE; i++) {
		
		//If i mod 12 equals zero, then wprint out the year end  balance and interest earned
		//Set interestEarnedThisYear equal to static zero
		if (i % 12 == STATIC_ZERO && i != STATIC_ZERO) {
			printDetails(i / STATIC_TWELVE, floor(openingBalance * STATIC_ONE_HUNDRED + STATIC_VALUE) / 100, floor(interestEarnedThisYear * STATIC_ONE_HUNDRED + STATIC_VALUE) / STATIC_ONE_HUNDRED);
			interestEarnedThisYear = STATIC_ZERO;
		}

		//If i is equal to zero, we will compute the interest earned this month, up date total amount and closing balance
		//update interest earned this year, and set opening balance equal to the closing balance for the next month
		if (i == STATIC_ZERO) {
			interestEarnedThisMonth = (t_initialInvestment + t_monthlyDeposit) * (conversionRate / nPeriod);
			totalAmount = openingBalance + m_monthlyDeposit;
			closingBalance = totalAmount + interestEarnedThisMonth;
			interestEarnedThisYear += interestEarnedThisMonth;
			openingBalance = closingBalance;
		}
		else {
			interestEarnedThisMonth = (openingBalance + t_monthlyDeposit) * (conversionRate / nPeriod);
			totalAmount = openingBalance + m_monthlyDeposit;
			closingBalance = totalAmount + interestEarnedThisMonth;
			interestEarnedThisYear += interestEarnedThisMonth;
			openingBalance = closingBalance;
		}

		
	}

	//If the number of years is equal to zero, then set the current balance equal to the initial investment,
	//and return the current balance
	if (t_numberOfYears == STATIC_ZERO) {
		openingBalance = t_initialInvestment;
		return openingBalance;
	}
	return openingBalance;
}

//Calculates the balance which does not include monthly deposit compounded monthly meaning number of times compounded equals 12.
//This returns a double in the proper format given user inputs
double BankingApp::calculateBalanceWithoutMonthlyDeposit(double t_initialInvestment, double t_interestRate, int t_numberOfYears) {
	//Delcare variables
	double nPeriod = 12.00;
	double conversionRate = t_interestRate / 100.00;
	double currentBalance = 0;
	double previousBalance = t_initialInvestment;
	double interestEarnedThisYear = 0;
	int STATIC_ONE = 1;
	int STATIC_ZERO = 0;
	int i;

	//For loop which iterates and calculates without the monthly contributions the interest earned over the course
	//of number of years specified and returns double of total balance after that many years
	for (i = STATIC_ZERO; i < t_numberOfYears; i++) {
		currentBalance = (double)(t_initialInvestment * pow(STATIC_ONE + (conversionRate / nPeriod), ((i + STATIC_ONE) * nPeriod)));
		interestEarnedThisYear = currentBalance - previousBalance;
		previousBalance = currentBalance;
		printDetails(i + STATIC_ONE, currentBalance, interestEarnedThisYear);
	}

	//if the number of years is equal to zero, then set the current balance equal to the initial investment,
	//and return the current balance
	if (t_numberOfYears == STATIC_ZERO) {
		currentBalance = t_initialInvestment;
		return currentBalance;
	}

	return currentBalance;
}

string BankingApp::continueProgram() {
	//Endl for readibility from previous method
	cout << endl;

	//Declare variables
	int i;
	int STATIC_ZERO = 0;
	int counter = 0;
	string userInput;

	//Present user options on whether they would like to continue program
	cout << "Would you like to continue this program? Press Y for yes or N for no" << endl;

	//Validate user input and return if user input is Y or N exclusively
	while (counter == STATIC_ZERO) {

		//Scan user input from console
		getline(cin, userInput);

		//If user input is Y or user input is N, then return the user's input, else return error message
		if (userInput == "Y" || userInput == "N") {
			//endl for readibility
			cout << endl;

			return userInput;
		}
		else {
			cout << "Invalid input, please enter Y for yes or N for no" << endl;
		}
	}
}


