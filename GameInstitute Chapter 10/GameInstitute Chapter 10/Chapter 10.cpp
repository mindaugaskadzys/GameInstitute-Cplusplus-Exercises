#include "Array.h"
#include <string>
#include <iostream>
#include "Table.h"

using namespace std;

template<typename T>
void PrintArray(const Array<T>& a)
{
	cout << "{ ";
	for (int i = 0; i < a.size(); ++i)
		cout << a[i] << " ";
	cout << "}" << endl << endl;
}

template<typename T>
void BubbleSort(T data[], int n) {
	int subArrayEnd = n - 1;
	int nextEnd;
	while (subArrayEnd > 0) {
		nextEnd = 0;
		for (int j = 0; j < subArrayEnd; j++) {
			if (data[j] > data[j + 1]) {
				T tmp = data[j];
				data[j] = data[j + 1];
				data[j + 1] = tmp;

				nextEnd = j;
			}
		}
		subArrayEnd = nextEnd;
	}
}

template<typename T>
void printArray(const T data[], int n) {
	for (int i = 0; i < n; i++) {
		cout << data[i];
		if (i != n - 1) cout << ",";
	}
}

template <typename T>
void printTable(Table<T>& tab) {
	for (int i = 0; i < tab.numRows(); ++i) {
		for (int j = 0; j < tab.numCols(); ++j) {
			cout << tab(i,j) << " ";
		}
		cout << endl;
	}
	cout << endl;
}

int main()
{
	//Ex 10.5.1 - Template Array class
	/*Array<string> A;

	A.resize(4);
	A[0] = "Hello";
	A[1] = "Beautiful";
	A[2] = "Lovely";
	A[3] = "World!";

	cout << "Printing A: ";
	PrintArray(A);

	Array<string> B(A);

	cout << "Printing B: ";
	PrintArray(B);

	Array<string> C = B = A;

	cout << "Printing C: ";
	PrintArray(C);

	A = A = A = A;

	cout << "Printing A: ";
	PrintArray(A);

	Array<int> D;

	D.resize(4);
	D[0] = 1;
	D[1] = 2;
	D[2] = 3;
	D[3] = 4;

	cout << "Printing D: ";
	PrintArray(D);

	Array<int> E(D);

	cout << "Printing E: ";
	PrintArray(E);

	Array<int> F = E = D;

	cout << "Printing F: ";
	PrintArray(F);

	D = D = D = D;

	cout << "Printing D: ";
	PrintArray(D);*/

	//Ex 10.5.2 - Template Bubble Sort
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
	cout << "Sorted List = "; BubbleSort(numbers, 10);  printArray(numbers, 10); cout << endl;

	string strings[10];
	cout << "Enter ten unsorted strings..." << endl;
	for (i = 0; i < 10; i++) {
		cout << "[" << i << "] = ";
		cin >> strings[i];
	}
	cout << endl;
	cout << "Unsorted List = "; printArray(strings, 10); cout << endl;
	cout << "Sorting..." << endl;
	cout << "Sorted List = "; BubbleSort(strings, 10);  printArray(strings, 10); cout << endl;*/

	//Ex 10.5.3 - Table driver
	Table<int> A(2, 3);
	A(0, 0) = -5; A(0, 1) = 2; A(0, 2) = 8;
	A(1, 0) = 1; A(1, 1) = 0; A(1, 2) = 0;

	Table<int> B(2, 3);
	B(0, 0) = 1; B(0, 1) = 0; B(0, 2) = 2;
	B(1, 0) = 0; B(1, 1) = 3; B(1, 2) = -6;

	Table<int> AB(2,3);
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 3; j++) {
			AB(i,j) = A(i,j) + B(i,j);
		}
	}

	printTable(A);
	printTable(B);
	printTable(AB);


	return 0;
}