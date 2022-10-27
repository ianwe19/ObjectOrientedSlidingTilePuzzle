#include "specification.h"
#include <iostream>
#include <iomanip>

	
#define PIVOT           NUM_ROWS * NUM_COLS // highest number on board to be changed to *
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
	this->boardWidth = 3;
	this->boardHeight = 3;
	this->pivotNum = 9;

	this->theBoard = new(int* [3]);

	for (int i = 0; i < 3; i++) {
		this->theBoard[i] = new(int[3]);
	}
}

SlidingPuzzle::SlidingPuzzle(int width, int height) {
	this->boardWidth = width;
	this->boardHeight = height;
	this->pivotNum = width * height;

	this->theBoard = new(int* [this->boardHeight]);

	for (int i = 0; i < this->boardHeight; i++) {
		this->theBoard[i] = new(int[this->boardHeight]);
	}
}

SlidingPuzzle::~SlidingPuzzle() {
	// dealloc memory from each array in ptr array
	for (int i = 0; i < this->boardHeight; i++) {
		delete[] this->theBoard[i];
	}

	// dealloc ptr array
	delete[] this->theBoard;
}

void SlidingPuzzle::initializeBoard() {
	int counter = 1;

	for (int i = 0; i < this->boardHeight; i++) {
		for (int j = 0; j < this->boardWidth; j++) {
			this->theBoard[i][j] = counter;
			counter++;
		}
	}
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


	for (i = 0; i < this->boardHeight; i++) {
		for (j = 0; j < this->boardWidth; j++) {
			if (theBoard[i][j] == this->pivotNum) {
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
