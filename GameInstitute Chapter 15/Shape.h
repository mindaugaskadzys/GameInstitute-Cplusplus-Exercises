// Shape.h

#ifndef SHAPE_H
#define SHAPE_H

#include <windows.h>

class Shape
{
public:
	Shape(const POINT u, const POINT v, 
		const LOGPEN& lp, const LOGBRUSH& lb);
	
	virtual~Shape();

	void setStartPt(const POINT& p0);
	void setEndPt(const POINT& p1);

	virtual void draw(HDC hdc) = 0;

protected:
	POINT  mPt0;
	POINT  mPt1;
	HPEN   mhPen;
	HBRUSH mhBrush;

	HPEN mhOldPen;
	HBRUSH mhOldBrush;
};

class LineShape : public Shape
{
public:
	LineShape(const POINT u, const POINT v, 
		const LOGPEN& lp, const LOGBRUSH& lb);

	void draw(HDC hdc);
};

class RectShape : public Shape
{
public:
	RectShape(const POINT u, const POINT v, 
		const LOGPEN& lp, const LOGBRUSH& lb);

	void draw(HDC hdc);
};

class EllipseShape : public Shape
{
public:
	EllipseShape(const POINT u, const POINT v, 
		const LOGPEN& lp, const LOGBRUSH& lb);

	void draw(HDC hdc);
};

//Ex 15.9.3 - Cube
class CubeShape : public Shape
{
public:
	CubeShape(const POINT u, const POINT v,
		const LOGPEN& lp, const LOGBRUSH& lb);

	void draw(HDC hdc);
};

#endif // SHAPE_H