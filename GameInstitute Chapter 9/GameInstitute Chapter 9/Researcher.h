#pragma once
#include "Employee.h"
class Researcher :
	public Employee
{
public:
	Researcher();
	Researcher(std::string fName, std::string lName, int salary, std::string school, std::string thesisTopic);
	virtual ~Researcher();

	//virtual void save(std::ofstream& outFile);
	//virtual void print();

protected:
	virtual void output(std::ostream& outStream);

	std::string mSchool;
	std::string mThesisTopic;
};

