#ifndef _MATRIX4_H_
#define _MATRIX4_H_

//standard 4x4 matrix
#pragma once

#include "vector3d.h"

enum E_MATRICES
{
	MATRIX_IDENTITY,
	MATRIX_NONE
};

class matrix4
{
public:
	//constructor
	matrix4(E_MATRICES matrix = MATRIX_IDENTITY)
	{
		for(unsigned i = 0; i < 16; i++)
		{
			m[i] = 0.0f;
		}
		if(matrix == MATRIX_IDENTITY)
		{
			m[0] = 1.0f;
		}

	}
	//copy constructor
	matrix4(const matrix4 &mat)
	{
		for(unsigned i = 0; i < 16; i++)
		{
			m[i] = mat[i];
		}
	}

	//returns an lvalue
	float& operator [] (unsigned index)
	{
		return m[index];
	}
	
	//returns an rvalue
	const float& operator [] (unsigned index) const
	{
		return m[index];
	}
	//sets a position in the matrix
	matrix4& setPosition(const vector3d &pos)
	{
		m[12] = pos.X;
		m[13] = pos.Y;
		m[14] = pos.Z;
		reset();
		return *this;
	}
	matrix4& setRotationFromEuler(const vector3d &rot)
	{
		float cx = cos(rot.X);
		float sx = sin(rot.X);
		float cy = cos(rot.Y);
		float sy = sin(rot.Y);
		float cz = cos(rot.Z);
		float sz = sin(rot.Z);

		m[0] = cy * cz;
		m[1] = cy * sz;
		m[2] = -sy;

		float sxsy = sx * sy;
		float cxsy = cx * sy;

		m[4] = sxsy*cz - cx*cz;
		m[5] = sxsy*sz + cx*cz;
		m[6] = sx*cy;

		m[8] = cxsy * cz + sx * sz;
		m[9] = cxsy * sz - sx * cz;
		m[10] = cx * cy;

		return *this;
	}

	void inverse()
	{
		//basic matrices
		for(unsigned i = 0; i < 16; i++)
		{
			m[i] = -1 * m[i];
		}
		reset();
	}

	matrix4 operator+(const matrix4 &mat) const
	{
		matrix4 temp;
		for(unsigned i = 0; i < 16; i++)
		{
			temp[i] = m[i] + mat[i];
		}
		return temp;
	}
	matrix4 operator+(const float scalar) const
	{
		matrix4 temp;
		for(unsigned i = 0; i < 16; i++)
		{
			temp[i] = m[i] + scalar;
		}
		return temp;
	}
	matrix4 operator-(const matrix4 &mat) const
	{
		matrix4 temp;
		for(unsigned i = 0; i < 16 ; i++)
		{
			temp[i] = m[i] - mat[i];
		}
		return temp;
	}
	matrix4 operator-(const float scalar) const
	{
		matrix4 temp;
		for(unsigned i = 0; i < 16; i++)
		{
			temp[i] = m[i] - scalar;
		}
		return temp;
	}

	matrix4 operator*(const matrix4 &mat)
	{
		//matrix multiplication
		matrix4 m_t;
		m_t[0] = m[0]*mat[0] + m[4]*mat[1] + m[8]*mat[2] + m[12]*mat[3];
		m_t[1] = m[1]*mat[0] + m[5]*mat[1] + m[9]*mat[2] + m[13]*mat[3];
		m_t[2] = m[2]*mat[0] + m[6]*mat[1] + m[10]*mat[2] + m[14]*mat[3];
		m_t[3] = m[3]*mat[0] + m[7]*mat[1] + m[11]*mat[2] + m[15]*mat[3];
 
		m_t[4] = m[0]*mat[4] + m[4]*mat[5] + m[8]*mat[6] + m[12]*mat[7];
		m_t[5] = m[1]*mat[4] + m[5]*mat[5] + m[9]*mat[6] + m[13]*mat[7];
		m_t[6] = m[2]*mat[4] + m[6]*mat[5] + m[10]*mat[6] + m[14]*mat[7];
		m_t[7] = m[3]*mat[4] + m[7]*mat[5] + m[11]*mat[6] + m[15]*mat[7];

		m_t[8] = m[0]*mat[8] + m[4]*mat[9] + m[8]*mat[10] + m[12]*mat[11];
		m_t[9] = m[1]*mat[8] + m[5]*mat[9] + m[9]*mat[10] + m[13]*mat[11];
		m_t[10] = m[2]*mat[8] + m[6]*mat[9] + m[10]*mat[10] + m[14]*mat[11];
		m_t[11] = m[3]*mat[8] + m[7]*mat[9] + m[11]*mat[10] + m[15]*mat[11];

		m_t[12] = m[0]*mat[12] + m[4]*mat[13] + m[8]*mat[14] + m[12]*mat[15];
		m_t[13] = m[1]*mat[12] + m[5]*mat[13] + m[9]*mat[14] + m[13]*mat[15];
		m_t[14] = m[2]*mat[12] + m[6]*mat[13] + m[10]*mat[14] + m[14]*mat[15];
		m_t[15] = m[3]*mat[12] + m[7]*mat[13] + m[11]*mat[14] + m[15]*mat[15];

		
		return m_t;
	}

