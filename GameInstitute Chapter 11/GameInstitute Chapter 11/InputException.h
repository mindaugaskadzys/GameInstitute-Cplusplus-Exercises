#pragma once
#include <string>

class InputException
{
public:
	InputException(const std::string& msg);

	void errorMsg();

private:
	std::string mErrorMsg;

};

