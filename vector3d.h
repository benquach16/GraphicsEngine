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

#pragma once

//very simple vector class
class vector3d
{
public:
	//only floats are supported so far
	//overloaded function
	vector3d() : X(0.0f), Y(0.0f), Z(0.0f) {}
	vector3d(float X, float Y, float Z) : X(X), Y(Y), Z(Z) {}

	//basic operator functions
	vector3d operator +(vector3d tmp)
	{
		vector3d t = vector3d(X + tmp.X, Y + tmp.Y, Z + tmp.Z);
		return t;
	}
	vector3d& operator -(vector3d tmp)
	{
		vector3d t = vector3d(X - tmp.X, Y - tmp.Y, Z - tmp.Z);
		return t;
	}
	vector3d& operator +=(vector3d tmp)
	{
		X += tmp.X;
		Y += tmp.Y;
		Z += tmp.Z;
		return *this;
	}
	vector3d& operator -=(vector3d tmp)
	{
		X -= tmp.X;
		Y -= tmp.Y;
		Z -= tmp.Z;
		return *this;
	}
	vector3d& operator =(vector3d tmp)
	{
		X = tmp.X;
		Y = tmp.Y;
		Z = tmp.Z;
		return *this;
	}

	//yes, we allow modification of variables by anyjuan
	float X;
	float Y;
	float Z;
};

#endif