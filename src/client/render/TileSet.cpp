#include "TileSet.h"
#include <iostream>

using namespace std;
using namespace render;


TileSet::TileSet(std::string path)
{
	this->path = path;
}
 
bool TileSet::loadTexture()
{
	
	bool result;
	


	result = this->textureTileSet.loadFromFile(path);
	//charge tout le temps la meme tile
	// cout << "TileSet: Loaded texture " << &this->textureTileSet
	// 	 << " for path \"" << path << "\" in " << this << endl;

	return result;
}

const sf::Texture& TileSet::getTexture() 
{
	// cout << "TileSet: Requesting texture " << &this->textureTileSet <<
	// 	" from " << this << endl;
	return this->textureTileSet;
}



