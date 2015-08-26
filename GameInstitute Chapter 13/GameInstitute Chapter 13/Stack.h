#pragma once
#include "LinkedList.h"

template<typename T>
class Stack
{
public:
	Stack();
	~Stack();
	T& getTopItem();
	bool isEmpty(void);
	void push(T newElement);
	void pop();

	template<typename U>
	friend std::ostream& operator<<(std::ostream& os, const Stack<U>& stack);
private:
	LinkedList<T> mList;
};

template<typename U>
std::ostream& operator<<(std::ostream& os, const Stack<U>& stack)
{
	os << stack.mList;

	return os;
}

template<typename T>
Stack<T>::Stack() {}

template<typename T>
Stack<T>::~Stack() {}

template<typename T>
T& Stack<T>::getTopItem() {
	return mList.getLast();
}

template<typename T>
bool Stack<T>::isEmpty() {
	return mList.isEmpty();
}

template<typename T>
void Stack<T>::push(T newElement) {
	mList.insertLast(newElement);
}

template<typename T>
void Stack<T>::pop() {
	if (!isEmpty())
		mList.removeLast();
}