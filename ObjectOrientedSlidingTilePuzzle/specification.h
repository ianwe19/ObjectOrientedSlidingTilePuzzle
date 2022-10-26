#ifndef __SLIDINGPUZZLE__
#define __SLIDINGPUZZLE__


class SlidingPuzzle {
private:
	int** theBoard;

public:
	SlidingPuzzle();
	SlidingPuzzle(int, int);

	void initializeBoard();
	bool isBoardSolved();
	bool slideTile(int);
	void scrambleBoard();
	void printBoard();
};
#endif