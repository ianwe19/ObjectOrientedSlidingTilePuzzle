#include "specification.h"
#include <iostream>
#include <iomanip>
#include <time.h>
#include <Windows.h>


#define NUM_SCRAMBLE    1000000 // number of times to scramble board

#define PIVOT_SYMBOL	"*"		// used to show the pivot location when drawing the board

// direction codes (part of the slideTile() interface)
#define SLIDE_UP		1		// pass to slideTile() to trigger UP movement
#define SLIDE_DOWN		2		// pass to slideTile() to trigger DOWN movement
#define SLIDE_LEFT		3		// pass to slideTile() to trigger LEFT movement
#define SLIDE_RIGHT		4		// pass to slideTile() to trigger RIGHT movement
#define BRUTE_FORCE     999     // pass to inputLoop() to solve with RNG

// if there isnt an extra line here, the comment on what is currently line 23 inexplicably causes a compiler error
#define UNSET			-1		// used to arbitrarily indicate an undetermined state in a constuct

#define COLOR_DEFAULT	7
#define COLOR_RED		12
#define COLOR_GREEN		10


int main() {
	char keyStroke = ' ';
	int directionCode = UNSET;
	int boardWidth = 0;
	int boardHeight = 0;
	int choice = 0;

	// seed pseudo rng
	srand(time(NULL));

	// allow user to define some stuff
	std::cout << "Enter board width: ";
	std::cin >> boardWidth;
	std::cout << "Enter board height: ";
	std::cin >> boardHeight;

	system("cls"); // clear console window

	SlidingPuzzle puzzle0(boardWidth, boardHeight);

	puzzle0.initializeBoard();

	while (puzzle0.isBoardSolved()) { // make sure the scrambled board isnt a solved board
		puzzle0.scrambleBoard();
	}

	while (1) {
		directionCode = UNSET;

		puzzle0.printBoard();

		puzzle0.gameLoop(directionCode, keyStroke);

		system("cls");

		// win condition check
		if (puzzle0.isBoardSolved()) {
			puzzle0.printBoard();
			std::cout << "\nboard is solved\n\ntook " << puzzle0.getTotalMoveCount() << " moves\n\n";
			break;
		}
	}

	return 0;
}
