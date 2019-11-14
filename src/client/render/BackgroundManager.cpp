#include "BackgroundManager.h"
#include "TextureManager.h"


using namespace std;
using namespace render;
using namespace state;

void BackgroundManager::draw(sf::RenderWindow& window,  state::State& state)
{
    TextureManager *instance = TextureManager::getInstance(); //recupère une instance de TextureManager
    TileSet* tileBackground = instance->getTileBackground(state.getTerrain());
    
    sf::Sprite spriteBackground;
    spriteBackground.setTexture(tileBackground->getTexture());
    
    window.clear();
    window.draw(spriteBackground);
    window.display();
}
