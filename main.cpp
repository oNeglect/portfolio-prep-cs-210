//Lawrence Arundel May 2022-June 2022 Project 2 CS 210 SNHU
#include <iostream>
#include <string>
#include <memory>
#include "BankingApp.h"
using namespace std;

int main() {
	//Declare variables
	int counter = 0;
	int STATIC_ZERO = 0;

	//Create object to be used to display data for banking app
	auto bank = std::make_unique<BankingApp>();

		while (counter == STATIC_ZERO) {
			bank->displayDataInput();
			bank->displayStaticReportWithout();
			bank->displayStaticReportWith();
			
			//If user input was equal to N, then the program increments counter and exits the program
			if (bank->continueProgram() == "N") {
				counter++;
			}
		}
	return 0;
}
