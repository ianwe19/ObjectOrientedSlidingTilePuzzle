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

	// seed pseudo rng
	srand(time(NULL));

	SlidingPuzzle puzzle0(6, 6);

	puzzle0.initializeBoard();

	puzzle0.printBoard();

	return 0;
}
