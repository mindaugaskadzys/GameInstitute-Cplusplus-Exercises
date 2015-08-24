#include "Fraction.h"
#include "FloatArray.h"

using namespace std;

void PrintFloatArray(FloatArray& fa)
{
	cout << "{ ";
	for (int i = 0; i < fa.size(); ++i)
		cout << fa[i] << " ";
	cout << "}" << endl << endl;
}

void main()
{
	//Ex 7.9.1 - Fraction class
	/*Fraction f1;
	Fraction f2(1, 3);
	cout << "Fraction1: " << f1;
	cout << "Fraction2: " << f2;

	Fraction f3;
	cin >> f3;

	Fraction f4;
	f4 = f2 + f3;
	cout << "f2 + f3: " << f4;
	f4 = f2 - f3;
	cout << "f2 - f3: " << f4;
	f4 = f2 * f3;
	cout << "f2 * f3: " << f4;
	f4 = f2 / f3;
	cout << "f2 / f3: " << f4;

	cout << "f2 == f3: " << (f2 == f3) << endl;
	cout << "f2 != f3: " << (f2 != f3) << endl;
	cout << "f2 > f3: " << (f2 > f3) << endl;
	cout << "f2 >= f3: " << (f2 >= f3) << endl;
	cout << "f2 < f3: " << (f2 < f3) << endl;
	cout << "f2 <= f3: " << (f2 <= f3) << endl;

	float f2f = (float)f2;
	double f2d = (double)f2;
	cout << "f2 float = " << f2f << ". f2 double = " << f2d << endl;*/

	//Ex 7.9.2 - FloatArray class
	FloatArray A;

	A.resize(4);
	A[0] = 1.0f;
	A[1] = 2.0f;
	A[2] = 3.0f;
	A[3] = 4.0f;

	cout << "Printing A: ";
	PrintFloatArray(A);

	FloatArray B(A);

	cout << "Printing B: ";
	PrintFloatArray(B);

	FloatArray C = B = A;

	cout << "Printing C: ";
	PrintFloatArray(C);

	A = A = A = A;

	cout << "Printing A: ";
	PrintFloatArray(A);
}