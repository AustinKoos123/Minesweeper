/**************************************************************
*	  Purpose:		Default ctor
*
*     Entry:		Object created using no parameters
*
*     Exit:			m_array initialized to nullptr,
*					m_row to 0, and m_col to 0
*
****************************************************************/
template <typename T>
Array2D<T>::Array2D() : m_array(nullptr), m_row(0), m_col(0)
{

}

/**************************************************************
*	  Purpose:		Two arg ctor
*
*     Entry:		Object created using two parameters
*
*     Exit:			m_array is allocated memory, m_row is
*					initialized to row, and m_col
*					is initialized to col
*
****************************************************************/
template <typename T>
Array2D<T>::Array2D(int row, int col) : m_array(nullptr), m_row(row), m_col(col)
{
	m_array = new T*[row];
	for (int i = 0; i < row; i++)
	{
		m_array[i] = new T[col];
	}
}

/**************************************************************
*	  Purpose:		Copy ctor
*
*     Entry:		Object passed or returned by value or
*					object instantiated with another object
*
*     Exit:			this will be a copy of copy
*
****************************************************************/
template <typename T>
Array2D<T>::Array2D(const Array2D &copy) : m_array(nullptr), m_row(0), m_col(0)
{
	*this = copy;
}

/**************************************************************
*	  Purpose:		Destructor
*
*     Entry:		Object to be destroyed
*
*     Exit:			m_array is deleted
*
****************************************************************/
template <typename T>
Array2D<T>::~Array2D() 
{
	Delete();
}

/**************************************************************
*	  Purpose:		Operator= function
*
*     Entry:		Object assigned to another object
*
*     Exit:			this will be a copy of rhs
*
****************************************************************/
template <typename T>
Array2D<T>& Array2D<T>::operator=(const Array2D &rhs)
{
	if (this != &rhs)
	{
		for (int i = 0; i < m_row; i++)
		{
			delete[] m_array[i];
		}

		delete[] m_array;
		m_array = nullptr;

		if (rhs.m_array != nullptr)
		{
			m_row = rhs.m_row;
			m_col = rhs.m_col;
			m_array = new T*[m_row];
			for (int i = 0; i < m_row; i++)
			{
				m_array[i] = new T[m_col];
			}

			for (int i = 0; i < m_row; i++)
			{
				for (int j = 0; j < m_col; j++)
				{
					m_array[i][j] = rhs.m_array[i][j];
				}
			}
		}
	}
	return *this;
}

/**************************************************************
*	  Purpose:		Operator[] function
*
*     Entry:		Object indexed using [] operator
*
*     Exit:			Returns the row at index
*
*	  Exception:	Throws an exception if the index is lower
*					than 0 or greater than/equal to the number
*					of rows
*
****************************************************************/
template <typename T>
Row<T> Array2D<T>::operator[](int index)
{
	if ((index > m_row) || (index < 0))
	{
		throw Exception("Row index out of bounds");
	}
	else
	{
		Row<T> row(*this, index);
		return row;
	}
}

/**************************************************************
*	  Purpose:		Const operator[] function
*
*     Entry:		Const object indexed using [] operator
*
*     Exit:			Returns the row at index
*
*	  Exception:	Throws an exception if the index is lower
*					than 0 or greater than/equal to the number
*					of rows
*
****************************************************************/
template <typename T>
Row<T> Array2D<T>::operator[](int index) const
{
	if ((index > m_row) || (index < 0))
	{
		throw Exception("Row index out of bounds");
	}
	else
	{
		Array2D<T> tempArray(m_row, m_col);
		for (int i = 0; i < m_row; i++)
		{
			for (int j = 0; j < m_col; j++)
			{
				tempArray[i][j] = m_array[i][j];
			}
		}

		Row<T> row(tempArray, index);
		return row;
	}
}

/**************************************************************
*	  Purpose:		Returns m_row
*
*     Entry:		Function called from invoking object
*
*     Exit:			Returns m_row
*
****************************************************************/
template <typename T>
int Array2D<T>::GetRow()
{
	return m_row;
}

