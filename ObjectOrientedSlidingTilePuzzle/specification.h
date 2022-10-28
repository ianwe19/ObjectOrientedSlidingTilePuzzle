#ifndef __SLIDINGPUZZLE__
#define __SLIDINGPUZZLE__


class SlidingPuzzle {
private:
	int** theBoard;
	int boardWidth;
	int boardHeight;
	int pivotNum;
	int totalMoveCount;

public:
	SlidingPuzzle();
	SlidingPuzzle(int, int);
	~SlidingPuzzle();

	void initializeBoard();
	bool isBoardSolved();
	bool slideTile(int);
	void scrambleBoard();
	void printBoard();
	void randomMove();
};
#endif