//////////////////////////////////////////////////////////////////////
///Copyright (C) 2012 Benjamin Quach
//
//This file is part of bengine
//
//This program is free software: you can redistribute it and/or modify
//it under the terms of the GNU General Public License as published by
//the Free Software Foundation, either version 3 of the License, or
//(at your option) any later version.
//
//This program is distributed in the hope that it will be useful,
//but WITHOUT ANY WARRANTY; without even the implied warranty of
//MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//GNU General Public License for more details.
//
//You should have received a copy of the GNU General Public License
//along with this program.  If not, see <http://www.gnu.org/licenses/>.
//
///////////////////////////////////////////////////////////////////////

#ifndef _VECTOR3D_H_
#define _VECTOR3D_H_

#include "quaternion.h"
#include "tools.h"
#include "cmath"

#pragma once

//very simple vector class
class vector3d
{
public:
	//only floats are supported so far
	//overloaded function
	vector3d() : X(0.0f), Y(0.0f), Z(0.0f) {}
	vector3d(float X, float Y, float Z) : X(X), Y(Y), Z(Z) {}
	//copy constructor
	vector3d(const vector3d &v) : X(v.X), Y(v.Y), Z(v.Z) {}

	//basic overloaded operator functions
	vector3d operator +(const vector3d &tmp) const
	{
		vector3d t = vector3d(X + tmp.X, Y + tmp.Y, Z + tmp.Z);
		return t;
	}
	vector3d operator +(const float &tmp) const
	{
		vector3d t = vector3d(X + tmp, Y + tmp, Z + tmp);
		return t;
	}
	vector3d operator -(const vector3d &tmp) const
	{
		vector3d t = vector3d(X - tmp.X, Y - tmp.Y, Z - tmp.Z);
		return t;
	}
	vector3d operator -(const float &tmp) const
	{
		vector3d t = vector3d(X - tmp, Y - tmp, Z - tmp);
		return t;
	}
	vector3d operator *(const vector3d &tmp) const
	{
		vector3d t = vector3d(X * tmp.X, Y * tmp.Y, Z * tmp.Z);
		return t;
	}
	vector3d operator *(const float &tmp) const
	{
		vector3d t = vector3d(X * tmp, Y * tmp, Z *tmp);
		return t;
	}
	vector3d& operator +=(const vector3d &tmp)
	{
		X += tmp.X;
		Y += tmp.Y;
		Z += tmp.Z;
		return *this;
	}
	vector3d& operator -=(const vector3d &tmp)
	{
		X -= tmp.X;
		Y -= tmp.Y;
		Z -= tmp.Z;
		return *this;
	}
	vector3d& operator =(const vector3d &tmp)
	{
		X = tmp.X;
		Y = tmp.Y;
		Z = tmp.Z;
		return *this;
	}
	vector3d& operator *=(const vector3d &tmp)
	{
		X *= tmp.X;
		Y *= tmp.Y;
		Z *= tmp.Z;
		return *this;
	}
	vector3d& operator *= (const float &tmp)
	{
		X *= tmp;
		Y *= tmp;
		Z *= tmp;
		return *this;
	}

	quaternion convertToQuaternion()
	{
		float rad_x = CTools::toRadians(X);
		float rad_y = CTools::toRadians(Y);
		float rad_z = CTools::toRadians(Z);
		
		float c1 = cos(rad_x/2);
		float s1 = sin(rad_x/2);
		float c2 = cos(rad_y/2);
		float s2 = sin(rad_y/2);
		float c3 = cos(rad_z/2);
		float s3 = sin(rad_z/2);

		//need to convert back into degrees cause opengl uses it
		c1 = CTools::toDegrees(c1);
		s1 = CTools::toDegrees(s1);
		c2 = CTools::toDegrees(c2);
		s2 = CTools::toDegrees(s2);
		c3 = CTools::toDegrees(c3);
		s3 = CTools::toDegrees(s3);

		float c1c2 = c1 * c2;
		float s1s2 = s1 * s2;

		float w =c1c2*c3 - s1s2*s3;
		float x =c1c2*s3 + s1s2*c3;
		float y =s1*c2*c3 + c1*s2*s3;
		float z =c1*s2*c3 - s1*c2*s3;

		quaternion tmp(w,x,y,z);
		return tmp;
	}

	//yes, we allow modification of variables by anyjuan
	float X;
	float Y;
	float Z;
};

#endif