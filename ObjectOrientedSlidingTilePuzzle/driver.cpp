#include "specification.h"
#include <iostream>
#include <iomanip>
#include <time.h>


// direction codes (part of the slideTile() interface)
#define SLIDE_UP		1		// pass to slideTile() to trigger UP movement
#define SLIDE_DOWN		2		// pass to slideTile() to trigger DOWN movement
#define SLIDE_LEFT		3		// pass to slideTile() to trigger LEFT movement
#define SLIDE_RIGHT		4		// pass to slideTile() to trigger RIGHT movement
#define BRUTE_FORCE     999     // pass to inputLoop() to solve with RNG
#define ESC             27

#define UNSET			-1		// used to arbitrarily indicate an undetermined state in a constuct



int main() {
	char keyStroke = ' ';
	int directionCode = UNSET;
	int boardWidth = 0;
	int boardHeight = 0;
	int choice = 0;

	// seed pseudo rng
	srand(time(NULL));

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

	// main game loop
	while (1) {
		directionCode = UNSET;

		puzzle0.printBoard();

		directionCode = puzzle0.gameLoop(directionCode, keyStroke);

		system("cls");

		// win condition check
		if (puzzle0.isBoardSolved()) {
			puzzle0.printBoard();
			std::cout << "\nBoard is solved\n\nTook " << puzzle0.getTotalMoveCount() << " moves\n\n";
			break;
		}
		// allow user to quit
		else if (directionCode == ESC) {
			std::cout << "\nExiting...\n\nGave up after " << puzzle0.getTotalMoveCount() << " moves\n\n";
			break;
		}
	}

	return 0;
}
