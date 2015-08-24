#include "InputException.h"
#include <iostream>

InputException::InputException(const std::string& msg)
{
	mErrorMsg = msg;
}

void InputException::errorMsg()
{
	std::cout << mErrorMsg << std::endl;
}
