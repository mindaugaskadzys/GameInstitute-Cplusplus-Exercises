#pragma once

//Ex 10.5.1 - Template Array class
template<typename T>
class Array
{
public:
	// Create an Array with zero elements.
	Array();

	// Create an Array with 'size' elements.
	Array(int size);

	// Create an Array from another Array--
	// be sure to prevent memory leaks!
	Array(const Array<T>& rhs);

	// Free dynamic memory.
	~Array();

	// Define how an Array shall be assigned to
	// another Array--be sure to prevent memory
	// leaks!
	Array<T>& operator=(const Array<T>& rhs);

	// Resize the Array to a new size.
	void resize(int newSize);

	// Return the number of elements in the array.
	int size();

	// Overload bracket operator so client can index
	// into Array objects and access the elements.
	T& operator[](int i);

private:
	T* mData; // Pointer to array of floats (dynamic memory).
	int mSize; // The number of elements in the array.
};

// Create an Array with zero elements.
template<typename T>
Array<T>::Array<T>()
{
	mData = new T[0];
	mSize = 0;
}

// Create an Array with 'size' elements.
template<typename T>
Array<T>::Array<T>(int size)
{
	mData = new T[size];
	mSize = size;
}

// Create an Array from another Array--
// be sure to prevent memory leaks!
template<typename T>
Array<T>::Array<T>(const Array<T>& rhs)
{
	mData = 0;
	*this = rhs;
}

// Free dynamic memory.
template<typename T>
Array<T>::~Array<T>()
{
	delete[] mData;
	mData = 0;
	mSize = 0;
}

// Define how an Array shall be assigned to
// another Array--be sure to prevent memory
// leaks!
template<typename T>
Array<T>& Array<T>::operator=(const Array<T>& rhs)
{
	if (this == &rhs)
		return *this;

	delete[] mData;
	mData = new T[rhs.mSize];
	mSize = rhs.mSize;
	for (int i = 0; i < mSize; i++) {
		mData[i] = rhs.mData[i];
	}

	return *this;
}

// Resize the Array to a new size.
template<typename T>
void Array<T>::resize(int newSize)
{
	T* newData = new T[newSize];
	int copySize = newSize > mSize ? mSize : newSize;

	for (int i = 0; i < copySize; i++)
	{
		newData[i] = mData[i];
	}

	delete[] mData;

	mData = newData;
	mSize = newSize;
}

// Return the number of elements in the array.
template<typename T>
int Array<T>::size()
{
	return mSize;
}

// Overload bracket operator so client can index
// into Array objects and access the elements.
template<typename T>
T& Array<T>::operator[](int i)
{
	return mData[i];
}