#pragma once
#include <string>
#include <fstream>

class Employee
{
public:
	Employee();
	Employee(std::string fName, std::string lName, int salary);

	virtual ~Employee();

	void save(std::ofstream& outFile);
	void print();

	inline std::string getLastName() { return mLastName; }

protected:
	virtual void output(std::ostream& outStream);

	std::string mFirstName;
	std::string mLastName;
	int mSalary;
};

