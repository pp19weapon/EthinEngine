#pragma once
#include <SDL.h>
#include "Vector2D.h"


class Rectangle
{
public:
	//pos int x int y :: size int w int h
	Rectangle(Vector2D pos, Vector2D size)
		: mX (pos.getX())
		, mY (pos.getY())
		, mW (size.getX())
		, mH (size.getY())
	{};

	Rectangle(float x, float y, float w, float h)
		: mX(x)
		, mY(y)
		, mW(w)
		, mH(h)
	{};

	friend bool operator==(Rectangle &r1, Rectangle &r2) {
		if ((r1.getX() == r2.getX()) &&
			(r1.getY() == r2.getY()) &&
			(r1.getW() == r2.getW()) &&
			(r1.getH() == r2.getH())) {
			return true;
		};
		return false;
	}

	float getX() { return mX; }
	float getY() { return mY; }
	float getW() { return mW; }
	float getH() { return mH; }

	void setX(float x) { mX = x; }
	void setY(float y) { mY = y; }
	void setW(float w) { mW = w; }
	void setH(float h) { mH = h; }

	SDL_Rect convertToSDLRect() {
		return SDL_Rect{ (int)mX, (int)mY, (int)mW, (int)mH };
	}

	bool hasIntersection(Rectangle rect) {
		if (SDL_HasIntersection(&convertToSDLRect(), &rect.convertToSDLRect())) {
			return true;
		}
		else {
			return false;
		}
	}


	//Returns true if vector resides inside a rectangle.
	bool contain(Vector2D point) {
		SDL_bool b = SDL_PointInRect(&point.toSDLPoint(), &convertToSDLRect());
		if (b == SDL_TRUE) {
			return true;
		}
		return false;
	}

private:
	float mX = 0;
	float mY = 0;
	float mW = 0;
	float mH = 0;
};