#ifndef _VECTOR2D_H_
#define _VECTOR2D_H_

//2d position class
//should be pretty simple
class vector2d
{
public:
	//default constructor
	vector2d(float X = 0, float Y = 0) : X(X), Y(Y) {}
	//copy constructor
	vector2d(const vector2d &v) : X(v.X), Y(v.Y) {}

	//operator functions go here
	vector2d operator + (const vector2d &v)
	{
		vector2d tmp;
		tmp.X = X + v.X;
		tmp.Y = Y + v.Y;
		return tmp;
	}
	vector2d operator - (const vector2d &v)
	{
		vector2d tmp;
		tmp.X = X - v.Y;
		tmp.Y = Y - v.Y;
		return tmp;
	}
	vector2d operator * (const vector2d &v)
	{
		vector2d tmp;
		tmp.X = X * v.Y;
		tmp.Y = Y * v.Y;
		return tmp;
	}
	vector2d& operator = (const vector2d &v)
	{
		X = v.X;
		Y = v.Y;
		return *this;
	}

	float X;
	float Y;
};

#endif