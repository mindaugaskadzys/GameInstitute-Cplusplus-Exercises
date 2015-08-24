#include "Manager.h"
#include <iostream>

Manager::Manager() : Employee(), mNumMeetings(0), mNumVacationDays(0) { }

Manager::Manager(std::string fName, std::string lName, int salary, int meetings, int vacationDays) :
	Employee(fName, lName, salary), mNumMeetings(meetings), mNumVacationDays(vacationDays) {}


Manager::~Manager()
{
}

void Manager::output(std::ostream& outStream)
{
	Employee::output(outStream);
	outStream << "MeetingsPerWeek= " << mNumMeetings << std::endl;
	outStream << "VacationDaysPerYear= " << mNumVacationDays << std::endl;
	outStream << std::endl;
}

/*void Manager::save(std::ofstream& outFile)
{
	output(outFile);
}

void Manager::print()
{
	output(std::cout);
}*/
