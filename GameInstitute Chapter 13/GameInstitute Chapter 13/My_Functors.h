#pragma once
#include <random>

//Print functor
template<typename T>
class Print
{
public:
	void operator()(T t)
	{
		cout << t << " ";
	}
};

//Random functor
class Random
{
public:
	Random(int low, int high)
		: mLow(low), mHigh(high)
	{
	}
	int operator()()
	{
		return mLow + rand() % (mHigh - mLow + 1);
	}
private:
	int mLow;
	int mHigh;
};