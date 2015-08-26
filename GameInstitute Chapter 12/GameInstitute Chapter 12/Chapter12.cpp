#include <iostream>
#include <string>

using namespace std;

template<typename T>
char* ToBinaryString(T number) {
	int powerCounter = 0;

	//find the highest '1' bit in the number
	int tempResult = 0;
	while (tempResult <= number) {
		powerCounter++;
		tempResult = pow(2, powerCounter);
		//cout << "powerCounter = " << powerCounter << ", tempResult = " << tempResult << ", number = " << number << endl;
	}
	char* binString = new char[powerCounter];
	tempResult = number;
	int power = 0;
	int position = 0;
	for (int i = powerCounter - 1; i >= 0; --i, position++)
	{
		//construct the bitstring
		power = pow(2, i);
		if (power <= tempResult) {
			tempResult -= power;
			binString[position] = '1';
		}
		else
			binString[position] = '0';
	}
	binString[position] = '\0';

	return binString;
}

int main()
{
	//Ex 12.8.5 Binary to Decimal
	/*cout << "Enter a binary string: ";
	string binString;
	cin >> binString;
	int result = 0;
	int powerCounter = 0;
	for (int i = binString.length()-1; i >= 0; --i, powerCounter++)
	{
		result += binString[i] == '0' ? 0 : pow(2, powerCounter);
	}
	cout << binString << " = " << result << " in decimal." << endl;*/

	//Ex 12.8.6 Decimal to Binary
	/*cout << "Enter a decimal number: ";
	short number = 0;
	cin >> number;
	char* binString = ToBinaryString(number);
	cout << number << " = " << binString << " in binary." << endl;*/

	//Ex 12.8.7 - Bit Operation Calculator
	cout << "Enter a decimal number in the range [0, 65,535]: ";
	unsigned short A,B;
	cin >> A;
	cout << "Enter a decimal number in the range [0, 65,535]: ";
	cin >> B;

	cout << "A = " << A << " in binary is " << ToBinaryString(A) << endl;
	cout << "B = " << B << " in binary is " << ToBinaryString(B) << endl << endl;

	unsigned short C = A & B;
	cout << "A & B = " << ToBinaryString(C) << endl;
	C = A | B;
	cout << "A | B = " << ToBinaryString(C) << endl;
	C = ~A;
	cout << "~A = " << ToBinaryString(C) << endl;
	C = ~B;
	cout << "~B = " << ToBinaryString(C) << endl;
	C = A ^ B;
	cout << "A ^ B = " << ToBinaryString(C) << endl;
	C = A << 2;
	cout << "A << 2 = " << ToBinaryString(C) << endl;
	C = B >> 3;
	cout << "B >> 3 = " << ToBinaryString(C) << endl;

}