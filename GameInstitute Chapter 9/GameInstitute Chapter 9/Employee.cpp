#include "Employee.h"
#include <iostream>

Employee::Employee()
{
	mFirstName = "default";
	mLastName = "default";
	mSalary = 0;
}

Employee::Employee(std::string fName, std::string lName, int salary)
{
	mFirstName = fName;
	mLastName = lName;
	mSalary = salary;
}

Employee::~Employee()
{
}

void Employee::output(std::ostream& outStream)
{
	outStream << "FirstName= " << mFirstName << std::endl;
	outStream << "LastName= " << mLastName << std::endl;
	outStream << "Salary= " << mSalary << std::endl;
}

void Employee::save(std::ofstream& outFile)
{
	output(outFile);
}

void Employee::print()
{
	output(std::cout);
}