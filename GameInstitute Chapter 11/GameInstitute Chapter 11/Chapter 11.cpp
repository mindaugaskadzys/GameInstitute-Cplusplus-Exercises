#include <iostream>
#include "InputException.h"
using namespace std;

int main()
{
	//Ex 11.5.1 - Exception Handling
	//Open ended exercise - create a situation to use try/catch and throw an exception.
	//The point is to go through the process of defining an exception, a try/catch and throw definition.
	cout << "Enter an integer between 5 and 10: " << endl;
	int i = 0;
	try {
		cin >> i;
		if (i < 5 || i > 10)
			throw InputException("Invalid input!");
	}
	catch (InputException& ex) {
		cout << "Exception caught!" << endl;
		ex.errorMsg();
	}

	cout << "Entered integer: " << i << endl;

	return 0;
}