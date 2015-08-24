// Random.cpp

#include "Random.h"
#include <cstdlib>

// Returns a random number in r.
int Random(Range r)
{
	return r.mLow + rand() % ((r.mHigh + 1) - r.mLow);
}

// Returns a random number in [low, high].
int Random(int low, int high)
{
	return low + rand() % ((high + 1) - low);
}
