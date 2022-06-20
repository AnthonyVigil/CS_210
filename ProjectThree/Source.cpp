// Anthony Vigil
// CS-210 Programming Languages

#include <Python.h>
#include <iostream>
#include <iomanip>
#define NOMINMAX
#include <Windows.h>
#undef NOMINMAX
#include <cmath>
#include <string>
#include <fstream>

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

    // Added Python Code to Import From
    PyObject* my_module = PyImport_ImportModule("CS210_Starter_PY_Code (1)");
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
    // Added Python Code 
    pName = PyUnicode_FromString((char*)"CS210_Starter_PY_Code (1)");
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
    // Added Python Code
    pName = PyUnicode_FromString((char*)"CS210_Starter_PY_Code (1)");

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

/*
// DisplayMenu() Function will ask for user input in a displayed menu
Output:
        Menu asks for user input options of 1-4; 
        Input 1 will calculate the number of times each item appears.
        Input 2 will calculate the frequency of a specific item. 
        Input 3 will create a histogram based on the appearances of the items
        Input 4 will end or terminate the program, allowing the user to quit.

*/

// Menu
void DisplayMenu() {

    // Menu Loops
    int menuInput = 0;

    // Variable to keep count for frequency
    int itemQuant = 0;

    // Variable for searched term by user
    string findItem;

    // Variable to keep count of searched words
    int countWords = 0;

    // Variable for storing the name of item
    string NameofItem;

    // Sets Red Asterisks
    string redColor = "\033[31;1m";  

    // Sets default color for menu
    string defColor = "\033[0m";     

    // Opens Input File
    ifstream InputFile;

    // While loop is not equal to 4, ask for user inputs
    while (menuInput != 4) {

        // Asks for user input
        std::cout << "---------------------------------- Menu -------------------------------------------" << std::endl;
        std::cout << "[1] Calculate the number of times each individual item appears" << std::endl;
        std::cout << "[2] Calculate the frequency of a specific item" << std::endl;
        std::cout << "[3] Create a text-based histogram listing the number of appearances of each item" << std::endl;
        std::cout << "[4] Quit" << std::endl;
        std::cout << "-----------------------------------------------------------------------------------" << std::endl;

        // Save input into variable
        std::cin >> menuInput;

        // While loop to check valid input
        while (std::cin.fail()) {

            // Clear
            std::cin.clear();

            // Checks input
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            // Asks user for a valid input
            std::cout << "Please enter a valid input: ";

            // Store user input into variable
            std::cin >> menuInput;
        }

        // Switch
        switch (menuInput) {

        // Case 1: Option 1, Calculate the number of times each item appears
        case 1:

            // Clear
            system("CLS");

            // Call Python 
            // Function CountAll from Python file
            CallProcedure("CountItems");

            // Space
            std::cout << std::endl;

            // Break
            break;

        
        // Case 2: Option 2, Calculate the frequency of a specific item
        case 2:

            //Clear
            system("CLS");

            // Asks user for input of item
            std::cout << "Which item would you like to search for?" << std::endl;

            // Store input in variable
            std::cin >> findItem;

            // Call function from Python code
            countWords = callIntFunc("CountFreq", findItem);

            // Print Word Count
            std::cout << std::endl << findItem << ": " << countWords << std::endl << std::endl;

            // Break
            break;

        // Case 3: Option 3, Create a histogram based on the number of appearances of each item
        // Displayed with Asterisks
        case 3:

            // Clear
            system("CLS");

            // Call CollectData function in Python File
            CallProcedure("FreqHistogram"); 

            // Open file frequency
            InputFile.open("frequency.dat");

            // Store first item on list  into variable
            InputFile >> NameofItem;

            // Store quantity of first item on list into variable
            InputFile >> itemQuant;

            // While loop, Print histogram
            while (!InputFile.fail()) {

                // Set to default color 
                std::cout << defColor;

                // Prints the item name for histogram
                std::cout << std::setw(14) << std::left << NameofItem << std::setw(6);

                // Sets color to red
                std::cout << redColor;

                // For loop, for iteration of item quantity
                // Print asterisks
                for (int i = 0; i < itemQuant; i++) {

                    //Print asterisks in color red
                    std::cout << std::right << "*";
                }

                // Print next line
                // Next item name
                // Next quantity of item
                std::cout << std::endl;
                InputFile >> NameofItem;
                InputFile >> itemQuant;
            }

            // Close Input file
            InputFile.close();

            // Default color with new line
            std::cout << defColor << endl;

            // Break
            break;

        // Case 4: Option 4, Terminates program
        case 4:
            cout << endl << "Program Terminated" << endl;
            return;

        // For default case, invalid input
        default:

            // Ask user for valid input
            std::cout << "Please enter a valid input.";

            // Print new line
            std::cout << std::endl;

            // Break
            break;
        }
    }
}

// Calls Main method
// Menu
void main()
{
    //Display menu
    DisplayMenu();

}