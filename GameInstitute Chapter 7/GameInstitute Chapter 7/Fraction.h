#pragma once
#include <iostream>

//Ex 7.9.1 - Fraction class
class Fraction
{
public:
	Fraction();
	Fraction(float numerator, float denominator);
	~Fraction();

	//Arithmetic operators
	Fraction Fraction::operator +(const Fraction& rhs);
	Fraction Fraction::operator -(const Fraction& rhs);
	Fraction Fraction::operator /(const Fraction& rhs);
	Fraction Fraction::operator *(const Fraction& rhs);

	//Relational operators
	bool Fraction::operator ==(const Fraction& rhs);
	bool Fraction::operator !=(const Fraction& rhs);
	bool Fraction::operator >(const Fraction& rhs);
	bool Fraction::operator >=(const Fraction& rhs);
	bool Fraction::operator <(const Fraction& rhs);
	bool Fraction::operator <=(const Fraction& rhs);

	//Conversion operators
	operator float();
	operator double();

	float mNumerator;
	float mDenominator;

private:
	static void getCommonDenumerator(const Fraction& frac1, const Fraction& frac2, Fraction& res1, Fraction& res2);
};

//Input/Output operators
std::istream& operator>>(std::istream& is, Fraction& f);
std::ostream& operator<<(std::ostream& os, Fraction& f);