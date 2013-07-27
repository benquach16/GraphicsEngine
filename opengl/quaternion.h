#ifndef _QUATERNION_H_
#define _QUATERNION_H_


//engine does not really have that much support for quaternions right now

class quaternion
{
public:
	//default constructor
	quaternion(float W = 0.f,
		float X = 0.f,
		float Y = 0.f,
		float Z = 0.f) : W(W), X(X), Y(Y), Z(Z) {}

	//overloaded constructors
	//quaternion(float W, const vector3d &v) : W(W), X(v.X), Y(v.Y), Z(v.Z) {}
	//quaternion(const vector3d &v) : W(0.f), X(v.X), Y(v.Y), Z(v.Z) {}

	//copy constructor
	quaternion(const quaternion &q) : W(q.W), X(q.X), Y(q.Y), Z(q.Z) {}

	//operator functions
	quaternion operator = (const quaternion &q)
	{
		quaternion tmp;
		tmp.W = q.W;
		tmp.X = q.X;
		tmp.Y = q.Y;
		tmp.Z = q.Z;
		return tmp;
	}



	float W,X,Y,Z;
};


#endif