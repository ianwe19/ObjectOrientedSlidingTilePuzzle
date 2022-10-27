#ifndef __SLIDINGPUZZLE__
#define __SLIDINGPUZZLE__


class SlidingPuzzle {
private:
	int** theBoard;
	int boardWidth;
	int boardHeight;
	int pivotNum;

public:
	SlidingPuzzle();
	SlidingPuzzle(int, int);
	~SlidingPuzzle();

	void initializeBoard();
	bool isBoardSolved();
	bool slideTile(int);
	void scrambleBoard();
	void printBoard();
};
#endif