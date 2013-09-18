/**
 * ResourceManager.cpp
 * File contains definition of ResourceManager class.
 *
 *  Created on: 2010-07-12
 *      Author: Szymon Jab³oñski - Veldrin
 */
#include <iostream>
#include "ResourceManager.h"

using namespace std;

//TODO: wczytywanie resourceów z pliku
ResourceManager::ResourceManager()
{
	loadMapTiles();
	loadPlayerSpriteSheet();
}

ResourceManager::~ResourceManager()
{
	for(int i = 0; i < mapTiles.size(); i++)
		al_destroy_bitmap(mapTiles[i]);

	al_destroy_bitmap(playerSpriteSheet);
}

void ResourceManager::loadMapTiles()
{
	int i = 0;

	mapTiles.push_back(al_load_bitmap("gfx/0.bmp"));
	if (!mapTiles[i++])
	{
		cerr << "Error loading image resources from file!" << endl;
		getchar();
		exit(1);
	}

	mapTiles.push_back(al_load_bitmap("gfx/1.bmp"));
	if (!mapTiles[i++])
	{
		cerr << "Error loading image resources from file!" << endl;
		getchar();
		exit(1);
	}

	mapTiles.push_back(al_load_bitmap("gfx/2.bmp"));
	if (!mapTiles[i++])
	{
		cerr << "Error loading image resources from file!" << endl;
		getchar();
		exit(1);
	}

	mapTiles.push_back(al_load_bitmap("gfx/3.bmp"));
	if (!mapTiles[i++])
	{
		cerr << "Error loading image resources from file!" << endl;
		getchar();
		exit(1);
	}

	mapTiles.push_back(al_load_bitmap("gfx/4.bmp"));
	if (!mapTiles[i++])
	{
		cerr << "Error loading image resources from file!" << endl;
		getchar();
		exit(1);
	}

	mapTiles.push_back(al_load_bitmap("gfx/5.bmp"));
	if (!mapTiles[i++])
	{
		cerr << "Error loading image resources from file!" << endl;
		getchar();
		exit(1);
	}

	mapTiles.push_back(al_load_bitmap("gfx/6.bmp"));
	if (!mapTiles[i++])
	{
		cerr << "Error loading image resources from file!" << endl;
		getchar();
		exit(1);
	}

	mapTiles.push_back(al_load_bitmap("gfx/7.bmp"));
	if (!mapTiles[i++])
	{
		cerr << "Error loading image resources from file!" << endl;
		getchar();
		exit(1);
	}

	mapTiles.push_back(al_load_bitmap("gfx/8.bmp"));
	if (!mapTiles[i++])
	{
		cerr << "Error loading image resources from file!" << endl;
		getchar();
		exit(1);
	}

	mapTiles.push_back(al_load_bitmap("gfx/9.bmp"));
	if (!mapTiles[i++])
	{
		cerr << "Error loading image resources from file!" << endl;
		getchar();
		exit(1);
	}
	
	mapTiles.push_back(al_load_bitmap("gfx/10.bmp"));
	if (!mapTiles[i++])
	{
		cerr << "Error loading image resources from file!" << endl;
		getchar();
		exit(1);
	}
	
	mapTiles.push_back(al_load_bitmap("gfx/11.bmp"));
	if (!mapTiles[i++])
	{
		cerr << "Error loading image resources from file!" << endl;
		getchar();
		exit(1);
	}
	
	mapTiles.push_back(al_load_bitmap("gfx/12.bmp"));
	if (!mapTiles[i++])
	{
		cerr << "Error loading image resources from file!" << endl;
		getchar();
		exit(1);
	}
	
	mapTiles.push_back(al_load_bitmap("gfx/13.bmp"));
	if (!mapTiles[i++])
	{
		cerr << "Error loading image resources from file!" << endl;
		getchar();
		exit(1);
	}
	
	mapTiles.push_back(al_load_bitmap("gfx/14.bmp"));
	if (!mapTiles[i++])
	{
		cerr << "Error loading image resources from file!" << endl;
		getchar();
		exit(1);
	}
	
	mapTiles.push_back(al_load_bitmap("gfx/15.bmp"));
	if (!mapTiles[i++])
	{
		cerr << "Error loading image resources from file!" << endl;
		getchar();
		exit(1);
	}

	mapTiles.push_back(al_load_bitmap("gfx/16.bmp"));
	if (!mapTiles[i++])
	{
		cerr << "Error loading image resources from file!" << endl;
		getchar();
		exit(1);
	}

	mapTiles.push_back(al_load_bitmap("gfx/17.bmp"));
	if (!mapTiles[i++])
	{
		cerr << "Error loading image resources from file!" << endl;
		getchar();
		exit(1);
	}

	mapTiles.push_back(al_load_bitmap("gfx/18.bmp"));
	if (!mapTiles[i++])
	{
		cerr << "Error loading image resources from file!" << endl;
		getchar();
		exit(1);
	}

	mapTiles.push_back(al_load_bitmap("gfx/19.bmp"));
	if (!mapTiles[i++])
	{
		cerr << "Error loading image resources from file!" << endl;
		getchar();
		exit(1);
	}

	mapTiles.push_back(al_load_bitmap("gfx/20.bmp"));
	if (!mapTiles[i++])
	{
		cerr << "Error loading image resources from file!" << endl;
		getchar();
		exit(1);
	}

	mapTiles.push_back(al_load_bitmap("gfx/21.bmp"));
	if (!mapTiles[i++])
	{
		cerr << "Error loading image resources from file!" << endl;
		getchar();
		exit(1);
	}

	mapTiles.push_back(al_load_bitmap("gfx/22.bmp"));
	if (!mapTiles[i++])
	{
		cerr << "Error loading image resources from file!" << endl;
		getchar();
		exit(1);
	}

	mapTiles.push_back(al_load_bitmap("gfx/23.bmp"));
	if (!mapTiles[i++])
	{
		cerr << "Error loading image resources from file!" << endl;
		getchar();
		exit(1);
	}

	mapTiles.push_back(al_load_bitmap("gfx/24.bmp"));
	if (!mapTiles[i++])
	{
		cerr << "Error loading image resources from file!" << endl;
		getchar();
		exit(1);
	}

	mapTiles.push_back(al_load_bitmap("gfx/25.bmp"));
	if (!mapTiles[i++])
	{
		cerr << "Error loading image resources from file!" << endl;
		getchar();
		exit(1);
	}

	mapTiles.push_back(al_load_bitmap("gfx/26.bmp"));
	if (!mapTiles[i++])
	{
		cerr << "Error loading image resources from file!" << endl;
		getchar();
		exit(1);
	}

	mapTiles.push_back(al_load_bitmap("gfx/27.bmp"));
	if (!mapTiles[i++])
	{
		cerr << "Error loading image resources from file!" << endl;
		getchar();
		exit(1);
	}

	mapTiles.push_back(al_load_bitmap("gfx/28.bmp"));
	if (!mapTiles[i++])
	{
		cerr << "Error loading image resources from file!" << endl;
		getchar();
		exit(1);
	}

	mapTiles.push_back(al_load_bitmap("gfx/29.bmp"));
	if (!mapTiles[i++])
	{
		cerr << "Error loading image resources from file!" << endl;
		getchar();
		exit(1);
	}
	mapTiles.push_back(al_load_bitmap("gfx/30.bmp"));
	if (!mapTiles[i++])
	{
		cerr << "Error loading image resources from file!" << endl;
		getchar();
		exit(1);
	}
	mapTiles.push_back(al_load_bitmap("gfx/31.bmp"));
	if (!mapTiles[i++])
	{
		cerr << "Error loading image resources from file!" << endl;
		getchar();
		exit(1);
	}
	mapTiles.push_back(al_load_bitmap("gfx/32.bmp"));
	if (!mapTiles[i++])
	{
		cerr << "Error loading image resources from file!" << endl;
		getchar();
		exit(1);
	}
	mapTiles.push_back(al_load_bitmap("gfx/33.bmp"));
	if (!mapTiles[i++])
	{
		cerr << "Error loading image resources from file!" << endl;
		getchar();
		exit(1);
	}
	mapTiles.push_back(al_load_bitmap("gfx/34.bmp"));
	if (!mapTiles[i++])
	{
		cerr << "Error loading image resources from file!" << endl;
		getchar();
		exit(1);
	}
	mapTiles.push_back(al_load_bitmap("gfx/35.bmp"));
	if (!mapTiles[i++])
	{
		cerr << "Error loading image resources from file!" << endl;
		getchar();
		exit(1);
	}
	mapTiles.push_back(al_load_bitmap("gfx/36.bmp"));
	if (!mapTiles[i++])
	{
		cerr << "Error loading image resources from file!" << endl;
		getchar();
		exit(1);
	}
	mapTiles.push_back(al_load_bitmap("gfx/37.bmp"));
	if (!mapTiles[i++])
	{
		cerr << "Error loading image resources from file!" << endl;
		getchar();
		exit(1);
	}
	mapTiles.push_back(al_load_bitmap("gfx/38.bmp"));
	if (!mapTiles[i++])
	{
		cerr << "Error loading image resources from file!" << endl;
		getchar();
		exit(1);
	}
	mapTiles.push_back(al_load_bitmap("gfx/39.bmp"));
	if (!mapTiles[i++])
	{
		cerr << "Error loading image resources from file!" << endl;
		getchar();
		exit(1);
	}
	mapTiles.push_back(al_load_bitmap("gfx/40.bmp"));
	if (!mapTiles[i++])
	{
		cerr << "Error loading image resources from file!" << endl;
		getchar();
		exit(1);
	}
	mapTiles.push_back(al_load_bitmap("gfx/41.bmp"));
	if (!mapTiles[i++])
	{
		cerr << "Error loading image resources from file!" << endl;
		getchar();
		exit(1);
	}
}


void ResourceManager::loadPlayerSpriteSheet()
{
	playerSpriteSheet = al_load_bitmap("gfx/marioSprite.bmp");
	if (!playerSpriteSheet)
	{
		cerr << "HAHAH Error loading image resources from file!" << endl;
		getchar();
		exit(1);
	}
	al_convert_mask_to_alpha(playerSpriteSheet, al_map_rgb(255,0,128));
}


ALLEGRO_BITMAP* ResourceManager::getPlayerSpriteSheet()
{
	return playerSpriteSheet;
}

ALLEGRO_BITMAP* ResourceManager::getTileByID(int tileID)
{
	return mapTiles[tileID];
}