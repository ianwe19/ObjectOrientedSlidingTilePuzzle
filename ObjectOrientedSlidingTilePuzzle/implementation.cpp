#include "specification.h"
#include <iostream>
#include <iomanip>


#define NUM_ROWS		3		
#define NUM_COLS		3		
#define PIVOT         NUM_ROWS * NUM_COLS // highest number on board to be changed to *
#define NUM_SCRAMBLE    1000000 // number of times to scramble board

#define PIVOT_SYMBOL	"*"		// used to show the pivot location when drawing the board

// direction codes (part of the slideTile() interface)
#define SLIDE_UP		1		// pass to slideTile() to trigger UP movement
#define SLIDE_DOWN		2		// pass to slideTile() to trigger DOWN movement
#define SLIDE_LEFT		3		// pass to slideTile() to trigger LEFT movement
#define SLIDE_RIGHT		4		// pass to slideTile() to trigger RIGHT movement
#define BRUTE_FORCE     999     // pass to inputLoop() to solve with RNG

#define UNSET			-1		// used to arbitrarily indicate an undetermined state in a constuct

#define COLOR_DEFAULT	7
#define COLOR_RED		12
#define COLOR_GREEN		10


SlidingPuzzle::SlidingPuzzle() {
	int counter = 1;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			this->theBoard[i][j] = counter;
			counter++;
		}
	}
}

SlidingPuzzle::SlidingPuzzle(int width, int height) {
	int counter = 1;
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			this->theBoard[i][j] = counter;
			counter++;
		}
	}
}

SlidingPuzzle::~SlidingPuzzle() {
	// dealloc memory from each array in ptr array
	for (int i = 0; i < NUM_ROWS; i++) {
		delete[] this->theBoard[i];
	}

	// dealloc ptr array
	delete[] this->theBoard;
}

void SlidingPuzzle::initializeBoard() {

}

bool SlidingPuzzle::isBoardSolved() {
	return false;
}

bool SlidingPuzzle::slideTile(int directionCode) {
	return false;
}

void SlidingPuzzle::scrambleBoard() {

}

void SlidingPuzzle::printBoard() {
	int i, j;
	int counter = 1;


	for (i = 0; i < NUM_ROWS; i++) {
		for (j = 0; j < NUM_COLS; j++) {
			if (theBoard[i][j] == PIVOT) {
				std::cout << std::setw(3) << PIVOT_SYMBOL;
			}
			else {
				if (theBoard[i][j] == counter) {
				}
				else {
				}
				std::cout << std::setw(3) << theBoard[i][j];
			}
			counter++;
		}
		std::cout << "\n";
	}
	std::cout << "\n";
}
