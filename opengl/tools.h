#ifndef _TOOLS_H_
#define _TOOLS_H_


//Ctools class is a utlility class
//used for easy math conversions or other
//useful stuff

#define PI 3.14159

class CTools
{
public:
	static float toRadians(float degrees)
	{
		float t = degrees * PI;
		t = t /180;
		return t;
	}
	static float toDegrees(float radians)
	{
		float t = radians * 180;
		t = t / PI;
		return t;
	}
};

#endif