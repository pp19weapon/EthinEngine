#pragma once
#include <math.h>


class Vector2D
{
public:
	Vector2D(float x, float y)
		: mX(x)
		, mY(y)
	{}

	Vector2D()
		: mX(0)
		, mY(0)
	{}
	
	float getX() { return mX; }
	float getY() { return mY; }

	void setX(float x) { mX = x; }
	void setY(float y) { mY = y; }

	float lenght() { return sqrt(mX * mX + mY * mY); }

	SDL_Point toSDLPoint() {
		return SDL_Point{ (int)mX, (int)mY };
	}

	Vector2D operator+(const Vector2D &v2) const {
		return Vector2D(mX + v2.mX, mY + v2.mY);
	}

	friend Vector2D& operator+=(Vector2D &v1, const Vector2D &v2) {
		v1.mX += v2.mX;
		v1.mY += v2.mY;
		return v1;
	}

	Vector2D operator*(float scalar) {
		return Vector2D(mX*scalar, mY*scalar);
	}

	Vector2D& operator*=(float scalar) {
		mX *= scalar;
		mY *= scalar;
		return *this;
	}

	Vector2D operator-(const Vector2D &v2) const {
		return Vector2D(mX - v2.mX, mY - v2.mY);
	}
	friend Vector2D& operator-=(Vector2D &v1, const Vector2D &v2) {
		v1.mX -= v2.mX;
		v1.mY -= v2.mY;
		return v1;
	}

	Vector2D operator/(float scalar) {
		return Vector2D(mX / scalar, mY / scalar);
	}
	Vector2D &operator/=(float scalar) {
		mX /= scalar;
		mY /= scalar;
		return *this;
	}

	friend bool operator==(Vector2D v1, Vector2D v2) {
		if ((v1.getX() == v2.getX()) &&
			(v1.getY() == v2.getY())) {
			return true;
		}
		return false;
	}

	void normalize() {
		float l = lenght();
		if (l > 0) {
			(*this) *= 1 / l;
		}
	}

private:
	float mX;
	float mY;
};

