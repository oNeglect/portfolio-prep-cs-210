//Lawrence Arundel Assignment 7-1 Project 3 June 2022
#include <Python.h>
#include <iostream>
#include <Windows.h>
#include <cmath>
#include <string>
#include <fstream>
#include <stdexcept>
#include <vector>

using namespace std;

/*
Description:
	To call this function, simply pass the function name in Python that you wish to call.
Example:
	callProcedure("printsomething");
Output:
	Python will print on the screen: Hello from python!
Return:
	None
*/
void CallProcedure(string pName)
{
	char* procname = new char[pName.length() + 1];
	std::strcpy(procname, pName.c_str());

	Py_Initialize();
	PyObject* my_module = PyImport_ImportModule("CS210_Starter_PY_Code");
	PyErr_Print();
	PyObject* my_function = PyObject_GetAttrString(my_module, procname);
	PyObject* my_result = PyObject_CallObject(my_function, NULL);
	Py_Finalize();

	delete[] procname;
}

/*
Description:
	To call this function, pass the name of the Python functino you wish to call and the string parameter you want to send
Example:
	int x = callIntFunc("PrintMe","Test");
Output:
	Python will print on the screen:
		You sent me: Test
Return:
	100 is returned to the C++
*/
int callIntFunc(string proc, string param)
{
	char* procname = new char[proc.length() + 1];
	std::strcpy(procname, proc.c_str());

	char* paramval = new char[param.length() + 1];
	std::strcpy(paramval, param.c_str());


	PyObject* pName, * pModule, * pDict, * pFunc, * pValue = nullptr, * presult = nullptr;
	// Initialize the Python Interpreter
	Py_Initialize();
	// Build the name object
	pName = PyUnicode_FromString((char*)"CS210_Starter_PY_Code");
	// Load the module object
	pModule = PyImport_Import(pName);
	// pDict is a borrowed reference 
	pDict = PyModule_GetDict(pModule);
	// pFunc is also a borrowed reference 
	pFunc = PyDict_GetItemString(pDict, procname);
	if (PyCallable_Check(pFunc))
	{
		pValue = Py_BuildValue("(z)", paramval);
		PyErr_Print();
		presult = PyObject_CallObject(pFunc, pValue);
		PyErr_Print();
	}
	else
	{
		PyErr_Print();
	}
	//printf("Result is %d\n", _PyLong_AsInt(presult));
	Py_DECREF(pValue);
	// Clean up
	Py_DECREF(pModule);
	Py_DECREF(pName);
	// Finish the Python Interpreter
	Py_Finalize();

	// clean 
	delete[] procname;
	delete[] paramval;


	return _PyLong_AsInt(presult);
}

/*
Description:
	To call this function, pass the name of the Python functino you wish to call and the string parameter you want to send
Example:
	int x = callIntFunc("doublevalue",5);
Return:
	25 is returned to the C++
*/
int callIntFunc(string proc, int param)
{
	char* procname = new char[proc.length() + 1];
	std::strcpy(procname, proc.c_str());

	PyObject* pName, * pModule, * pDict, * pFunc, * pValue = nullptr, * presult = nullptr;
	// Initialize the Python Interpreter
	Py_Initialize();
	// Build the name object
	pName = PyUnicode_FromString((char*)"CS210_Starter_PY_Code");
	// Load the module object
	pModule = PyImport_Import(pName);
	// pDict is a borrowed reference 
	pDict = PyModule_GetDict(pModule);
	// pFunc is also a borrowed reference 
	pFunc = PyDict_GetItemString(pDict, procname);
	if (PyCallable_Check(pFunc))
	{
		pValue = Py_BuildValue("(i)", param);
		PyErr_Print();
		presult = PyObject_CallObject(pFunc, pValue);
		PyErr_Print();
	}
	else
	{
		PyErr_Print();
	}
	//printf("Result is %d\n", _PyLong_AsInt(presult));
	Py_DECREF(pValue);
	// Clean up
	Py_DECREF(pModule);
	Py_DECREF(pName);
	// Finish the Python Interpreter
	Py_Finalize();

	// clean 
	delete[] procname;

	return _PyLong_AsInt(presult);
}


