#ifndef _COLOR_H_
#define _COLOR_H_

#pragma once

#define MAX_RGB 255

class color
{
public:
	color() : R(255) , G(255) , B(255) , A(255) {}
	color(float R, float G, float B, float A) : R(R),
		G(G), B(B), A(A) {}

	void setColor(const color &new_color)
	{
		R = new_color.R;
		G = new_color.G;
		B = new_color.B;
		A = new_color.A;
	}

	color& operator=(const color &new_color)
	{
		R = new_color.R;
		G = new_color.G;
		B = new_color.B;
		A = new_color.A;
		return *this;
	}

	float getClampedR() const
	{
		return R / MAX_RGB;
	}
	float getClampedG() const 
	{
		return G / MAX_RGB;
	}
	float getClampedB() const
	{
		return B / MAX_RGB;
	}
	float getClampedA() const
	{
		return A / MAX_RGB;
	}


	float R;
	float G;
	float B;
	float A;
};


#endif