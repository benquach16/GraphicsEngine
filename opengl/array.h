#ifndef _ARRAY_H_
#define _ARRAY_H_

#pragma once

//custom vector so we dont have to use the stl lib

template<class T>
class CArray
{
public:
	//default constructor
	CArray();
	void push_back(T d);

private:
	T *data;
};




#endif