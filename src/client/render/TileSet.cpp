#include "TileSet.h"

using namespace std;
using namespace render;

TileSet::TileSet(TileSetID newID){
    id = newID;
    
    cellWidth=100;
    cellHeight=100;

    if (id == KUROTILE )
    {
        cellWidth=100;
        cellHeight=100;
        imageFile="res/Fighters/Kuro.png";
    }
    if (id == FLINTTILE)
    {
        cellWidth=100;
        cellHeight=100;
        imageFile="res/Fighters/Flint.png";
    }
     if (id == TERRAIN )
    {
        cellWidth=640;
        cellHeight=384;
        imageFile="res/Terrains/seku_terrain.png";
    }
    //sf:: IntRect rectSourceSprite(0,0,100,100);
    textureTileSet.loadFromFile(imageFile);
}

int const TileSet ::getCellWidth(){
    return cellWidth;
}

int const TileSet ::getCellHeight(){
    return cellHeight;
}

int const TileSet ::getTileSetID(){
    return id;
}

sf::Texture& TileSet:: getTexture (){
    return textureTileSet;
}
