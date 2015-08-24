#include "Point.h"

// Implementation
Point3::Point3()
{
	mX = mY = mZ = 0.0f;
}
Point3::Point3(float x, float y, float z)
{
	mX = x;
	mY = y;
	mZ = z;
}