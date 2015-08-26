#pragma once
#include "LinkedList.h"

template<class T>
class Queue
{
public:
	Queue();
	~Queue();
	T& getFirst();
	bool isEmpty();
	void push(T newElement);
	void pop();

	template<typename U>
	friend std::ostream& operator<<(std::ostream& os, const Queue<U>& queue);
private:
	LinkedList<T> mList;
};

template<typename U>
std::ostream& operator<<(std::ostream& os, const Queue<U>& queue)
{
	os << queue.mList;

	return os;
}

template<typename T>
Queue<T>::Queue() {}

template<typename T>
Queue<T>::~Queue() {}

template<typename T>
T& Queue<T>::getFirst() {
	return mList.getFirst();
}

template<typename T>
bool Queue<T>::isEmpty() {
	return mList.isEmpty();
}

template<typename T>
void Queue<T>::push(T newElement) {
	mList.insertLast(newElement);
}

template<typename T>
void Queue<T>::pop() {
	if (!isEmpty())
		mList.removeFirst();
}