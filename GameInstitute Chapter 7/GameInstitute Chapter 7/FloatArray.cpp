#include "FloatArray.h"

//Ex 7.9.2 - FloatArray class

// Create a FloatArray with zero elements.
FloatArray::FloatArray()
{
	mData = new float[0];
	mSize = 0;
}

// Create a FloatArray with 'size' elements.
FloatArray::FloatArray(int size)
{
	mData = new float[size];
	mSize = size;
}

// Create a FloatArray from another FloatArray--
// be sure to prevent memory leaks!
FloatArray::FloatArray(const FloatArray& rhs)
{
	mData = 0;
	*this = rhs;
}

// Free dynamic memory.
FloatArray::~FloatArray()
{
	delete[] mData;
	mData = 0;
	mSize = 0;
}

// Define how a FloatArray shall be assigned to
// another FloatArray--be sure to prevent memory
// leaks!
FloatArray& FloatArray::operator=(const FloatArray& rhs)
{
	if (this == &rhs)
		return *this;

	delete[] mData;
	mData = new float[rhs.mSize];
	mSize = rhs.mSize;
	for (int i = 0; i < mSize; i++) {
		mData[i] = rhs.mData[i];
	}

	return *this;
}

// Resize the FloatArray to a new size.
void FloatArray::resize(int newSize)
{
	float* newData = new float[newSize];
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
int FloatArray::size()
{
	return mSize;
}

// Overload bracket operator so client can index
// into FloatArray objects and access the elements.
float& FloatArray::operator[](int i)
{
	return mData[i];
}
