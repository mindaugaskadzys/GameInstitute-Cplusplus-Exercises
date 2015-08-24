#include "Engineer.h"
#include <iostream>

Engineer::Engineer() :
Employee(), mKnowsCPP(false), mYearsExperience(0), mEngineerType("default") { }

Engineer::Engineer(std::string fName, std::string lName, int salary, bool knowsCPP, int yearsExperience, std::string engineerType) :
Employee(fName, lName, salary), mKnowsCPP(knowsCPP), mYearsExperience(yearsExperience), mEngineerType(engineerType) { }

Engineer::~Engineer()
{
}

void Engineer::output(std::ostream& outStream)
{
	Employee::output(outStream);
	outStream << "KnowsC++= " << mKnowsCPP << std::endl;
	outStream << "YearsExperience= " << mYearsExperience << std::endl;
	outStream << "EngineerType= " << mEngineerType << std::endl;
	outStream << std::endl;
}

/*void Engineer::save(std::ofstream& outFile)
{
	output(outFile);
}

void Engineer::print()
{
	output(std::cout);
}*/