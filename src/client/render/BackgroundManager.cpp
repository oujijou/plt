#include "BackgroundManager.h"
#include "TextureManager.h"

using namespace std;
using namespace render;
using namespace state;

void BackgroundManager::draw(sf::RenderWindow& window,  state::State& state)
{
    const TextureManager *instance = TextureManager::getInstance(); //recupère une instance de TextureManager
    TileSet* tileBackground = instance->getTileBackground(state.getTerrain());

    window.clear();
    window.draw((sf::Sprite)tileBackground->getTexture());
    window.display();
}
