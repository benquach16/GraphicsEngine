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

#include "stdafx.h"
#include "imageloader.h"

CImageLoader::CImageLoader()
{
}

CImageLoader::~CImageLoader()
{
}

//loading a bitmap manually
//works
CTexture *CImageLoader::loadBMP(const char *file) const
{

	unsigned short planes;	// number of planes in image (must be 1) 
	unsigned short bpp;			// number of bits per pixel (must be 24)
	int width;
	int height;
	int size;
	unsigned char *data;


	ifstream fin(file, ios::in | ios::binary);
	if(!fin)
		//tried to open a file that didnt exist
		return 0;

	fin.seekg(18, ios::cur);
	fin.read((char*)&width, sizeof(int));
	fin.read((char*)&height, sizeof(int));
	fin.read((char*)&planes, sizeof(unsigned short));
	fin.read((char*)&bpp, sizeof(unsigned short));

	fin.seekg(24, ios::cur);
	size = width * height * 3;				// size of the image in bytes (3 is to RGB component).

	data = new unsigned char[size];
	fin.read((char*)data, size);

	unsigned char tmp;					// temporary color storage for bgr-rgb conversion.

	for( int i = 0; i < size; i += 3 )
	{
		tmp = data[i];
		data[i] = data[i+2];
		data[i+2] = tmp;

		//cout << "RGB(" <<(int)data[i] << ", " << (int)data[i + 1] << ", " << (int)data[i + 2] << ")" << endl;
	}

	CTexture *tex = new CTexture(width, height, data);
	return tex;
}
