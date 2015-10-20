#include "Minesweeper.h"
#include <cstdlib>
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

/**************************************************************
*	  Purpose:		Default ctor
*
*     Entry:		Object created using no parameters
*
*     Exit:			m_board initialized to default, m_boardRows,
*					m_boardCols, and m_numMines to 0
*
****************************************************************/
Minesweeper::Minesweeper() : m_board(), m_boardRows(0), m_boardCols(0), m_numMines(0)
{

}

/**************************************************************
*	  Purpose:		Destructor
*
*     Entry:		Object to be destroyed
*
*     Exit:			m_board is deleted, m_boardRows and m_boardCols
*					set to 0
*
****************************************************************/
Minesweeper::~Minesweeper()
{
	m_board.Delete();
	m_boardRows = 0;
	m_boardCols = 0;
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
Minesweeper::Minesweeper(const Minesweeper& copy) : m_board(), m_boardRows(0), m_boardCols(0), m_numMines(0)
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
Minesweeper& Minesweeper::operator=(const Minesweeper& rhs)
{
	if (this != &rhs)
	{
		m_board = rhs.m_board;
		m_boardRows = rhs.m_boardRows;
		m_boardCols = rhs.m_boardCols;
		m_numMines = rhs.m_numMines;
	}

	return *this;
}

/**************************************************************
*	  Purpose:		Runs the game
*
*     Entry:		Function called 
*
*     Exit:			Game has been played
*
****************************************************************/
void Minesweeper::Play()
{
	Cell currentCell;
	bool end = false;
	bool lose = false;
	char option = '\0';

	BoardInput();
	PlaceMines();
	CountMines();
	DisplayBoard();

	while (!end)
	{
		while (!CheckWin() && !lose)
		{
			currentCell = CellInput();

			if (currentCell.GetBombSquare())
			{
				lose = true;

				UncoverBoard();
				DisplayBoard();

				cout << "You lose!  Play again? Y/N: ";
				cin >> option;

				if ((option == 'Y') || (option == 'y'))
				{
					lose = false;

					ResetGame();
					BoardInput();
					PlaceMines();
					CountMines();
					DisplayBoard();
				}
				else
				{
					end = true;
				}
			}
			else
			{
				cout << endl << endl;

				DisplayBoard();
			}
		}
	}
}

/**************************************************************
*	  Purpose:		Checks to see if the board is in winning state
*
*     Entry:		Called after a move has been made
*
*     Exit:			Returns true if all non-bomb squares have been
*					uncovered.  False otherwise.
*
****************************************************************/
bool Minesweeper::CheckWin()
{
	bool win = true;

	for (int i = 0; i < m_boardRows; i++)
	{
		for (int j = 0; j < m_boardCols; j++)
		{
			if (m_board[i][j].GetCovered() == true)
			{
				win = false;

				return win;
			}
		}
	}

	return win;
}

/**************************************************************
*	  Purpose:		Places mines on the board
*
*     Entry:		Called after difficulty has been chosen
*
*     Exit:			Populates the board with m_numBombs number
*					of bombs
*
****************************************************************/
void Minesweeper::PlaceMines()
{
	for (int i = 0; i < m_numMines; i++)
	{
		int row = rand() % m_boardRows;
		int col = rand() % m_boardCols;

		if (m_board[row][col].GetBombSquare())
		{
			while (m_board[row][col].GetBombSquare())
			{
				row = rand() % m_boardRows;
				col = rand() % m_boardCols;
			}
		}

		m_board[row][col].SetBombSquare(true);
	}
}

/**************************************************************
*	  Purpose:		Counts the bombs in adjacent cells of all cells
*					on the board.
*
*     Entry:		Called after mines have been placed
*
*     Exit:			Number of mines for each cell is set
*
*     Exception:	Exceptions thrown when trying to access the 
*					board out-of-bounds
*
****************************************************************/
void Minesweeper::CountMines()
{
	for (int i = 0; i < m_boardRows; i++)
	{
		for (int j = 0; j < m_boardCols; j++)
		{
			if (!m_board[i][j].GetBombSquare())
			{
				try
				{
					if (m_board[i - 1][j - 1].GetBombSquare())
					{
						m_board[i][j].SetNumBombs(m_board[i][j].GetNumBombs() + 1);
					}
				}
				catch (Exception &except)
				{
					//Catch Exceptions generated when elements outside m_board are accessed
					//on border cases.  Does nothing with them, just helps limit bound checking
				}

				try
				{
					if (m_board[i - 1][j].GetBombSquare())
					{
						m_board[i][j].SetNumBombs(m_board[i][j].GetNumBombs() + 1);
					}
				}
				catch (Exception &except)
				{
					//Catch Exceptions generated when elements outside m_board are accessed
					//on border cases.  Does nothing with them, just helps limit bound checking
				}

				try
				{
					if (m_board[i - 1][j + 1].GetBombSquare())
					{
						m_board[i][j].SetNumBombs(m_board[i][j].GetNumBombs() + 1);
					}
				}
				catch (Exception &except)
				{
					//Catch Exceptions generated when elements outside m_board are accessed
					//on border cases.  Does nothing with them, just helps limit bound checking
				}

				try
				{
					if (m_board[i][j - 1].GetBombSquare())
					{
						m_board[i][j].SetNumBombs(m_board[i][j].GetNumBombs() + 1);
					}
				}
				catch (Exception &except)
				{
					//Catch Exceptions generated when elements outside m_board are accessed
					//on border cases.  Does nothing with them, just helps limit bound checking
				}

				try
				{
					if (m_board[i][j + 1].GetBombSquare())
					{
						m_board[i][j].SetNumBombs(m_board[i][j].GetNumBombs() + 1);
					}
				}
				catch (Exception &except)
				{
					//Catch Exceptions generated when elements outside m_board are accessed
					//on border cases.  Does nothing with them, just helps limit bound checking
				}

				try
				{
					if (m_board[i + 1][j - 1].GetBombSquare())
					{
						m_board[i][j].SetNumBombs(m_board[i][j].GetNumBombs() + 1);
					}
				}
				catch (Exception &except)
				{
					//Catch Exceptions generated when elements outside m_board are accessed
					//on border cases.  Does nothing with them, just helps limit bound checking
				}

				try
				{
					if (m_board[i + 1][j].GetBombSquare())
					{
						m_board[i][j].SetNumBombs(m_board[i][j].GetNumBombs() + 1);
					}
				}
				catch (Exception &except)
				{
					//Catch Exceptions generated when elements outside m_board are accessed
					//on border cases.  Does nothing with them, just helps limit bound checking
				}

				try
				{
					if (m_board[i + 1][j + 1].GetBombSquare())
					{
						m_board[i][j].SetNumBombs(m_board[i][j].GetNumBombs() + 1);
					}
				}
				catch (Exception &except)
				{
					//Catch Exceptions generated when elements outside m_board are accessed
					//on border cases.  Does nothing with them, just helps limit bound checking
				}
			}
		}
	}
}

/**************************************************************
*	  Purpose:		Handles input for cells
*
*     Entry:		Called when a move is to be made
*
*     Exit:			Returns the Cell the user specifies
*
****************************************************************/
Cell& Minesweeper::CellInput()
{
	int row = 0;
	int col = 0;
	int option = 0;

	cout << "Enter row: ";
	cin >> row;

	while ((row < 0) || (row >= m_boardRows))
	{
		cout << "Invalid input.  Try again" << endl;
		cout << "Enter row: ";
		cin >> row;
	}

	cout << "Enter column: ";
	cin >> col;

	while ((col < 0) || (col >= m_boardCols))
	{
		cout << "Invalid input.  Try again" << endl;
		cout << "Enter column: ";
		cin >> col;
	}

	cout << "What would you like to do? " << endl;
	cout << "1. Mark square for bomb" << endl;
	cout << "2. Uncover square" << endl;
	cout << "Choice: ";
	cin >> option;

	if (option == 1)
	{
		m_board[row][col].SetMarkedSquare(true);
	}
	else if (option == 2)
	{
		m_board[row][col].SetCovered(false);
	}
	else
	{
		cout << "Invalid input.  Try again" << endl;
		cout << "What would you like to do? " << endl;
		cout << "1. Mark square for bomb" << endl;
		cout << "2. Uncover square" << endl;
		cout << "Choice: ";
		cin >> option;

		while ((option != 1) && (option != 2))
		{
			cout << "Invalid input.  Try again" << endl;
			cout << "What would you like to do? " << endl;
			cout << "1. Mark square for bomb" << endl;
			cout << "2. Uncover square" << endl;
			cout << "Choice: ";
			cin >> option;
		}

		if (option == 1)
		{
			m_board[row][col].SetMarkedSquare(true);
		}
		else 
		{
			m_board[row][col].SetMarkedSquare(true);
		}
	}

	return m_board[row][col];
}

/**************************************************************
*	  Purpose:		Handles input for determining difficulty
*					and sets the board up
*
*     Entry:		Called when a game starts
*
*     Exit:			Difficulty selected, m_boardRows, m_boardCols
*					m_numBombs, and board size set.
*
****************************************************************/
void Minesweeper::BoardInput()
{
	int option = 0;

	cout << "Select difficulty" << endl;
	cout << "1. Beginner (8 x 8 grid, 10 mines)" << endl;
	cout << "2. Intermediate (16 x 16 grid, 40 mines)" << endl;
	cout << "3. Expert (16 x 30 grid, 100 mines)" << endl;
	cout << "Difficulty: ";
	cin >> option;

	if (option == 1)
	{
		m_boardRows = 8;
		m_boardCols = 8;
		m_board.SetRow(8);
		m_board.SetColumn(8);
		m_numMines = 10;
	}
	else if (option == 2)
	{
		m_boardRows = 16;
		m_boardCols = 16;
		m_board.SetRow(16);
		m_board.SetColumn(16);
		m_numMines = 40;
	}
	else if (option == 3)
	{
		m_boardRows = 16;
		m_boardCols = 30;
		m_board.SetRow(16);
		m_board.SetColumn(30);
		m_numMines = 100;
	}
	else
	{
		cout << "Invalid option.  Try again" << endl;
		cout << "Select difficulty" << endl;
		cout << "1. Beginner (8 x 8 grid, 10 mines)" << endl;
		cout << "2. Intermediate (16 x 16 grid, 40 mines)" << endl;
		cout << "3. Expert (16 x 30 grid, 100 mines)" << endl;
		cout << "Difficulty: ";
		cin >> option;

		while ((option < 1) || (option > 3))
		{
			cout << "Invalid option.  Try again" << endl;
			cout << "Select difficulty" << endl;
			cout << "1. Beginner (8 x 8 grid, 10 mines)" << endl;
			cout << "2. Intermediate (16 x 16 grid, 40 mines)" << endl;
			cout << "3. Expert (16 x 30 grid, 100 mines)" << endl;
			cout << "Difficulty: ";
			cin >> option;
		}

		if (option == 1)
		{
			m_board.SetRow(8);
			m_board.SetColumn(8);
			m_numMines = 10;
		}
		else if (option == 2)
		{
			m_board.SetRow(16);
			m_board.SetColumn(16);
			m_numMines = 40;
		}
		else
		{
			m_board.SetRow(16);
			m_board.SetColumn(30);
			m_numMines = 100;
		}
	}
}

/**************************************************************
*	  Purpose:		Uncovers all cells on the board
*
*     Entry:		Called after the player loses
*
*     Exit:			All cells set to uncovered state
*
****************************************************************/
void Minesweeper::UncoverBoard()
{
	for (int i = 0; i < m_boardRows; i++)
	{
		for (int j = 0; j < m_boardCols; j++)
		{
			m_board[i][j].SetCovered(false);
		}
	}
}

/**************************************************************
*	  Purpose:		Resets board to default state
*
*     Entry:		Called after player requests to play again
*
*     Exit:			Game reset
*
****************************************************************/
void Minesweeper::ResetGame()
{
	for (int i = 0; i < m_boardRows; i++)
	{
		for (int j = 0; j < m_boardCols; j++)
		{
			m_board[i][j].SetBombSquare(false);
			m_board[i][j].SetCovered(true);
			m_board[i][j].SetMarkedSquare(false);
			m_board[i][j].SetNumBombs(0);
		}
	}

	m_boardRows = 0;
	m_boardCols = 0;
	m_numMines = 0;
}

/**************************************************************
*	  Purpose:		Displays the board to the console window
*
*     Entry:		Called before the first move, after any move,
*					and when the player loses
*
*     Exit:			Board displayed
*
****************************************************************/
void Minesweeper::DisplayBoard()
{
	for (int i = 0; i < m_boardCols; i++)
	{
		if (i >= 10)
		{
			cout << " " << i << " ";
		}
		else
		{
			cout << "  " << i << " ";
		}
	}

	cout << endl;

	for (int i = 0; i < m_boardCols; i++)
	{
		cout << "____";
	}

	cout << endl;

	int currentRow = 0;
	int currentCol = 0;
	int displayInfoRow = 1;		

	for (int i = 0; i < (m_boardRows * 3); i++)
	{
		for (int j = 0; j < m_boardCols; j++)
		{
			if (((i + 1) % 3) == 0)
			{
				cout << "|___";
			}
			else if (i == displayInfoRow)
			{
				if (m_board[currentRow][currentCol].GetMarkedSquare()) 
				{
					cout << "| M ";
					currentCol++;
				}

				else if (m_board[currentRow][currentCol].GetCovered())
				{
					cout << "| ? ";
					currentCol++;
				}
				else
				{
					if (m_board[currentRow][currentCol].GetBombSquare())
					{
						cout << "| X ";
						currentCol++;
					}
					else
					{
						if (m_board[currentRow][currentCol].GetNumBombs() == 0)
						{
							cout << "|   ";
							currentCol++;
						}
						else
						{
							cout << "| " << m_board[currentRow][currentCol].GetNumBombs() << " ";
							currentCol++;
						}
					}
				}
			}
			else
			{
				cout << "|   ";
			}
		}

		if (i == displayInfoRow)
		{
			cout << "| " << currentRow << endl;

			currentRow++;
			currentCol = 0;
			displayInfoRow = displayInfoRow + 3;
		}
		else
		{
			cout << "|" << endl;
		}
	}
}