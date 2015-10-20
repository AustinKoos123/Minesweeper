#ifndef MINESWEEPER_H
#define MINESWEEPER_H
#include "Array2D.h"
#include "Cell.h"

/************************************************************************
* Class: Minesweeper
*
* Constructors:
*	Minesweeper()
*		m_board initialized to default, m_boardRows, m_boardCols, 
*		and m_numBombs to 0
*
*	Minesweeper(const Minesweeper &copy)
*		Copy constructor
*
* Destructor:
*	~Minesweeper()
*		Deletes the board, sets m_boardRows, m_boardCols, and m_numBombs to 0
*
* Mutators:
*	Minesweeper& operator= (const Minesweeper& rhs)
*		If the invoking object and rhs are not the same, creates a new
*		Minesweeper that is a copy of rhs
*
* Methods:
*	void Play()
*		Runs the game.  Sets up and displays the board, takes input from 
*		the console.
*
*	bool CheckWin()
*		Checks all the squares in the board.  If one hasn't been uncovered,
*		returns false
*
*	void PlaceMines()
*		Places mines by randomly selecting 2 numbers, one between 0 and m_boardRows
*		and the other between 0 and m_boardCols.  Sets the mine at that spot
*
*	void CountMines()
*		Counts the surrounding mines of each square
*
*	Cell& CellInput()
*		Handles input for the cell the user wants to manipulate
*
*	void BoardInput()
*		Takes in user input determining the board size and adjusts the board
*
*	void UncoverBoard()
*		Sets all cells to uncovered state.  Used when the player loses
*
*	void ResetGame()
*		Resets game back to default state
*
*	void DisplayBoard()
*		Displays board to the console window
*
*************************************************************************/
class Minesweeper
{
public:
	//Default ctor
	Minesweeper();

	//Destructor
	~Minesweeper();

	//Copy ctor
	Minesweeper(const Minesweeper& copy);

	//Copies rhs and returns it
	Minesweeper& operator=(const Minesweeper& rhs);

	//Runs the game
	void Play();
	
	//Checks for player win
	bool CheckWin();

	//Places mines on the board
	void PlaceMines();

	//Counts the mines in adjacent cells
	void CountMines();

	//Handles user input of cells
	Cell& CellInput();

	//Handles user input of the board
	void BoardInput();

	//Sets board to uncovered state
	void UncoverBoard();

	//Resets the game to default state
	void ResetGame();

	//Displays the board to the console window
	void DisplayBoard();

private:
	Array2D<Cell> m_board;			//Minesweeper board
	int m_boardRows;				//Number of rows
	int m_boardCols;				//Number of columns
	int m_numMines;					//Number of mines
};

#endif
