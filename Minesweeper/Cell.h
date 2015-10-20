#ifndef CELL_H
#define CELL_H

/************************************************************************
* Class: Cell
*
* Constructors:
*	Cell()
*		m_array initialized to nullptr and m_row and m_col to 0
*
*	Cell(const Cell &copy)
*		Copy constructor
*
* Destructor:
*	~Cell()
*		Deletes the columns first, then the rows
*
* Mutators:
*	Cell& operator= (const Cell& rhs)
*		If the invoking object and rhs are not the same, creates a new
*		Cell that is a copy of rhs
*
* Methods:
*	bool GetCovered();
*		Returns m_covered
*
*	void SetCovered(bool covered);
*		Sets m_covered to covered
*
*	int GetNumBombs();
*		Returns m_numBombs
*
*	void SetNumBombs(int bombs);
*		Sets m_numBombs to bombs
*
*	bool GetBombSquare();
*		Returns m_bombSquare
*	
*	void SetBombSquare(bool bombSquare);
*		Sets m_bombSquare to bombSquare
*
*	bool GetMarkedSquare();
*		Returns m_markedSquare
*
*	void SetMarkedSquare(bool marked);
*		Sets m_markedSquare to marked
*
*************************************************************************/
class Cell
{
public:
	//Default ctor
	Cell();

	//Destructor
	~Cell();

	//Copy ctor
	Cell(const Cell& copy);

	//Copies rhs and returns 
	Cell& operator=(const Cell& rhs);

	//Returns m_covered
	bool GetCovered();

	//Sets m_covered to covered
	void SetCovered(bool covered);

	//Returns m_numBombs
	int GetNumBombs();

	//Sets m_numBombs to bombs
	void SetNumBombs(int bombs);

	//Returns m_bombSquare
	bool GetBombSquare();

	//Sets m_bombSquare to bombSquare
	void SetBombSquare(bool bombSquare);

	//Returns m_markedSquare
	bool GetMarkedSquare();

	//Sets m_markedSquare to marked
	void SetMarkedSquare(bool marked);

private:
	bool m_covered;			//Determines if the cells info is displayed
	int m_numBombs;			//Number of bombs in adjecent squares
	bool m_bombSquare;		//Determines if a bomb is in the cell
	bool m_markedSquare;	//Determines if the user marked the cell for a bomb
};

#endif
