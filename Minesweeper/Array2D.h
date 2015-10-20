#ifndef ARRAY2D_H
#define ARRAY2D_H
#include "Row.h"

/************************************************************************
* Class: Array2D
*
* Constructors:
*	Array2D()
*		m_array initialized to nullptr and m_row and m_col to 0
*
*	Array2D(int row, int col = 0)
*		m_array initialized to nullptr, m_row to row, and m_col
*		to col
*
*	Array2D(const Array &copy)
*		Copy constructor
*
* Destructor:
*	~Array2D()
*		Deletes the columns first, then the rows
*
* Mutators:
*	Array2D& operator= (const Array2D& rhs)
*		If the invoking object and rhs are not the same, creates a new
*		Array2D that is a copy of rhs
*
* Methods:
*	Row<T> operator[](int index)
*		Returns the row at index
*
*	int GetRow()
*		Returns m_row
*
*	void SetRow(int row)
*		Sets m_row to row and reallocates memory
*
*	int GetColumn()
*		Returns m_col
*
*	void SetColumn(int column)
*		Sets m_col to column
*
*	T& Select(int row, int column)
*		Returns the data at m_array[row][column]
*
*	void SetData(int row, int column, T data)
*		Sets the data at m_array[row][column] to data
*
*	void Delete()
*		Deletes the entire array
*
*************************************************************************/

template <typename T>
class Array2D
{
public:
	//Default ctor
	Array2D();

	//Two arg ctor
	Array2D(int row, int col = 0);

	//Copy ctor
	Array2D(const Array2D &copy);

	//Destructor
	~Array2D();

	//Operator= function 
	Array2D& operator=(const Array2D &rhs);

	//[] operator function
	Row<T> operator[](int index);

	//const[] operator function
	Row<T> operator[](int index) const;

	//Returns m_row
	int GetRow();

	//Sets m_row to user input
	void SetRow(int rows);

	//Returns m_col
	int GetColumn();

	//Sets m_col to user input
	void SetColumn(int columns);

	//Returns the data at m_array[row][column]
	T& Select(int row, int column);

	//Sets the data at m_array[row][column] to user input
	void SetData(int row, int column, T data);

	//Deletes the 2d array
	void Delete();

private:
	T** m_array;				//2 dimensional array
	int m_row;					//Number of rows
	int m_col;					//Number of columns
};

#include "Array2D.tpp"

#endif
