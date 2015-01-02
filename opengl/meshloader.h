#ifndef _MESHLOADER_H_
#define _MESHLOADER_H_

#pragma once

#include "mesh.h"
#include "fstream"
#include "vector"
#include "string"
#include "iostream"
#include "sstream"
#include "vector3d.h"

using namespace std;

class CMeshLoader
{
public:
	CMeshLoader();
	~CMeshLoader();

	CMesh *loadOBJ(const char *file);
};

#endif
