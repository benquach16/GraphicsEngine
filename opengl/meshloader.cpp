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
#include "meshloader.h"


CMeshLoader::CMeshLoader()
{
}

CMesh *CMeshLoader::loadOBJ(const char *file)
{
	std::ifstream fin(file,ios::in);
	if(!fin)
		return 0;
	

	vector<vector3d> vertex_indices;
	vector<vector3d> normals;

	string line;
	while(getline(fin, line))
	{
		if(line.substr(0,2) == "v ")
		{
			//vertex information
			istringstream s(line.substr(2));
			vector3d v;
			s >> v.X;
			s >> v.Y;
			s >> v.Z;
			vertex_indices.push_back(v);
		}
		if(line.substr(0,2) == "f ")
		{
		}
		if(line[0] == '#')
		{
			//.obj comment
			//so we ignore it
		}
	}
}
