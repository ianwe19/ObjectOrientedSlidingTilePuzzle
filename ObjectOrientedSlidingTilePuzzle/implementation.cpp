#include "specification.h"
#include <iostream>
#include <iomanip>

	
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


// constructor for default board of 3x3
SlidingPuzzle::SlidingPuzzle() {
	this->totalMoveCount = 0;
	this->boardWidth = 3;
	this->boardHeight = 3;
	this->pivotNum = 9;

	this->theBoard = new(int* [3]);

	for (int i = 0; i < 3; i++) {
		this->theBoard[i] = new(int[3]);
	}
}


// constructor for user defined board size
SlidingPuzzle::SlidingPuzzle(int width, int height) {
	this->totalMoveCount = 0;
	this->boardWidth = width;
	this->boardHeight = height;
	this->pivotNum = this->boardWidth * this->boardHeight;

	this->theBoard = new(int* [this->boardHeight]);

	for (int i = 0; i < this->boardHeight; i++) {
		this->theBoard[i] = new(int[this->boardWidth]);
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
	int i, j;
	int counter = 1;

	for (i = 0; i < this->boardHeight; i++) {
		for (j = 0; j < this->boardWidth; j++) {
			if (this->theBoard[i][j] != counter) {
				return false;
				break;
			}
			counter++;
		}
	}
	return true;
}


bool SlidingPuzzle::slideTile(int directionCode) {
	int i, j;
	int pivotRow = int(this->boardHeight);
	int pivotCol = int(this->boardWidth);

	for (i = 0; i < this->boardHeight; i++) {
		for (j = 0; j < this->boardWidth; j++) {
			if (theBoard[i][j] == this->pivotNum) {
				pivotRow = i;
				pivotCol = j;
			}
		}
	}

	if (pivotRow == this->boardHeight - 1 && directionCode == SLIDE_DOWN) { // detect and prevent illegal moves
		directionCode = UNSET;                                     // e.g. if pivot is in top row, prevent moving up
	}
	else if (pivotRow == 0 && directionCode == SLIDE_UP) {
		directionCode = UNSET;
	}
	else if (pivotCol == this->boardWidth - 1 && directionCode == SLIDE_RIGHT) {
		directionCode = UNSET;
	}
	else if (pivotCol == 0 && directionCode == SLIDE_LEFT) {
		directionCode = UNSET;
	}

	switch (directionCode) {
	case SLIDE_UP:
		this->theBoard[pivotRow][pivotCol] = this->theBoard[pivotRow - 1][pivotCol];
		this->theBoard[pivotRow - 1][pivotCol] = this->pivotNum;
		break;
	case SLIDE_DOWN:
		this->theBoard[pivotRow][pivotCol] = this->theBoard[pivotRow + 1][pivotCol];
		this->theBoard[pivotRow + 1][pivotCol] = this->pivotNum;
		break;
	case SLIDE_LEFT:
		this->theBoard[pivotRow][pivotCol] = this->theBoard[pivotRow][pivotCol - 1];
		this->theBoard[pivotRow][pivotCol - 1] = this->pivotNum;
		break;
	case SLIDE_RIGHT:
		this->theBoard[pivotRow][pivotCol] = this->theBoard[pivotRow][pivotCol + 1];
		this->theBoard[pivotRow][pivotCol + 1] = this->pivotNum;
		break;
	case UNSET: // unset if illegal move
		return false;
	}
	return true;
}


void SlidingPuzzle::scrambleBoard() {

}


void SlidingPuzzle::printBoard() {
	int i, j;

	int counter = 1;

	for (i = 0; i < this->boardHeight; i++) {
		for (j = 0; j < this->boardWidth; j++) {
			if (this->theBoard[i][j] == this->pivotNum) {
				std::cout << std::setw(4) << PIVOT_SYMBOL;
			}
			else {
				if (this->theBoard[i][j] == counter) {
					// color stuff here
				}
				else {
				}
				std::cout << std::setw(4) << this->theBoard[i][j];
			}
			counter++;
		}
		std::cout << "\n\n";
	}
	std::cout << "\n";
}

void SlidingPuzzle::randomMove() {
	switch (rand() % 4 + 1) {

	case 1:
		slideTile(SLIDE_UP);
		break;
	case 2:
		slideTile(SLIDE_DOWN);
		break;
	case 3:
		slideTile(SLIDE_LEFT);
		break;
	case 4:
		slideTile(SLIDE_RIGHT);
		break;
	}
}
