#include "StateLayer.h"
#include "../render.h"

using namespace std;
using namespace render;

StateLayer::StateLayer(sf::RenderWindow& window, state::State& State)
{
    //font.loadFromFile("rsc/Font/Game_Played.otf");
    screenWidth=1950;
    screenHeight=900;

    mapWidth=1600;
    mapHeight=800;

	TileSet tileSetFighter1(KUROTILE);//Load units tileset image
	unique_ptr<TileSet> ptr_fighterTileSet1 (new TileSet(tileSetFighter1));
	tileSets.push_back(move(ptr_fighterTileSet1));//Store pointor of the TileSet object

    TileSet tileSetFighter2(FLINTTILE);//Load units tileset image
	unique_ptr<TileSet> ptr_fighterTileSet2 (new TileSet(tileSetFighter2));
	tileSets.push_back(move(ptr_fighterTileSet2));//Store pointor of the TileSet object

    TileSet tileSetTerrain(TERRAIN);
	std::unique_ptr<TileSet> ptr_terrainTileSet (new TileSet(tileSetTerrain));
	tileSets.push_back(move(ptr_terrainTileSet));
}

std::vector<std::unique_ptr<TileSet>>& StateLayer::getTileSets()
{
    return tileSets;
}

std::vector<std::unique_ptr<TextureManager>>& StateLayer::getTextureManagers()
{
    return textureManagers;
}

void StateLayer::initTextureManagers(state::State state)
{
    //Déclaration des textures
    TextureManager textureFighter1;
    TextureManager textureFighter2;
    TextureManager textureTerrain;

    //Chargement des Tiles dans Texture
    // string directory="rsc/Images/level1_completeMap.png";
    // .loadMap(mapWidth,mapHeight,directory);
    //map.loadMap(mapWidth,mapHeight,state,*tileSets[2]);

    textureFighter1.loadFighter(state,*tileSets[0]);
    textureFighter2.loadFighter(state,*tileSets[1]);
    textureTerrain.loadTerrain(640,384,"/home/ensea/plt/res/Terrains/seku_terrain.png");

    //Déclaration des pointeurs sur des pbjets de types Texture
	std::unique_ptr<TextureManager> ptr_fighter1 (new TextureManager(textureFighter1));
    std::unique_ptr<TextureManager> ptr_fighter2 (new TextureManager(textureFighter2));
    std::unique_ptr<TextureManager> ptr_terrain (new TextureManager(textureTerrain));

    //Vider la table des éléments de type Texture
    if(textureManagers.size()!=0){
		while(textureManagers.size()!=0){
			textureManagers.pop_back();
		}
	}

    textureManagers.push_back(move(ptr_fighter1 ));
    textureManagers.push_back(move(ptr_fighter2));
    textureManagers.push_back(move(ptr_terrain));
}

void StateLayer::draw (sf::RenderWindow& window)
{
    window.clear();
    window.draw(*textureManagers[0]);
    window.draw(*textureManagers[1]);
    window.draw(*textureManagers[2]);
    window.display();
}

int StateLayer::getMapHeight() const{
    return mapHeight;
}

int StateLayer::getMapWidth() const{
    return mapWidth;
}

