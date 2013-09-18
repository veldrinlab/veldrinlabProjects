/**
 * File contains declaration of scene element -  Terrain class.
 * @file    Terrain.hpp
 * @author  Szymon Jab³oñski
 * @date    2010-10-16
 * @version 1.0
 */

#ifndef TERRAIN_HPP
#define TERRAIN_HPP

#include <stdio.h>
#include <fstream>

#include "SceneEntity.hpp"
#include "Shader.hpp"
#include "ResourceManager/ResourceManager.hpp"

using namespace resMan;

namespace engine
{
	
/**
 * Terrain class represents one of the basic World scene elements - terrain. Terrain is generated procedural, by
 * Height Map algorithm. The structure of height map is loaded from *raw file.
 * @remarks all load functions store in ResourceManager.
 */
class Terrain : public SceneEntity
{
private:
	PResource terrainTexture;
	Vertex* verts;
	TextureCoord* coords;
	int terrainMapWidth;
	int terrainMapHeight; 
	int points;
	unsigned int VBOVertices;
	unsigned int VBOTextureCoords;
	int levelOfDetail;
	unsigned char terrainHeightMap[1024][1024];
	Shader shader;

	void loadRawFile(const char* fileName);
	void initializeTerrain();

public:
	Terrain(const char* terrainFileName,const char* textureFileName);
	~Terrain();

	void updateEntity(const float elapsedTime);
	void renderEntity();

};

}
#endif
