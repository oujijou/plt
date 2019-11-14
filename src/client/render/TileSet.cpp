#include "TileSet.h"

using namespace std;
using namespace render;


TileSet::TileSet(std::string path)
{
	this->path = path;
}
 
bool TileSet::loadTexture()
{
	textureTileSet.loadFromFile(path);
}

const sf::Texture& TileSet::getTexture() 
{
	return textureTileSet;
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
