#include <iostream>
#include <string>
#include <cmath>
#include <ctime>
#include <vector>
using namespace std;

template <int rows, int cols>
void printMatrix(int(&matrix)[rows][cols]);

int Factorial(int n);

char ToUpperCase(char input);
char ToLowerCase(char input);

float dist3(float ux, float uy, float uz, float vx, float vy, float vz);

float MyArcTangent(float y, float x);
float rad2deg(float n);
float deg2rad(float n);

float PI = 3.14f;

float inputNumber(string name = "x");

int Random(int low, int high);

int BinSearch(int data[], int numElements, int searchKey);

void BubbleSort(int data[], int n);

//Got fed up rewriting array print
void printArray(int data[], int n);

void Dice(int& die1, int& die2);
void Dice(int* die1, int* die2);

void RandomArrayFill(int* array, int size);
void RandomArrayFill(vector<int>& v);

bool QuadraticFormula(float a, float b, float c,
	float& r1, float& i1, float& r2, float& i2);


int main()
{
	//Chapter 1 - Environment & Core Language Features

	//Ex 1.6.1 Arithmetic Operators
	/*float n1, n2, sum, diff, prod, quot;

	cout << "Enter a real number n1: ";
	cin >> n1;
	cout << "Enter a real number n2: ";
	cin >> n2;
	sum = n1 + n2;
	diff = n1 - n2;
	prod = n1 * n2;
	quot = n1 / n2;
	cout << n1 << " + " << n2 << " = " << sum << endl;
	cout << n1 << " - " << n2 << " = " << diff << endl;
	cout << n1 << " * " << n2 << " = " << prod << endl;
	cout << n1 << " / " << n2 << " = " << quot << endl;	*/

	//Ex 1.6.2 Cin/Cout
	/*string fname = "";
	string lname = "";
	cout << "Enter your first and last name: ";
	cin >> fname >> lname;
	cout << "Hello, " << fname << " " << lname << endl; */

	//Ex 1.6.3 Cube
	/*float n, pow3;
	cout << "Enter a real number: ";
	cin >> n;
	pow3 = n*n*n;
	cout << n << "^3 = " << pow3 << endl;*/

	//Ex 1.6.4 Area/Circumference
	/*float r, A, C;
	cout << "Enter the radius of a circle: ";
	cin >> r;
	A = 3.14f * r * r;
	C = 2 * 3.14f * r;
	cout << "The area A of the circle with radius " << r << " = " << A << endl;
	cout << "The circumference C of the circle with radius " << r << " = " << C << endl;*/

	//Ex 1.6.5 Average
	/*float a0,a1,a2,a3,a4,avg;
	cout << "Enter a0: ";
	cin >> a0;
	cout << "Enter a1: ";
	cin >> a1;
	cout << "Enter a2: ";
	cin >> a2;
	cout << "Enter a3: ";
	cin >> a3;
	cout << "Enter a4: ";
	cin >> a4;
	avg = (a0 + a1 + a2 + a3 + a4) / 5;
	cout << "The average of the five inputs a0...a4 = " << avg << endl;*/

	//Ex 1.6.6 Bug fixing
	/*string str = "Hello World!";
	float x = 5.0f;
	cout << str << endl;
	cout << x << str << endl;
	int num65 = 65;
	cout << "65Num = " << num65 << endl;*/

	//Chapter 2 - Conditionals, Loops and Arrays

	//Ex 2.7.2 Navigator
	/*int x = 0, y = 0;
	char input;
	bool cont = true;
	while (cont) {
	cout << "Current Position = (" << x << ", " << y << ")" << endl << "Move (N)orth, (E)ast, (S)outh, (W)est, (Q)uit ?";
	cin >> input;
	switch (input)
	{
	case 'N': case 'n': y++; break;
	case 'E': case 'e': x++; break;
	case 'S': case 's': y--; break;
	case 'W': case 'w': x--; break;
	case 'Q': case 'q': cont = false; break;
	default: cout << "Unknown command!" << endl;
	}
	}
	cout << "Bye!" << endl;*/

	//Ex 2.7.3 Average
	/*int noNumbers = 0;
	cout << "Enter the number of values to average: ";
	cin >> noNumbers;
	int sum = 0, currNo = 0;
	for (int i = 0; i < noNumbers; i++) {
	cout << "[" << i << "] = ";
	cin >> currNo;
	sum += currNo;
	}
	sum /= noNumbers;
	cout << "Average = " << sum << endl;*/

	//Ex 2.7.4 Factorials
	/*int number = 1;
	cout << "Enter a positive integer to compute the factorial of: ";
	cin >> number;
	cout << number << "! = ";
	int result = 1;
	for ( ; number > 0; number--) {
	result *= number;
	}
	cout << result << endl;*/

	//Ex 2.7.5 Matrix Addition
	/*int A[2][3] = { { -5, 2, 8 },
	{1, 0, 0 }
	};
	int B[2][3] = { { 1, 0, 2 },
	{ 0, 3, -6 } };

	int AB[2][3];
	for (int i = 0; i < 2; i++) {
	for (int j = 0; j < 3; j++) {
	AB[i][j] = A[i][j] + B[i][j];
	}
	}

	printMatrix(A);
	printMatrix(B);
	printMatrix(AB);*/

	//Ex 2.7.6 ASCII Characters
	/*for (int i = 33; i < 256; i++) {
	cout << i << ": " << (char)i << " ";
	}
	cout << endl;*/

	//Ex 2.7.7 Linear Search
	/*int numbers[] = { 7, 3, 32, 2, 55, 34, 6, 13, 29, 22, 11, 9, 1, 5, 42, 39, 8 };
	cout << "List = ";
	int i;
	for (i = 0; i < 17; i++) {
	cout << numbers[i] << ", ";
	}
	cout << endl << endl << "Enter an integer from the list to search for: ";
	int searchKey = -1;
	cin >> searchKey;
	for (i = 0; i < 17; i++) {
	if (searchKey == numbers[i])
	break;
	}
	cout << "Item found at index [" << i << "]" << endl;*/

	//Ex 2.7.8 Selection Sort
	/*int numbers[10];
	cout << "Enter ten unsorted integers..." << endl;
	int i;
	for (i = 0; i < 10; i++) {
	cout << "[" << i << "] = ";
	cin >> numbers[i];
	}
	cout << endl << "Unsorted List = ";
	for (i = 0; i < 10; i++) {
	cout << numbers[i] << ", ";
	}
	cout << endl << "Sorting..." << endl << "Sorted List = ";
	int min, p;
	for (i = 0; i < 9; i++) {
	min = numbers[i];
	p = i;
	for (int j = i+1; j < 10; j++) {
	if (numbers[j] < min) {
	p = j;
	min = numbers[j];
	}
	}
	numbers[p] = numbers[i];
	numbers[i] = min;
	}

	for (i = 0; i < 10; i++) {
	cout << numbers[i] << ", ";
	}
	cout << endl;*/

	//Chapter 3 - Functions

	//Ex 3.7.1 Factorial
	/*int number = 1;
	while (true) {
	cout << "Enter a positive integer to compute the factorial of: ";
	cin >> number;
	if (number < 1) {
	cout << "Exiting..." << endl;
	break;
	}
	cout << number << "! = ";
	cout << Factorial(number) << endl;
	}*/

	//Ex 3.7.2  ToUpper;ToLower
	/*for (int i = 65; i < 91; i++) {
	cout << ToLowerCase((char)i) << ", ";
	}
	cout << endl;
	for (int i = 97; i < 123; i++) {
	cout << ToUpperCase((char)i) << ", ";
	}
	cout << endl;*/

	//Ex 3.7.3 3D Distance
	/*cout << "Distance between (1, 2, 3) and (0, 0, 0) = " << dist3(1, 2, 3, 0, 0, 0) << endl;
	cout << "Distance between (1, 2, 3) and (1, 2, 3) = " << dist3(1, 2, 3, 1, 2, 3) << endl;
	cout << "Distance between (1, 2, 3) and (7, -4, 5) = " << dist3(1, 2, 3, 7, -4, 5) << endl;*/

	//Ex 3.7.4 Arc Tangent 2
	/*cout << "MyArcTangent( 4, 2) = " << MyArcTangent(4.0f, 2.0f) << endl;
	cout << "MyArcTangent( 5, -1) = " << MyArcTangent(5.0f, -1.0f) << endl;
	cout << "MyArcTangent( -4, -6) = " << MyArcTangent(-4.0f, -6.0f) << endl;
	cout << "MyArcTangent( -6, 4) = " << MyArcTangent(-6.0f, 4.0f) << endl;*/

	//Ex 3.7.5 Calculator
	/*bool loop = true;
	while (loop) {
	cout << "1) cos(x), 2) sin(x), 3) tan(x), 4) atan2(y, x), 5) sqrt(x), 6) x^y, 7) ln(x), 8) e^x, 9) | x | , 10) floor(x), 11) ceil(x), 12) Exit.";
	int choice = 12;
	cin >> choice;
	float x, y;
	switch (choice) {
	case 1:
	cout << "cos(x) = " << cos(inputNumber()) << endl;
	break;
	case 2:
	cout << "sin(x) = " << sin(inputNumber()) << endl;
	break;
	case 3:
	cout << "tan(x) = " << tan(inputNumber()) << endl;
	break;
	case 4:
	cout << "atan2(y, x) = " << atan2f(inputNumber("y"), inputNumber()) << endl;
	break;
	case 5:
	cout << "sqrt(x) = " << sqrt(inputNumber()) << endl;
	break;
	case 6:
	float x = inputNumber();
	cout << "x^y = " << pow(x, inputNumber("y")) << endl;
	break;
	case 7:
	cout << "ln(x) = " << log2(inputNumber()) << endl;
	break;
	case 8:
	cout << "e^x = " << pow(2.71828f, inputNumber()) << endl;
	break;
	case 9:
	cout << "| x | = " << abs(inputNumber()) << endl;
	break;
	case 10:
	cout << "floor(x) = " << floorf(inputNumber()) << endl;
	break;
	case 11:
	cout << "ceil(x) = " << ceilf(inputNumber()) << endl;
	break;
	case 12:
	loop = false;
	break;
	default:
	cout << "Unknown command. Try again." << endl;
	}
	}*/

	//Ex 3.7.6 Slot Machine
	/*int balance = 1000;
	int input = 0, bet = 0;
	int numbers[3];
	while (input != 2) {
	cout << "Player chips: $" << balance << endl << "1) Play slot. 2) Exit.";
	cin >> input;
	switch (input) {
	case 1:
	bet = -1;
	while (true) {
	cout << "Enter your bet: ";
	cin >> bet;
	if (bet < 1 || bet > balance)
	cout << "You did not enter a valid bet.";
	else
	break;
	}
	numbers[0] = Random(2, 7);
	numbers[1] = Random(2, 7);
	numbers[2] = Random(2, 7);
	cout << "| " << numbers[0] << " | " << numbers[1] << " | " << numbers[2] << " |" << endl;
	if (numbers[0] == 7 && numbers[1] == 7 && numbers[2] == 7) {
	balance += bet * 10;
	cout << "You win!" << endl;
	}
	else if (numbers[0] == numbers[1] && numbers[1] == numbers[2]) {
	balance += bet * 5;
	cout << "You win!" << endl;
	}
	else if (numbers[0] == numbers[1] || numbers[0] == numbers[2] || numbers[1] == numbers[2]) {
	balance += bet * 3;
	cout << "You win!" << endl;
	}
	else {
	cout << "You lose!" << endl;
	balance -= bet;
	}
	case 2:
	break;
	default:
	cout << "Unknown command. Try again." << endl;
	}

	if (balance <= 0) break;
	}
	cout << "Game Over. Exiting..." << endl;*/

	//Ex 3.7.7 Binary Search
	/*int numbers[] = { 1, 4, 5, 6, 9, 14, 21, 23, 28, 31, 35, 42, 46, 50, 53, 57, 62, 63, 65, 74, 79, 89, 95 };
	cout << "{";
	for (int i = 0; i < 23; i++) {
	cout << numbers[i];
	if (i == 22)
	cout << "}" << endl;
	else
	cout << ", ";
	}
	int input = -1;
	while (true)
	{
	//Having x as the exit key is nonsensical, since it could either be 'x' or the number you're searching for, so use -1 instead
	cout << "Enter search key (or -1 to exit):";
	cin >> input;
	if (input == -1)
	break;
	else
	cout << input << " is in position " << BinSearch(numbers, 23, input) << endl;
	}
	cout << "Exiting" << endl;*/

	//Ex 3.7.8 Bubble Sort
	/*int numbers[10];
	int i;
	cout << "Enter ten unsorted integers..." << endl;
	for (i = 0; i < 10; i++) {
	cout << "[" << i << "] = ";
	cin >> numbers[i];
	}
	cout << endl;
	cout << "Unsorted List = "; printArray(numbers, 10); cout << endl;
	cout << "Sorting..." << endl;
	cout << "Sorted List = "; BubbleSort(numbers, 10);  printArray(numbers, 10); cout << endl;*/

	//Chapter 4 - References and Pointers

	//Ex 4.9.2 Dice Function
	/*Make a dice game about betting for dice. For simplicity, the rules are:
	//Rolling a 7 triples your bet
	//Rolling a double doubles your bet
	//Rolling 6,8 wins half of your bet
	//Rolling 2,3,4,5,9,10,11,12 loses nothing*/
	/*srand(time(0));
	int balance = 1000;
	int input = 0, bet = 0;
	int die1,die2, sum;
	while (input != 2) {
	cout << "Player chips: $" << balance << endl << "1) Play dice. 2) Exit.";
	cin >> input;
	switch (input) {
	case 1:
	bet = -1;
	while (true) {
	cout << "Enter your bet: ";
	cin >> bet;
	if (bet < 1 || bet > balance)
	cout << "You did not enter a valid bet.";
	else
	break;
	}
	Dice(&die1, &die2);
	cout << "You rolled: " << die1 << " and " << die2 << endl;
	sum = die1 + die2;
	if (sum == 7) {
	balance += bet * 2;
	cout << "You win!" << endl;
	}
	else if (die1 == die2 && sum != 2) {
	balance += bet;
	cout << "You win!" << endl;
	}
	else if (sum == 6 || sum == 8) {
	balance += bet*0.5;
	cout << "You win!" << endl;
	}
	else {
	cout << "You lose!" << endl;
	balance -= bet;
	}
	case 2:
	break;
	default:
	cout << "Unknown command. Try again." << endl;
	}

	if (balance <= 0) break;
	}
	cout << "Game Over. Exiting..." << endl;*/

	//Ex 4.9.2 Array Fill
	/*cout << "Enter the size of the array to create: ";
	int aSize = 0;
	cin >> aSize;
	cout << "Creating array and filling it with random numbers..." << endl;
	//int* myArray = new int[aSize];
	//RandomArrayFill(myArray, aSize);
	vector<int> myArray;
	myArray.resize(aSize);
	RandomArrayFill(myArray);
	//cout << "Array = "; printArray(myArray, aSize); cout << endl;
	//delete[] myArray;
	cout << "Array = {";
	for (int i = 0; i < myArray.size(); i++) {
	cout << myArray[i] << " ";
	}
	cout << "}" << endl;*/

	//Ex 4.9.3 Quadratic Equation
	//Find the roots of a quadratic equation, including imaginary parts
	/*float r1, r2, i1, i2;
	QuadraticFormula(1, -1, -6, r1, i1, r2, i2);
	cout << "Coefficients a= 1, b = -1, c = -6 yield S1 = " << r1 << " + " << i1 << "i, and S2 = " << r2 << " - " << abs(i2) << "i" << endl;
	QuadraticFormula(1, -2, 1, r1, i1, r2, i2);
	cout << "Coefficients a= 1, b = -2, c = -1 yield S1 = " << r1 << " + " << i1 << "i, and S2 = " << r2 << " - " << abs(i2) << "i" << endl;
	QuadraticFormula(1, 2, 5, r1, i1, r2, i2);
	cout << "Coefficients a= 1, b = 2, c = 5 yield S1 = " << r1 << " + " << i1 << "i, and S2 = " << r2 << " - " << abs(i2) << "i" << endl;*/

}

