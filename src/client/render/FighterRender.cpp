#include "FighterRender.h"
#include "TextureManager.h"

using namespace std;
using namespace render;

void FighterRender::draw (sf::RenderWindow& window, float drawPositionX, float drawPositionY, state::State& state)
{
    TextureManager *instance = TextureManager::getInstance(); //recupère une instance de TextureManager
    // on recupère le tilefighter  
    TileSet* tileFighter = instance->getTileFighter(state.getFighter().getName());
    
    sf::Sprite spriteFighter; //creation d'une sprite
    spriteFighter.setPosition(sf::Vector2f(drawPositionX,drawPositionY)); //postionnement d'un fighter
    
    spriteFighter.setTexture(tileFighter->getTexture());
    spriteFighter.setTextureRect(sf::IntRect(0, 0, 100, 100));
 
    window.draw(move(spriteFighter));
}

// void FighterRender::draw(sf::RenderWindow window, sf::Vector2f drawPosition, state::Fighter& fighter)
// {
//     //sf::Texture textureFighter = tileFighter->getTexture();
//     sf::Sprite spriteFighter;
//     spriteFighter.setPosition(drawPosition);
    
//     // spriteFighter.setTexture(textureFighter);
//     fighter.getName();

//     window.clear();
//    // window.draw(fighter.getName());//getTexture()
//     window.display();
// }
