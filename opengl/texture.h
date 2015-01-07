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

#ifndef _TEXTURE_H_
#define _TEXTURE_H_

#pragma once

#include "Resource.h"
#include "gl/gl.h"
#include "gl/glu.h"
#include "iostream"


class CTexture
{
public:
	CTexture(int x, int y, void *pixel_data);
	~CTexture();
	//TODO: make this a protected function
	//dont allow users to get this function
	GLuint getGLTexture();
	int getWidth();
	int getHeight();
private:
	GLuint image;
	int x;
	int y;
};

#endif