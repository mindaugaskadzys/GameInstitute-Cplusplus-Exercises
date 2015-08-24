// Table.h
#ifndef TABLE_H
#define TABLE_H
template <typename T>
class Table
{
public:
	Table();
	Table(int m, int n);
	Table(int m, int n, const T& value);
	Table(const Table<T>& rhs);
	~Table();
	Table<T>& operator=(const Table& rhs);
	T& operator()(int i, int j);
	int numRows()const;
	int numCols()const;
	void resize(int m, int n);
	void resize(int m, int n, const T& value);
private:
	// Make private because this method should only be used
	// internally by the class.
	void destroy();
private:
	int mNumRows;
	int mNumCols;
	T** mDataMatrix;
};
template <typename T>
Table<T>::Table<T>()
{
	mDataMatrix = 0;
	mNumRows = 0;
	mNumCols = 0;
}
template <typename T>
Table<T>::Table<T>(int m, int n)
{
	mDataMatrix = 0;
	mNumRows = 0;
	mNumCols = 0;
	resize(m, n, T());
}
template <typename T>
Table<T>::Table<T>(int m, int n, const T& value)
{
	mDataMatrix = 0;
	mNumRows = 0;
	mNumCols = 0;
	resize(m, n, value);
}
template <typename T>
Table<T>::Table<T>(const Table<T>& rhs)
{
	mDataMatrix = 0;
	mNumRows = 0;
	mNumCols = 0;
	*this = rhs;
}
template <typename T>
Table<T>::~Table<T>()
{
	// Destroy any previous dynamic memory.
	destroy();
}
template <typename T>
Table<T>& Table<T>::operator=(const Table& rhs)
{
	// Check for self assignment.
	if (this == &rhs) return *this;
	// Reallocate the table based on rhs info.
	resize(rhs.mNumRows, rhs.mNumCols);
	// Copy the entries over element-by-element.
	for (int i = 0; i < mNumRows; ++i)
		for (int j = 0; j < mNumCols; ++j)
			mDataMatrix[i][j] = rhs.mDataMatrix[i][j];
	// return a reference to *this so we can do chain
	// assignments: x = y = z = w = ...
	return *this;
}
template <typename T>
T& Table<T>::operator()(int i, int j)
{
	return mDataMatrix[i][j]; // return the ijth table entry.
}
template <typename T>
int Table<T>::numRows()const
{
	return mNumRows; // Return the number of rows.
}
template <typename T>
int Table<T>::numCols()const
{
	return mNumCols; // Return the number of columns.
}
template <typename T>
void Table<T>::resize(int m, int n)
{
	// Call resize and use default constructor T()
	// as 'value'.
	resize(m, n, T());
}

template <typename T>
void Table<T>::resize(int m, int n, const T& value)
{
	// Destroy the previous data.
	destroy();
	// Save dimensions.
	mNumRows = m;
	mNumCols = n;
	// Allocate a row (array) of pointers.
	mDataMatrix = new T*[mNumRows];
	// Now, loop through each pointer in this row array.
	for (int i = 0; i < mNumRows; ++i)
	{
		// And allocate a column (array) to build the table.
		mDataMatrix[i] = new T[mNumCols];
		// Now loop through each element in this row[i]
		// and copy 'value' into it.
		for (int j = 0; j < mNumCols; ++j)
			mDataMatrix[i][j] = value;
	}
}
template <typename T>
void Table<T>::destroy()
{
	// Does the matrix exist?
	if (mDataMatrix)
	{
		for (int i = 0; i < mNumRows; ++i)
		{
			// Does the ith row exist?
			if (mDataMatrix[i])
			{
				// Yes, delete it.
				delete[]mDataMatrix[i];
				mDataMatrix[i] = 0;
			}
		}
		// Delete the row-array.
		delete[] mDataMatrix;
		mDataMatrix = 0;
	}
	mNumRows = 0;
	mNumCols = 0;
}
#endif // TABLE_H