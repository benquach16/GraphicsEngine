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

#ifndef _IMAGELOADER_H_
#define _IMAGELOADER_H_

#include "Resource.h"
#include "gl/gl.h"
#include "gl/glu.h"
#include "iostream"
#include "texture.h"
#include "fstream"
#include "cstdlib"


using namespace std;


class CImageLoader
{
public:
	CImageLoader();
	~CImageLoader();
	CTexture *loadBMP(const char *file);
	//Not sure if actually should implement
	//might do it for the lulz
	CTexture *loadBEN(const char *file);
	CTexture *loadPNG(const char *file);
	CTexture *loadTGA(const char *file);
};

#endif