/**************************************************************
*	  Purpose:		Sets m_row to rows and reallocates memory
*
*     Entry:		Function called from invoking object
*
*     Exit:			m_row set to rows
*
****************************************************************/
template <typename T>
void Array2D<T>::SetRow(int rows)
{
	T** tempArray = new T*[rows];
	for (int i = 0; i < rows; i++)
	{
		tempArray[i] = new T[m_col];
	}

	for (int i = 0; i < m_row; i++)
	{
		for (int j = 0; j < m_col; j++)
		{
			tempArray[i][j] = m_array[i][j];
		}
	}

	for (int i = 0; i < m_row; i++)
	{
		delete[] m_array[i];
	}

	delete[] m_array;

	m_array = new T*[rows];
	for (int i = 0; i < rows; i++)
	{
		m_array[i] = new T[m_col];
	}

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < m_col; j++)
		{
			m_array[i][j] = tempArray[i][j];
		}
	}

	m_row = rows;

	for (int i = 0; i < m_row; i++)
	{
		delete[] tempArray[i];
	}

	delete[] tempArray;
}

/**************************************************************
*	  Purpose:		Returns m_col
*
*     Entry:		Function called from invoking object
*
*     Exit:			m_col returned
*
****************************************************************/
template <typename T>
int Array2D<T>::GetColumn()
{
	return m_col;
}

/**************************************************************
*	  Purpose:		Sets m_col to column and reallocates memory
*					if column is > m_col.  m_col set to 0 if column
*					is < 0
*
*     Entry:		Function called from invoking object
*
*     Exit:			m_col set to column
*
****************************************************************/
template <typename T>
void Array2D<T>::SetColumn(int column)
{
	if (column <= m_col)
	{
		if (column <= 0)
		{
			m_col = 0;
		}
		else
		{
			m_col = column;
		}
	}
	else
	{
		T** tempArray = new T*[m_row];
		for (int i = 0; i < m_row; i++)
		{
			tempArray[i] = new T[column];
		}

		for (int i = 0; i < m_row; i++)
		{
			for (int j = 0; j < m_col; j++)
			{
				tempArray[i][j] = m_array[i][j];
			}
		}

		for (int i = 0; i < m_row; i++)
		{
			delete[] m_array[i];
			m_array[i] = new T[column];
			
			for (int j = 0; j < column; j++)
			{
				m_array[i][j] = tempArray[i][j];
			}
		}

		for (int i = 0; i < m_row; i++)
		{
			delete[] tempArray[i];
		}

		delete[] tempArray;

		m_col = column;
	}
}

/**************************************************************
*	  Purpose:		Returns data at m_array[row][column]
*
*     Entry:		Function called from invoking object
*
*     Exit:			data returned
*
****************************************************************/
template <typename T>
T& Array2D<T>::Select(int row, int column)
{
	if ((row >= m_row) || (row < 0))
	{
		throw Exception("Row index out of bounds");
	}
	else if ((column >= m_col) || (column < 0))
	{
		throw Exception("Column index out of bounds");
	}
	else	
	{
		return m_array[row][column];
	}
}

/**************************************************************
*	  Purpose:		Sets data at m_array[row][column] to data
*
*     Entry:		Function called from invoking object
*
*     Exit:			data changed 
*
****************************************************************/
template <typename T>
void Array2D<T>::SetData(int row, int column, T data)
{
	if ((row >= m_row) || (row < 0))
	{
		throw Exception("Row index out of bounds");
	}
	else if ((column >= m_col) || (column < 0))
	{
		throw Exception("Column index out of bounds");
	}
	else
	{
		m_array[row][column] = data;
	}
}

/**************************************************************
*	  Purpose:		Deletes m_array and sets it to nullptr
*
*     Entry:		Function called from invoking object
*
*     Exit:			m_array deleted
*
****************************************************************/
template <typename T>
void Array2D<T>::Delete()
{
	if(m_array != nullptr)
	{
		for (int i = 0; i < m_row; i++)
		{
			delete[] m_array[i];
		}

		delete[] m_array;
		m_array = nullptr;
	}
}