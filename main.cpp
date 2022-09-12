//Lawrence Arundel 3-1 Project One

//Includes for program to function properly
#include <string>
#include <iostream>
#include "TechClocks.h"
using namespace std;

int main() {
        //All Test variables which can be changed to test different values includes time, drawing character, and length of that character.
        unsigned int SET_HOUR = 3; //Feel free to change for testing, hours
        unsigned int SET_MINUTE = 22; //Feel free to change for testing, minutes
        unsigned int SET_SECOND = 1; //Feel free to change for testing, seconds
        unsigned int BORDER_LENGTH = 27; //Feel free to change for testing, border for menu option length
        unsigned int MENU_CHOICE = 4; 
        unsigned int MENU_ONE = 1;
        unsigned int MENU_TWO = 2;
        unsigned int MENU_THREE = 3;
        char BORDER_CHAR = '*'; //Feel free to change for testing
        const char* strings[] = {"Add One Hour" , "Add One Minute" , "Add One Second", "Exit Program" };
        unsigned int STATIC_ZERO = 0;

        //Counter used to dictate when to leave while loop to end program.
        unsigned int counter = 0;

        //Stores the input from user to determine which option to choose from in the menu.
        unsigned int userChoice = 0;

        //(Set arbitrary hours, minutes, seconds to any value. These values) are from the example given in the 
        //module for clarity, creating the objects to be used.
        TechClocks clock;
        clock.setHour(SET_HOUR);
        clock.setMinute(SET_MINUTE);
        clock.setSecond(SET_SECOND);

        //Start of while loop
        while (counter == STATIC_ZERO) {

            //Display both clocks to follow procedure calling get functions to easier readibility.
            clock.displayClocks(clock.getHour(), clock.getMinute(), clock.getSecond());

            //Display choices for the User to select from (1-4) Assign abitrary values for the dimension of menu.
            clock.printMenu(strings, BORDER_LENGTH, BORDER_CHAR);

            //Ask user for input using the specified menu and act accordingly.
            userChoice = clock.getMenuChoice(MENU_CHOICE);

            //If statements which dictate the outcome of the program either adding to time or ending program.
            if (userChoice == MENU_ONE) {
                clock.addOneHour();
            }
            else if (userChoice == MENU_TWO) {
                clock.addOneMinute();
            }
            else if (userChoice == MENU_THREE) {
                clock.addOneSecond();
            }
            else {
                counter++;
            }
            //Clears screen and refreshes input.
            system("cls");
        }
    }



 
