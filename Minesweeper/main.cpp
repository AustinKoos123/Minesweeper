/*********************************************************************************************
*Author:					Austin Koos
*Date Created:				10/10/2015
*Last Modification Date:	10/11/2015
*Lab Number:				CST 211 Lab 1 Minesweeper
*Filename:					main.cpp
*
*Overview:
*	Allows the user to play a console-based Minesweeper game.  3 levels of difficulty: Beginner,
*	Intermediate, and Expert.  The player wins if all non-bomb squares are uncovered. 
*
*Input:
*
*
*Output:
*	Contents of arrays, number of rows and columns, and exceptions displayed to console
*
***********************************************************************************************/
#include "Minesweeper.h"
#include <cstdlib>
#include <time.h>

int main()
{
	srand(time(NULL));

	Minesweeper minesweeper;
	
	minesweeper.Play();

	return 0;
}