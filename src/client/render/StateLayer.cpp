#include "StateLayer.h"
#include "../render.h"

using namespace std;
using namespace render;

StateLayer::StateLayer(sf::RenderWindow& window, state::State& State)
{
   	TileSet tileSetFighter1(KUROTILE);
	unique_ptr<TileSet> ptr_fighterTileSet1 (new TileSet(tileSetFighter1));
	tileSets.push_back(move(ptr_fighterTileSet1));

    TileSet tileSetFighter2(FLINTTILE);
	unique_ptr<TileSet> ptr_fighterTileSet2 (new TileSet(tileSetFighter2));
	tileSets.push_back(move(ptr_fighterTileSet2));

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


    // textureFighter1.loadFighter1(state,*tileSets[0]);
    // textureFighter2.loadFighter2(state,*tileSets[1]);
    textureFighter1.loadFighter(100,100,"res/Fighters/Kuro.png");
    textureFighter2.loadFighter(100,100,"res/Fighters/Flint.png");
    textureTerrain.loadTerrain(640,384,"res/Terrains/seku_terrain.png");

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
    window.draw(*textureManagers[2]);
    window.draw(*textureManagers[0]);
    window.draw(*textureManagers[1]);
    window.display();
}

int StateLayer::getMapHeight() const{
    return mapHeight;
}

int StateLayer::getMapWidth() const{
    return mapWidth;
}
