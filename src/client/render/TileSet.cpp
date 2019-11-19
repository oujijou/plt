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
	cout << "TileSet: Loaded texture " << &this->textureTileSet
		 << " for path \"" << path << "\" in " << this << endl;

	return result;
}

const sf::Texture& TileSet::getTexture() 
{
	cout << "TileSet: Requesting texture " << &this->textureTileSet <<
		" from " << this << endl;
	return this->textureTileSet;
}



// TileSet::TileSet(TileSetID newID){
//     id = newID;
//     sf:: IntRect rectSourceSprite(0,0,100,100);
//     cellWidth=100;
//     cellHeight=100;

//     if (id == KUROTILE )
//     {
//         cellWidth=100;
//         cellHeight=100;
//         imageFile="/home/ensea/plt/res/Fighters/Kuro.png";
//         textureTileSet.loadFromFile(imageFile,rectSourceSprite);
//     }
//     if (id == FLINTTILE)
//     {
//         cellWidth=100;
//         cellHeight=100;
//         imageFile="/home/ensea/plt/res/Fighters/Flint.png";
//         textureTileSet.loadFromFile(imageFile,rectSourceSprite);
//     }
//      if (id == TERRAIN )
//     {
//         cellWidth=640;
//         cellHeight=384;
//         imageFile="/home/ensea/plt/res/Terrains/seku_terrain.png";
//         textureTileSet.loadFromFile(imageFile);
//     }
//     //sf:: IntRect rectSourceSprite(0,0,100,100);
    
// }

// int const TileSet ::getCellWidth(){
//     return cellWidth;
// }

// int const TileSet ::getCellHeight(){
//     return cellHeight;
// }

// int const TileSet ::getTileSetID(){
//     return id;
// }

// sf::Texture& TileSet:: getTexture (){
//     return textureTileSet;
// }
