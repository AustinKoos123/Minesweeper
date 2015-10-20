#ifndef ROW_H
#define ROW_H
#include "Exception.h"

template <typename T>
class Array2D;

/************************************************************************
* Class: Array2D
*
* Constructors:
*	Row(Array2D<T> &arr, int row)
*		m_array initialized to arr, m_row to row
*
* Methods:
*	T& operator[](int column)
*		Returns the data at m_array[m_row][column] by calling the Select
*		function
*
*************************************************************************/
template <typename T>
class Row
{
public:
	//Two arg ctor
	Row(Array2D<T> &arr, int row);

	//[] operator function
	T& operator[](int column);

	//Const [] operator function
	T& operator[](int column) const;

private:
	Array2D<T> &m_array2D;			//2D array
	int m_row;						//The row that has been accessed
};

#include "Row.tpp"

#endif
