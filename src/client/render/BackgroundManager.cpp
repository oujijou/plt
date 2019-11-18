#include "BackgroundManager.h"
#include "TextureManager.h"
#include <iostream>

using namespace std;
using namespace render;
using namespace state;

void BackgroundManager::draw(sf::RenderWindow& window,  state::State& state)
{
    TextureManager *instance = TextureManager::getInstance(); //recupère une instance de TextureManager
    TileSet* tileBackground = instance->getTileBackground(state.getTerrain());
    
    sf::Sprite spriteBackground(tileBackground->getTexture());
    cout << "Hey: " << &tileBackground->getTexture() << endl;
    
    window.draw(spriteBackground);
    /*
    {
        sf::Texture t;
        t.loadFromFile("./res/Terrains/seku_terrain.png");
        window.draw(sf::Sprite {t});
    }*/
}