template <int rows, int cols>
void printMatrix(int(&matrix)[rows][cols]) {
	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < cols; ++j) {
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

int Factorial(int n)
{
	int result = 1;
	for (; n > 0; n--) {
		result *= n;
	}
	return result;
}

char ToUpperCase(char input) {
	if (input >= 65 && input <= 90)
		return input;
	else if (input >= 97 && input <= 122) {
		int diff = input - 97; //get letter number
		return 65 + diff;
	}
	else
		return '/0';
}

char ToLowerCase(char input) {
	if (input >= 65 && input <= 90) {
		int diff = input - 65; //get letter number
		return 97 + diff;
	}
	else if (input >= 97 && input <= 122) {
		return input;
	}
	else
		return '/0';
}

float dist3(float ux, float uy, float uz, float vx, float vy, float vz) {
	return sqrtf(powf(vx - ux, 2) + powf(vy - uy, 2) + powf(vz - uz, 2));
}

float MyArcTangent(float y, float x) {
	if (x > 0) {
		return rad2deg(atanf(y / x));
	}
	else {
		return rad2deg(atanf(y / x)) + 180.0f;
	}
}

float rad2deg(float n) { return n * 180.0f / PI; }
float deg2rad(float n) { return n * PI / 180.0f; }

float inputNumber(string name) {
	float no;
	cout << "Enter " << name << ": ";
	cin >> no;
	return no;
}

int Random(int low, int high) {
	return low + rand() % (high + 1 - low);
}

int BinSearch(int data[], int numElements, int searchKey) {
	int low = 0, high = numElements - 1;
	int mid;
	while (true) {
		mid = low + (high - low) / 2;
		if (searchKey > data[mid]) {
			low = mid + 1;
		}
		else if (searchKey < data[mid]) {
			high = mid - 1;
		}
		else {
			break;
		}
	}

	return mid;
}

void BubbleSort(int data[], int n) {
	int subArrayEnd = n - 1;
	int nextEnd;
	while (subArrayEnd > 0) {
		nextEnd = 0;
		for (int j = 0; j < subArrayEnd; j++) {
			if (data[j] > data[j + 1]) {
				int tmp = data[j];
				data[j] = data[j + 1];
				data[j + 1] = tmp;

				nextEnd = j;
			}
		}
		subArrayEnd = nextEnd;
	}
}

void printArray(int data[], int n) {
	for (int i = 0; i < n; i++) {
		cout << data[i];
		if (i != n - 1) cout << ",";
	}
}

//dice implementation with references
void Dice(int& die1, int& die2) {
	die1 = 1 + rand() % 6;
	die2 = 1 + rand() % 6;
}

//dice implementation with pointers
void Dice(int* die1, int* die2) {
	*die1 = 1 + rand() % 6;
	*die2 = 1 + rand() % 6;
}

void RandomArrayFill(int* array, int size) {
	for (int i = 0; i < size; i++) {
		array[i] = rand() % 101;
	}
}

void RandomArrayFill(vector<int>& v) {
	for (int i = 0; i < v.size(); i++) {
		v[i] = rand() % 101;
	}
}

//Find roots of quadratic equations, including imaginary parts
bool QuadraticFormula(float a, float b, float c,
	float& r1, float& i1, float& r2, float& i2) {
	float bSquaredminus4ac = powf(b, 2) - 4 * a*c;
	if (bSquaredminus4ac < 0) {
		bSquaredminus4ac *= -1;

		r1 = -b / 2 * a;
		r2 = -b / 2 * a;
		i1 = sqrtf(bSquaredminus4ac) / 2 * a;
		i2 = i1*-1;

		return true;
	}
	else {
		float root = sqrtf(bSquaredminus4ac);
		r1 = (-b + root) / 2 * a;
		r2 = (-b - root) / 2 * a;
		i1 = 0;
		i2 = 0;

		return false;
	}
}
