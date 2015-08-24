#include "Researcher.h"
#include <iostream>

Researcher::Researcher()
	: Employee(), mSchool("default"), mThesisTopic("default") { }

Researcher::Researcher(std::string fName, std::string lName, int salary, std::string school, std::string thesisTopic)
	: Employee(fName, lName, salary), mSchool(school), mThesisTopic(thesisTopic) { }

Researcher::~Researcher()
{
}

void Researcher::output(std::ostream& outStream)
{
	Employee::output(outStream);
	outStream << "School= " << mSchool << std::endl;
	outStream << "ThesisTopic= " << mThesisTopic << std::endl;
	outStream << std::endl;
}

/*void Researcher::save(std::ofstream& outFile)
{
	output(outFile);
}

void Researcher::print()
{
	output(std::cout);
}*/