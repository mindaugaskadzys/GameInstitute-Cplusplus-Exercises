#include <iostream>
#include <string>
#include <vector>
#include "Employee.h"
#include "Manager.h"
#include "Engineer.h"
#include "Researcher.h"

using namespace std;

void addGeneric(string& fName, string& lName, int& salary);
Employee* addManager();
Employee* addEngineer();
Employee* addResearcher();

int main()
{
	//Ex 9.11 - Employee Database
	vector<Employee*> employees;
	bool quit = false;
	while (!quit)
	{
		// Output size.
		cout << "Number of Employees = " << employees.size() << endl;
		// Output vector contents.
		cout << "Database contains: " << endl;
		for (int i = 0; i < employees.size(); ++i)
			employees[i]->print();
		cout << endl << endl;
		// Display option menu.
		cout << "1) Add Employee, 2) Remove Employee, 3) Save Database, 4) Exit. ";
		// Get menu input.
		int input = 1;
		cin >> input;
		// Do operation based on item chosen.
		switch (input)
		{
		case 1:
		{
			// Add an inputted integer to the vector.
			cout << "1) Add a Manager, 2) Add an Engineer, 3) Add a Researcher, 4) Cancel: ";
			input = 4;
			cin >> input;
			Employee* empl = 0;

			switch (input)
			{
			case 1:
				empl = addManager();
				break;
			case 2:
				empl = addEngineer();
				break;
			case 3:
				empl = addResearcher();
				break;
			case 4: default:
				cout << "Cancelling..." << endl;
				break;
			} //End Add Employee menu
			if (empl != 0)
				employees.push_back(empl);
			break;
		}
		case 2:
		{
			// Remove employee with specified last name.
			cout << "Enter the last name of the employee to remove: ";
			string empLastName = "";
			cin >> empLastName;

			//get the index of the employee specified
			int i;
			for (i = 0; i < employees.size(); i++)
				if (!empLastName.compare(employees[i]->getLastName()))
					break;

			//check if we found the employee specified
			if (i < employees.size())
				employees.erase(employees.begin() + i);
			else
				cout << "Employee with specified last name not found." << endl;
			break;
		}
		case 3:
		{
			//Save
			//Use pointers for polymorphism
			ofstream* outFile = new ofstream("employees.txt");

			for (int i = 0; i < employees.size(); i++) {
				employees[i]->save(*outFile);
			}
			break;
		}
		case 4:
			// Exit.
			quit = true;
			break;
		}
	}

	for (int i = 0; i < employees.size(); i++) {
		delete employees[i];
		employees[i] = 0;
	}
}

void addGeneric(string& fName, string& lName, int& salary)
{
	cout << "First name: ";
	cin >> fName;
	cout << "Last name: ";
	cin >> lName;
	cout << "Salary: ";
	cin >> salary;
}

Employee* addManager()
{
	string fName, lName;
	int salary, numMeetings, numVacations;
	addGeneric(fName, lName, salary);
	cout << "Enter number of meetings per week: ";
	cin >> numMeetings;
	cout << "Enter number of vacation days per year: ";
	cin >> numVacations;
	return new Manager(fName, lName, salary, numMeetings, numVacations);
}

Employee* addEngineer()
{
	string fName, lName, engineerType;
	int salary, yearsExp;
	bool knowsCPP;
	addGeneric(fName, lName, salary);
	cout << "Knows C++? 1) Yes, 0) No:";
	cin >> knowsCPP;
	cout << "Years of experience: ";
	cin >> yearsExp;
	cout << "Engineer type: ";
	cin >> engineerType;
	return new Engineer(fName, lName, salary, knowsCPP, yearsExp, engineerType);

}

Employee* addResearcher()
{
	string fName, lName, school, thesisTopic;
	int salary;
	addGeneric(fName, lName, salary);
	cout << "Enter school where phD was achieved: ";
	cin >> school;
	cout << "Enter thesis topic: ";
	cin >> thesisTopic;
	return new Researcher(fName, lName, salary, school, thesisTopic);
}