#include "Fraction.h"

//Ex 7.9.1 - Fraction class
Fraction::Fraction()
{
	mNumerator = 0;
	mDenominator = 1;
}

Fraction::Fraction(float numerator, float denominator)
{
	mNumerator = numerator;
	mDenominator = denominator;
}

Fraction::~Fraction()
{
}

//Arithmetic operators
Fraction Fraction::operator +(const Fraction& rhs)
{
	Fraction result;
	result.mDenominator = mDenominator*rhs.mDenominator;
	result.mNumerator = mNumerator*rhs.mDenominator + rhs.mNumerator*mDenominator;

	return result;
}

Fraction Fraction::operator -(const Fraction& rhs)
{
	Fraction result;
	result.mDenominator = mDenominator*rhs.mDenominator;
	result.mNumerator = mNumerator*rhs.mDenominator - rhs.mNumerator*mDenominator;

	return result;
}

Fraction Fraction::operator /(const Fraction& rhs)
{
	Fraction result;
	result.mNumerator = mNumerator * rhs.mDenominator;
	result.mDenominator = mDenominator * rhs.mNumerator;

	return result;
}

Fraction Fraction::operator *(const Fraction& rhs)
{
	Fraction result;
	result.mNumerator = mNumerator * rhs.mNumerator;
	result.mDenominator = mDenominator * rhs.mDenominator;

	return result;
}

void Fraction::getCommonDenumerator(const Fraction& frac1, const Fraction& frac2, Fraction& res1, Fraction& res2)
{
	res1.mNumerator = frac1.mNumerator * frac2.mDenominator;
	res1.mDenominator = frac1.mDenominator * frac2.mDenominator;

	res2.mNumerator = frac2.mNumerator * frac1.mDenominator;
	res2.mDenominator = frac2.mDenominator * frac1.mDenominator;
}

//Relational operators
bool Fraction::operator ==(const Fraction& rhs)
{
	Fraction f1, f2;
	getCommonDenumerator(*this, rhs, f1, f2);
	return f1.mNumerator == f2.mNumerator && f1.mDenominator == f2.mDenominator;
}

bool Fraction::operator !=(const Fraction& rhs)
{
	return !(*this == rhs);
}

bool Fraction::operator >(const Fraction& rhs)
{
	return (*this - rhs).mNumerator > 0;
}

bool Fraction::operator >=(const Fraction& rhs)
{
	return (*this == rhs) || (*this > rhs);
}

bool Fraction::operator <(const Fraction& rhs)
{
	return (*this - rhs).mNumerator < 0;
}

bool Fraction::operator <=(const Fraction& rhs)
{
	return (*this == rhs) || (*this < rhs);
}

//Conversion operators
Fraction::operator float()
{
	return mNumerator / mDenominator;
}

Fraction::operator double()
{
	return (double)mNumerator / (double)mDenominator;
}

//Input/Output operators
std::istream& operator>>(std::istream& is, Fraction& f)
{
	std::cout << "Enter a numerator: ";
	std::cin >> f.mNumerator;
	std::cout << "Enter a denominator: ";
	std::cin >> f.mDenominator;

	return is;
}

std::ostream& operator<<(std::ostream& os, Fraction& f)
{
	std::cout << f.mNumerator << "/" << f.mDenominator << std::endl;

	return os;
}