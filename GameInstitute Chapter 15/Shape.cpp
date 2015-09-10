// Shape.cpp

#include "Shape.h"

Shape::Shape(const POINT u, const POINT v, 
			 const LOGPEN& lp, const LOGBRUSH& lb)
{
	mPt0.x = u.x;
	mPt0.y = u.y;
	mPt1.x = v.x;
	mPt1.y = v.y;
	mhPen   = CreatePenIndirect(&lp);
	mhBrush = CreateBrushIndirect(&lb);

	mhOldPen   = 0;
	mhOldBrush = 0;
}

Shape::~Shape()
{
	DeleteObject(mhPen);
	DeleteObject(mhBrush);
}

void Shape::setStartPt(const POINT& p0)
{
	mPt0 = p0;
}

void Shape::setEndPt(const POINT& p1)
{
	mPt1 = p1;
}

LineShape::LineShape(const POINT u, const POINT v, 
		             const LOGPEN& lp, const LOGBRUSH& lb)
					 : Shape(u, v, lp, lb)
{
}

void LineShape::draw(HDC hdc)
{
	// Select the current pen and brush.
	mhOldPen   = (HPEN)SelectObject(hdc, mhPen);
	mhOldBrush = (HBRUSH)SelectObject(hdc, mhBrush);

	// Draw the line.
	MoveToEx(hdc, mPt0.x, mPt0.y, 0);
	LineTo(hdc, mPt1.x, mPt1.y);

	// Restore the old pen and brush.
	SelectObject(hdc, mhOldPen);
	SelectObject(hdc, mhOldBrush);
}

RectShape::RectShape(const POINT u, const POINT v, 
		             const LOGPEN& lp, const LOGBRUSH& lb)
					 : Shape(u, v, lp, lb)
{
}

void RectShape::draw(HDC hdc)
{
	// Select the current pen and brush.
	mhOldPen   = (HPEN)SelectObject(hdc, mhPen);
	mhOldBrush = (HBRUSH)SelectObject(hdc, mhBrush);

	// Draw the rectangle.
	Rectangle(hdc, mPt0.x, mPt0.y, mPt1.x, mPt1.y);

	// Restore the old pen and brush.
	SelectObject(hdc, mhOldPen);
	SelectObject(hdc, mhOldBrush);
}

EllipseShape::EllipseShape(const POINT u, const POINT v, 
		                   const LOGPEN& lp, const LOGBRUSH& lb)
						   : Shape(u, v, lp, lb)
{
}

void EllipseShape::draw(HDC hdc)
{
	// Select the current pen and brush.
	mhOldPen   = (HPEN)SelectObject(hdc, mhPen);
	mhOldBrush = (HBRUSH)SelectObject(hdc, mhBrush);

	// Draw the ellipse.
	Ellipse(hdc, mPt0.x, mPt0.y, mPt1.x, mPt1.y);

	// Restore the old pen and brush.
	SelectObject(hdc, mhOldPen);
	SelectObject(hdc, mhOldBrush);
}

//Ex 15.9.3 - Cube
CubeShape::CubeShape(const POINT u, const POINT v,
	const LOGPEN& lp, const LOGBRUSH& lb)
	: Shape(u, v, lp, lb)
{
}

//Ex 15.9.3 - Cube
void drawCubeRect(HDC hdc, const POINT mPt0, const POINT mPt1)
{
	//draw a rectangle from 4 lines
	//top line
	MoveToEx(hdc, mPt0.x, mPt0.y, 0);
	LineTo(hdc, mPt1.x, mPt0.y);
	//bottom line
	MoveToEx(hdc, mPt0.x, mPt1.y, 0);
	LineTo(hdc, mPt1.x, mPt1.y);
	//left line
	MoveToEx(hdc, mPt0.x, mPt0.y, 0);
	LineTo(hdc, mPt0.x, mPt1.y);
	//right line
	MoveToEx(hdc, mPt1.x, mPt0.y, 0);
	LineTo(hdc, mPt1.x, mPt1.y);

}

//Ex 15.9.3 - Cube
void CubeShape::draw(HDC hdc)
{
	// Select the current pen and brush.
	mhOldPen = (HPEN)SelectObject(hdc, mhPen);
	mhOldBrush = (HBRUSH)SelectObject(hdc, mhBrush);

	// Draw the cube. 12 Lines as per specification
	// Perspective as a percentage of cube size
	drawCubeRect(hdc, mPt0, mPt1);
	//determine offset of second rect
	int offsetX = (mPt1.x - mPt0.x)*0.3;
	int offsetY = (mPt1.y - mPt0.y)*0.3;

	//determine the back rectangle position of the cube
	POINT mPt2 = mPt0;
	POINT mPt3 = mPt1;
	mPt2.x += offsetX;
	mPt2.y -= offsetY;
	mPt3.x += offsetX;
	mPt3.y -= offsetY;

	//draw the back rectangle
	drawCubeRect(hdc, mPt2, mPt3);

	//draw the connecting lines
	//top left
	MoveToEx(hdc, mPt0.x, mPt0.y, 0);
	LineTo(hdc, mPt2.x, mPt2.y);
	//top right
	MoveToEx(hdc, mPt1.x, mPt0.y, 0);
	LineTo(hdc, mPt3.x, mPt2.y);
	//bottom left
	MoveToEx(hdc, mPt0.x, mPt1.y, 0);
	LineTo(hdc, mPt2.x, mPt3.y);
	//bottom right
	MoveToEx(hdc, mPt1.x, mPt1.y, 0);
	LineTo(hdc, mPt3.x, mPt3.y);

	// Restore the old pen and brush.
	SelectObject(hdc, mhOldPen);
	SelectObject(hdc, mhOldBrush);
}