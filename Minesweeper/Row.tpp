/**************************************************************
*	  Purpose:		Two arg ctor
*
*     Entry:		Object created using two parameters
*
*     Exit:			m_array2D is allocated memory and m_row is
*					initialized to row
*
****************************************************************/
template <typename T>
Row<T>::Row(Array2D<T> &arr, int row) : m_array2D(arr), m_row(row)
{

}

/**************************************************************
*	  Purpose:		Operator[] function
*
*     Entry:		Object indexed using [] operator
*
*     Exit:			Returns the data at m_array2D[m_row][column]
*
*	  Exception:	Throws an exception if the column is lower
*					than 0 or greater than/equal to the number
*					of columns
*
****************************************************************/
template <typename T>
T& Row<T>::operator[](int column)
{
	if ((column > m_array2D.GetColumn()) || (column < 0))
	{
		throw Exception("Column index out of bounds");
	}
	else
	{
		return m_array2D.Select(m_row, column);
	}
}

/**************************************************************
*	  Purpose:		Const operator[] function
*
*     Entry:		Const object indexed using [] operator
*
*     Exit:			Returns the data at m_array2D[m_row][column]
*
*	  Exception:	Throws an exception if the column is lower
*					than 0 or greater than/equal to the number
*					of columns
*
****************************************************************/
template <typename T>
T& Row<T>::operator[](int column) const
{
	if ((column > m_array2D.GetColumn()) || (column < 0))
	{
		throw Exception("Column index out of bounds");
	}
	else
	{
		return m_array2D.Select(m_row, column);
	}
}