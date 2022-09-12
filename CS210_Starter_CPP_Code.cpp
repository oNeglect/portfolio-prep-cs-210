#include <Python.h>
#include <iostream>
#include <Windows.h>
#include <cmath>
#include <string>
#include <stdexcept>

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
	PyObject* my_module = PyImport_ImportModule("PythonCode");
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
	pName = PyUnicode_FromString((char*)"PythonCode");
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
	pName = PyUnicode_FromString((char*)"PythonCode");
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


void main()
{
	//Delcare variables
	int counter = 0;
	int secondCounter = 0;
	int thirdCounter = 0;
	int STATIC_ZERO = 0;
	int STATIC_ONE = 1;
	int i;
	string userInput;

	//While loop to create menu for user and finds inputs to run program
	while (counter == STATIC_ZERO) {
		cout << "1: Display a Multiplication Table" << endl;
		cout << "2: Double a Value" << endl;
		cout << "3: Exit" << endl;
		cout << endl;
		cout << "Enter your selection as a number 1, 2, or 3." << endl;

		//Gets user input for program to operate effectively 
		getline(cin, userInput);

		//Checks to see if user input is either 1, 2, or 3 and acts accordingly.
		if (userInput == "1") {
			secondCounter = STATIC_ZERO;

			//Ask user for a valid input
			cout << "Enter a positive or negative number" << endl;

			while (secondCounter == STATIC_ZERO) {
				try {
					//Checks input from user for positive or negative integer
					getline(cin, userInput);
					
					//If user input is not a valid input, throw the runtime error and execute catch portion of code
					for (i = STATIC_ZERO; i < userInput.length(); i++) {
						if (isalpha(userInput.at(i)) || userInput.at(i) == ' ' ||
							(userInput.at(STATIC_ZERO) == '0' && userInput.length() - STATIC_ONE > STATIC_ZERO) ||
							ispunct(userInput.at(i)) && userInput.at(i) != '-' || count(userInput.begin(), userInput.end(), '-') > STATIC_ONE ||
							userInput.at(userInput.length() - STATIC_ONE) == '-' || userInput.at(STATIC_ZERO) == '-' && userInput.find('0') == true
							) {
							throw runtime_error("Invalid input, enter a positive or negative number");
						}
					}

					//If user input is not a positive or negative number, output the error message below, else add one
					//to second counter and break out of loop
					if (userInput.empty()) {
						throw runtime_error("Invalid input, enter a positive or negative number");
					}
					else {
						secondCounter++;
					}
				}

				//Outputs the error message when user input is less than zero
				catch (runtime_error& excpt) {
					cout << excpt.what() << endl;
				}
			}
		
			//Call function to output response to user given the valid input
			cout << endl;
			callIntFunc("MultiplicationTable", userInput);
			cout << endl;
		}
		else if (userInput == "2") {
			thirdCounter = 0;

			//Ask user for a valid input
			cout << "Enter a positive or negative number" << endl;

			while (thirdCounter == STATIC_ZERO) {
				try {
					//Checks input from user for positive or negative integer
					getline(cin, userInput);

					//If user input is not a valid input, throw the runtime error and execute catch portion of code
					for (i = STATIC_ZERO; i < userInput.length(); i++) {
						if (isalpha(userInput.at(i)) || userInput.at(i) == ' ' ||
							(userInput.at(STATIC_ZERO) == '0' && userInput.length() - STATIC_ONE > STATIC_ZERO) ||
							ispunct(userInput.at(i)) && userInput.at(i) != '-' || count(userInput.begin(), userInput.end(), '-') > STATIC_ONE ||
							userInput.at(userInput.length() - STATIC_ONE) == '-' || userInput.at(STATIC_ZERO) == '-' && userInput.find('0') == true
							) {
							throw runtime_error("Invalid input, enter a positive or negative number");
						}
					}

					//If user input is not a positive or negative number, output the error message below, else add one
					//to second counter and break out of loop
					if (userInput.empty()) {
						throw runtime_error("Invalid input, enter a positive or negative number");
					}
					else {
						thirdCounter++;
					}
				}

				//Outputs the error message when user input is less than zero
				catch (runtime_error& excpt) {
					cout << excpt.what() << endl;
				}
			}

			//Call function to output response to user given the valid input
			cout << endl;
			cout << "Your number squared is: " << callIntFunc("DoubleValue", userInput);
			cout << endl;
			cout << endl;
		}
		else if (userInput == "3") {
			counter++;
		}
		else {
			cout << "Invalid input" << endl;
			cout << endl;
		}
	}
}

