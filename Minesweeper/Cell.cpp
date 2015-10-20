#include "Cell.h"

/**************************************************************
*	  Purpose:		Default ctor
*
*     Entry:		Object created using no parameters
*
*     Exit:			m_covered set to true, m_numBombs to 0, 
*					m_bombSquare and m_markedSquare to false
*
****************************************************************/
Cell::Cell() : m_covered(true), m_numBombs(0), m_bombSquare(false), m_markedSquare(false)
{

}

/**************************************************************
*	  Purpose:		Destructor
*
*     Entry:		Object to be destroyed
*
*     Exit:			Variables are set to default values
*
****************************************************************/
Cell::~Cell()
{
	m_covered = true;
	m_numBombs = 0;
	m_bombSquare = false;
	m_markedSquare = false;
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
Cell::Cell(const Cell& copy) : m_covered(true), m_numBombs(0), m_bombSquare(false), m_markedSquare(false)
{
	*this = copy;
}

/**************************************************************
*	  Purpose:		Operator= function
*
*     Entry:		Object assigned to another object
*
*     Exit:			this will be a copy of rhs
*
****************************************************************/
Cell& Cell::operator=(const Cell& rhs)
{
	if (this != &rhs)
	{
		m_covered = rhs.m_covered;
		m_numBombs = rhs.m_numBombs;
		m_bombSquare = rhs.m_bombSquare;
		m_markedSquare = rhs.m_markedSquare;
	}

	return *this;
}

/**************************************************************
*	  Purpose:		Returns m_covered
*
*     Entry:		Function called from invoking object
*
*     Exit:			Returns m_covered
*
****************************************************************/
bool Cell::GetCovered()
{
	return m_covered;
}

/**************************************************************
*	  Purpose:		Sets m_covered to covered
*
*     Entry:		Function called from invoking object
*
*     Exit:			m_covered set to covered
*
****************************************************************/
void Cell::SetCovered(bool covered) 
{
	m_covered = covered;
}

/**************************************************************
*	  Purpose:		Returns m_numBombs
*
*     Entry:		Function called from invoking object
*
*     Exit:			Returns m_numBombs
*
****************************************************************/
int Cell::GetNumBombs()
{
	return m_numBombs;
}

/**************************************************************
*	  Purpose:		Sets m_numBombs to bombs
*
*     Entry:		Function called from invoking object
*
*     Exit:			m_numBombs set to bombs
*
****************************************************************/
void Cell::SetNumBombs(int bombs)
{
	m_numBombs = bombs;
}

/**************************************************************
*	  Purpose:		Returns m_bombSquare
*
*     Entry:		Function called from invoking object
*
*     Exit:			Returns m_bombSquare
*
****************************************************************/
bool Cell::GetBombSquare()
{
	return m_bombSquare;
}

/**************************************************************
*	  Purpose:		Sets m_bombSquare to bombSquare
*
*     Entry:		Function called from invoking object
*
*     Exit:			m_bombSquare set to bombSquare
*
****************************************************************/
void Cell::SetBombSquare(bool bombSquare)
{
	m_bombSquare = bombSquare;
}

/**************************************************************
*	  Purpose:		Returns m_markedSquare
*
*     Entry:		Function called from invoking object
*
*     Exit:			Returns m_markedSquare
*
****************************************************************/
bool Cell::GetMarkedSquare()
{
	return m_markedSquare;
}

/**************************************************************
*	  Purpose:		Sets m_markedSquare to marked
*
*     Entry:		Function called from invoking object
*
*     Exit:			m_markedSquare set to marked
*
****************************************************************/
void Cell::SetMarkedSquare(bool marked)
{
	m_markedSquare = marked;
}