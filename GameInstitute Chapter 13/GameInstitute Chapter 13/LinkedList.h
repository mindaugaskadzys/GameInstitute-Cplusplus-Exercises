#pragma once

#include <iostream>

//Ex 13.9.1 - Design and implement your own LinkedList class

template<typename T>
class LinkedList
{
private:
	struct LinkedNode
	{
		LinkedNode(T tData) : data(tData), prev(0), next(0) { };
		T data;
		LinkedNode* next;
		LinkedNode* prev;
	};
	
	LinkedNode* mFirst;
	LinkedNode* mLast;

public:
	LinkedList();
	~LinkedList();
	LinkedList(const LinkedList& rhs);
	LinkedList<T>& operator=(const LinkedList& rhs);
	bool isEmpty();
	T& getFirst();
	T& getLast();
	void insertFirst(T data);
	void insertLast(T data);
	bool insertAfter(T tKey, T tData);
	void removeFirst();
	void removeLast();
	void remove(T removalCandidate);
	void destroy();

	template<typename U>
	friend std::ostream& operator<<(std::ostream& os, const LinkedList<U>& llist);
};

template<typename U>
std::ostream& operator<<(std::ostream& os, const LinkedList<U>& llist)
{
	typename LinkedList<U>::LinkedNode* current = llist.mFirst;
	os << "{ ";
	while (current != 0)
	{
		os << current->data;
		if (current->next != 0)
			os << ", ";
		current = current->next;
	}
	os << " } " << std::endl;

	return os;
}

template<typename T>
LinkedList<T>::LinkedList() : mFirst(0), mLast(0) { }

template<typename T>
LinkedList<T>::~LinkedList()
{
	destroy();
}

template<typename T>
LinkedList<T>::LinkedList(const LinkedList<T>& rhs)
{
	*this = rhs;
}

template<typename T>
LinkedList<T>& LinkedList<T>::operator=(const LinkedList& rhs)
{
	//check assignment to self
	if (this == &rhs)
		return *this;

	//destroy old linked list
	destroy();
	//iterate through rhs and copy all elements
	LinkedNode* current = rhs.mFirst;
	LinkedNode* prev = 0;
	while (current != 0) {
		LinkedNode* copy = new LinkedNode(current->data);
		//link current to previous
		copy->prev = prev;
		//link previous to current
		if (prev != 0) {
			prev->next = copy;
		}
		//if no previous, mark this node as first
		else
			mFirst = copy;
		//check if there's a next node. If not, mark current copy as last
		if (current->next == 0) {
			mLast = copy;
			copy->next = 0;
		}

		//continue on to the next node
		prev = copy;
		current = current->next;
	}
	return *this;
}

template<typename T>
bool LinkedList<T>::isEmpty()
{
	return (mFirst == mLast) && (mFirst == 0);
}

template<typename T>
T& LinkedList<T>::getFirst()
{
	return mFirst->data;
}

template<typename T>
T& LinkedList<T>::getLast()
{
	return mLast->data;
}

template<typename T>
void LinkedList<T>::insertFirst(T tData)
{
	LinkedNode* newNode = new LinkedNode(tData);
	// If the list is empty, this is the first and the last node
	// and doesn't have a previous ptr.
	if (isEmpty()) {
		mLast = newNode;
	}
	// If the list is not empty, the new node becomes the previous
	// node of the current first node.
	else {
		mFirst->prev = newNode;
	}
	// The new node's next ptr is the old first ptr. May be null
	// if this is the first node being added to the list.
	newNode->next = mFirst;
	// The new node becomes the first ptr.
	mFirst = newNode;
}

template<typename T>
void LinkedList<T>::insertLast(T data)
{
	LinkedNode* newNode = new LinkedNode(data);
	//If the list is empty, this is the first and last node
	//and doesn't have a previous ptr.
	if (isEmpty())
		mFirst = newNode;
	//If the list is not empty, the new node becomes the next node of the current last node.
	else
		mLast->next = newNode;
	//the new node's prev ptr is the old last ptr. May be null
	//if this is the first node being added to the list
	newNode->prev = mLast;
	//The new node becomes the last ptr.
	mLast = newNode;
}

template<typename T>
bool LinkedList<T>::insertAfter(T tKey, T tData)
{
	if (isEmpty())
		return false;

	// Get a ptr to the front of the list
	LinkedNode* current = mFirst;

	// Loop until we find tKey (the value of the node to
	// insert after)
	while (current->data != tKey)
	{
		// Hop to the next node
		current = current->next;
		// Test if we reached the end, if we did we didn't
		// find the node to insert after (tKey).
		if (current == 0)
			return false;
	}
	// Allocate memory for the new node to insert.
	LinkedNode* newNode = new LinkedNode(tData);
	// Special case: Are we inserting after the last node?
	if (current == mLast)
	{
		newNode->next = 0;
		mLast = newNode;
	}
	// No, link in newNode after the current node.
	else
	{
		newNode->next = current->next;
		current->next->prev = newNode;
	}
	newNode->prev = current;
	current->next = newNode;
	return true;
}

template<typename T>
void LinkedList<T>::removeFirst()
{
	//check if list is not empty
	if (!isEmpty()) {
		//get the second element in the list
		LinkedNode* newFirst = mFirst->next;
		//check if we removed the only element in the list or not
		if (newFirst != 0) {
			//if there are more elements left, dereference the new first's prev element
			newFirst->prev = 0;
		}
		//otherwise, the list is now empty
		else
			mLast = 0;
		//dereference elements from the item to delete
		mFirst->next = 0;
		//delete the first element
		delete mFirst;
		//assign the next element (may be null) to be the first element
		mFirst = newFirst;
	}
}

template<typename T>
void LinkedList<T>::removeLast()
{
	//check if list is not empty
	if (!isEmpty())
	{
		//get the second last element in the list
		LinkedNode* newLast = mLast->prev;
		//check if the list has more than 1 elements
		if (newLast != 0) {
			//if there are more elements left, dereference the new last's next element
			newLast->next = 0;
		}
		//otherwise, the list is now empty
		else
			mFirst = 0;
		//dereference elements from the item to delete
		mLast->prev = 0;
		//delete the last element
		delete mLast;
		//assign the second last element (may be null) to be the last element
		mLast = newLast;
	}
}

template<typename T>
void LinkedList<T>::remove(T removalCandidate)
{
	LinkedNode* curr = mFirst;
	while (curr != 0) {
		//search for the removal candidate
		if (curr->data == removalCandidate) {
			//found our candidate
			//dereference from prev if available
			if (curr->prev != 0)
				curr->prev->next = curr->next;
			//dereference from next if available
			if (curr->next != 0)
				curr->next->prev = curr->prev;
			//dereference prev and next from curr
			curr->next = 0;
			curr->prev = 0;
			delete curr;
			return;
		}
		//keep iterating through the linked list
		else
			curr = curr->next;
	}
}

template<typename T>
void LinkedList<T>::destroy()
{
	// Is there at least one node in the list?
	if (mFirst != 0)
	{
		// Get a pointer to the first node.
		LinkedNode* current = mFirst;
		// Loop until the end of the list.
		while (current != 0)
		{
			// Save the current node.
			LinkedNode* oldNode = current;
			// Move to the next node.
			current = current->next;
			// Delete the old node.
			delete oldNode;
			oldNode = 0;
		}
	}
	mFirst = 0;
	mLast = 0;
}