void main(){
	//Delcare variables
	int counter = 0;
	int secondCounter = 0;
	int thirdCounter = 0;
	int STATIC_ZERO = 0;
	int STATIC_ONE = 1;
	int i;
	int searchQuantity;
	string userInput;
	string currentItem;
	string searchItem;

	//While loop to create menu for user and finds inputs to run program
	while (counter == STATIC_ZERO) {
		cout << "1: Print number of times item appears in list" << endl;
		cout << "2: Frequency of specific item" << endl;
		cout << "3: Graphical display as a text-based histogram" << endl;
		cout << "4: Exit" << endl;
		cout << endl;
		cout << "Enter your selection as a number 1, 2, 3, or 4." << endl;

		//Gets user input for program to operate effectively 
		getline(cin, userInput);

		//endl for readibility
		cout << endl;

		//If user input is 1, then it does correct response which reads from file and prints out 
		//frequency of items within the file
		if (userInput == "1") {

			//Opens file to perform read operations
			fstream myOpenFile;
			myOpenFile.open("CS210_Project_Three_Input_File.txt");


			while (myOpenFile.is_open()) {
				//Create vector to store values in it with value type string
				vector<string> listItems;

				//Read from file and store into the list of items if the item does not exists
				while (!myOpenFile.eof()) {
					//Read file and store into current item variable
					myOpenFile >> currentItem;

					//If the item exists, do nothing, else add the item to the vector
					if (find(listItems.begin(), listItems.end(), currentItem) == listItems.end()) {
						listItems.push_back(currentItem);
					}
				}

				//For loop which iterates through list and calls specified python method for output
				for (int i = STATIC_ZERO; i < listItems.size(); i++) {
					callIntFunc("ListPrint", listItems[i]);

				}

				//endl for readibility
				cout << endl;

				// Closes the file
				myOpenFile.close();
			}
		}
		//Else if user input is equal to 2, then it finds a specified item within the file, and prints out the
		//frequency of the item within the file.
		else if (userInput == "2") {

			//If user input is empty, print invalid input, else store user input into
			//search item variable to use further in code.
			cout << "Please enter item to search, cannot be blank" << endl;

			//Read user input for searched item
			getline(cin, searchItem);

			//endl for readibility
			cout << endl;

			//While loop which checks to see if the search item is empty or not
			while (secondCounter == STATIC_ZERO) {

				//If search items is empty, output error message, else break out of while loop
				if (searchItem.empty()) {
					cout << "Invalid input, Please enter item to search, cannot be blank" << endl;
					getline(cin, searchItem);
					cout << endl;
				}
				else {
					secondCounter++;
				}
			}
			
			//Calls specific python method, and if it returns 0 print appropriate output to user, else
			//prints out the number of times that specific item is in the file
			if (callIntFunc("PrintFrequency", searchItem) == 0) {
				cout << "Item is not found in the file" << endl;
				cout << "Quantity of " << searchItem << ": " <<  "0" << endl;
				cout << endl;
			}
			else {
				cout << "Quantity of " << searchItem << ": " << callIntFunc("PrintFrequency", searchItem) << endl;
				cout << endl;
			}
		}

		//Else if user input is equal to 3, it calls python code and prints out a histogram based on the file
		//created within the python file
		else if (userInput == "3") {
			//Declare Variables
			string itemName;
			string itemQuantity;

			//Call function which creates .dat file to be utilized later in this code for computational purposes
			callIntFunc("PrintHistogram", "0");
			
			//Opens file to perform read operations
			fstream myOpenFile;
			myOpenFile.open("frequency.dat");

			while (myOpenFile.is_open()) {
				//While the file has content to store in these two variables, print out the contents to console
				
				while (myOpenFile >> itemName >> itemQuantity.erase(STATIC_ZERO, STATIC_ONE)) {
					cout << itemName << " ";
					for (int i = STATIC_ZERO; i < stoi(itemQuantity); i++) {
						cout << '*';
					}
					cout << endl;
				}

			//Closes file
			myOpenFile.close();

			//Endl for readibility
			cout << endl;

			}
		}

		//Else if the user input is equal to 4, we end the program by adding one to counter variable
		else if (userInput == "4") {
			counter++;
		}

		//Else user entered an invalid input, and output error message to console
		else {
		cout << "Invalid input" << endl;
		cout << endl;
		}
	}
}




