#pragma once
#include "Employee.h"

class Engineer : public Employee
{
public:
	Engineer();
	Engineer(std::string fName, std::string lName, int salary, bool knowsCPP, int yearsExperience, std::string engineerType);

	virtual ~Engineer();

	//virtual void save(std::ofstream& outFile);
	//virtual void print();

protected:
	virtual void output(std::ostream& outStream);

	bool mKnowsCPP;
	int mYearsExperience;
	std::string mEngineerType;
};

