#pragma once
#include "Employee.h"

class Manager : public Employee
{
public:
	Manager();
	Manager(std::string fName, std::string lName, int salary, int meetings, int vacationDays);
	virtual ~Manager();

	//virtual void save(std::ofstream& outFile);
	//virtual void print();

protected:
	virtual void output(std::ostream& outStream);

	int mNumMeetings;
	int mNumVacationDays;
};

