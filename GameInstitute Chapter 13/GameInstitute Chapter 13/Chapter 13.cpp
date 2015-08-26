#include "LinkedList.h"
#include "Stack.h"
#include "Queue.h"
#include <iostream>
#include <string>
#include <functional>
#include "My_Algorithms.h"
#include "My_Functors.h"

using namespace std;

int main()
{
	//Ex 13.9.1 - Implement your own LinkedList
	/*LinkedList<int> intList;
	cout << "intList.isEmpty(): " << intList.isEmpty() << endl;
	intList.insertFirst(3);
	intList.insertFirst(2);
	intList.insertLast(4);
	cout << endl;
	cout << "Inserting 3 to front, 2 to front, then 4 to back... " << endl;
	//check if isEmpty worked
	cout << "intList.isEmpty(): " << intList.isEmpty() << endl;
	cout << "intList = " << intList;
	LinkedList<int> intList2 = intList;
	//check if assignment worked and insertion worked
	cout << endl;
	cout << "assigning intList to intList2..." << endl;
	cout << "intList2.isEmpty(): " << intList2.isEmpty() << endl;
	cout << "intList2 = " << intList2;
	//verify getFirst and getLast
	cout << endl;
	cout << "verifying getFirst and getLast..." << endl;
	cout << "intList2.getFirst(): " << intList2.getFirst() << endl;
	cout << "intList2.getLast(): " << intList2.getLast() << endl;
	intList2.removeLast();
	intList2.removeFirst();
	cout << endl;
	cout << "removing last and first from intList2..." << endl;
	//check if removal works and only happened in intList2
	cout << "intList2 = " << intList2;
	cout << "intList = " << intList;
	intList2.insertAfter(3,5);
	intList2.insertAfter(3, 4);
	//verify insertAfter
	cout << endl;
	cout << "inserting 5 and then 4 after the value 3 in intList2..." << endl;
	cout << "intList2 = " << intList2;
	intList2.remove(4);
	//verify remove item
	cout << endl;
	cout << "removing 4 from intList 2..." << endl;
	cout << "intList2 = " << intList2;
	intList.destroy();
	//verify destroy
	cout << endl;
	cout << "destroying intList..." << endl;
	cout << "intList.isEmpty(): " << intList.isEmpty() << endl;
	cout << "intList2.isEmpty(): " << intList2.isEmpty() << endl;*/

	//Ex 13.9.2 - Implement your own Stack class
	/*Stack<std::string> stringStack;
	int choice = 1;
	while (choice != 5) {
		cout << endl;
		cout << stringStack;
		cout << "1) Push 2) Pop 3) Peek 4) Empty? 5) Exit: ";
		cin >> choice;
		std::string item = "";
		switch (choice) {
		case 1:
			cout << "Enter a string:";
			cin >> item;
			stringStack.push(item);
			break;
		case 2:
			item = stringStack.getTopItem();
			cout << "Popped: " << item << endl;
			stringStack.pop();
			break;
		case 3:
			item = stringStack.getTopItem();
			cout << "Item on top is: " << item << endl;
			break;
		case 4:
			cout << "The Stack " << (stringStack.isEmpty() ? "is empty." : "is not empty.") << endl;
			break;
		}
	}*/

	//Ex 13.9.3 - Implement your own Queue class
	/*Queue<float> floatQueue;
	int choice = 1;
	while (choice != 5) {
		cout << endl;
		cout << floatQueue;
		cout << "1) Push 2) Pop 3) Peek 4) Empty? 5) Exit: ";
		cin >> choice;
		float item = 0;
		switch (choice) {
		case 1:
			cout << "Enter a float:";
			cin >> item;
			floatQueue.push(item);
			break;
		case 2:
			item = floatQueue.getFirst();
			cout << "Popped: " << item << endl;
			floatQueue.pop();
			break;
		case 3:
			item = floatQueue.getFirst();
			cout << "Item at the front is: " << item << endl;
			break;
		case 4:
			cout << "The Queue " << (floatQueue.isEmpty() ? "is empty." : "is not empty.") << endl;
			break;
		}
	}*/

	//Ex 13.9.4 - Implement your own for_each, count, reverse, sort algorithms for an array
	int intArray[5];
	Random r(2,7);
	Print<int> p;
	my_generate(std::begin(intArray), std::end(intArray), r);
	my_for_each(std::begin(intArray), std::end(intArray), p);
	cout << endl;

	int result = my_count(std::begin(intArray), std::end(intArray), 7);
	cout << "7 occurs " << result << " times." << endl;

	my_reverse(std::begin(intArray), std::end(intArray));
	my_for_each(std::begin(intArray), std::end(intArray), p);
	cout << endl;

	//need inclusive array for quicksort
	my_sort(std::begin(intArray), std::end(intArray)-1, less_equal<int>());
	my_for_each(std::begin(intArray), std::end(intArray), p);
	cout << endl;

}