	matrix4 multiply(const float scalar)
	{
		matrix4 temp;
		for(unsigned i = 0; i < 16; i++)
		{
			temp[i] = scalar * m[i];
		}
		reset();
		return temp;
	}

	matrix4 multiply(const matrix4 &mat)
	{
		//matrix multiplication
		matrix4 m_t;
		m_t[0] = m[0]*mat[0] + m[4]*mat[1] + m[8]*mat[2] + m[12]*mat[3];
		m_t[1] = m[1]*mat[0] + m[5]*mat[1] + m[9]*mat[2] + m[13]*mat[3];
		m_t[2] = m[2]*mat[0] + m[6]*mat[1] + m[10]*mat[2] + m[14]*mat[3];
		m_t[3] = m[3]*mat[0] + m[7]*mat[1] + m[11]*mat[2] + m[15]*mat[3];
 
		m_t[4] = m[0]*mat[4] + m[4]*mat[5] + m[8]*mat[6] + m[12]*mat[7];
		m_t[5] = m[1]*mat[4] + m[5]*mat[5] + m[9]*mat[6] + m[13]*mat[7];
		m_t[6] = m[2]*mat[4] + m[6]*mat[5] + m[10]*mat[6] + m[14]*mat[7];
		m_t[7] = m[3]*mat[4] + m[7]*mat[5] + m[11]*mat[6] + m[15]*mat[7];

		m_t[8] = m[0]*mat[8] + m[4]*mat[9] + m[8]*mat[10] + m[12]*mat[11];
		m_t[9] = m[1]*mat[8] + m[5]*mat[9] + m[9]*mat[10] + m[13]*mat[11];
		m_t[10] = m[2]*mat[8] + m[6]*mat[9] + m[10]*mat[10] + m[14]*mat[11];
		m_t[11] = m[3]*mat[8] + m[7]*mat[9] + m[11]*mat[10] + m[15]*mat[11];

		m_t[12] = m[0]*mat[12] + m[4]*mat[13] + m[8]*mat[14] + m[12]*mat[15];
		m_t[13] = m[1]*mat[12] + m[5]*mat[13] + m[9]*mat[14] + m[13]*mat[15];
		m_t[14] = m[2]*mat[12] + m[6]*mat[13] + m[10]*mat[14] + m[14]*mat[15];
		m_t[15] = m[3]*mat[12] + m[7]*mat[13] + m[11]*mat[14] + m[15]*mat[15];

		
		return m_t;
	}

	

	//assignment operator
	matrix4 &operator = (const matrix4 &mat)
	{
		for(unsigned i = 0; i < 16; i++)
		{
			m[i] = mat[i];
		}
		return *this;
	}


	//matrix
	//we'll graph out what each aligns to
	//opengl uses columns though
	// [ 0][ 4][ 8][12]
	// [ 1][ 5][ 9][13]
	// [ 2][ 6][10][14]
	// [ 3][ 7][11][15]
	float m[16];

private:
	void reset()
	{
		m[5] = 1.0f;
		m[10] = -1.0f;
		m[15] = 1.0f;
	}
};

#endif