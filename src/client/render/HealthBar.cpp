#include "HealthBar.h"
#include "TextureManager.h"

using namespace std;
using namespace render;
using namespace state;



void HealthBar::draw (sf::RenderWindow& window, std::shared_ptr<state::Player> player,float x, float y)
{
    TextureManager *instance = TextureManager::getInstance();
    TileSet *tileHpBar1 = instance->getTileHealthBar(0);
   

    sf::Sprite hpBar;
    hpBar.setTexture(tileHpBar1->getTexture());
    hpBar.setPosition(x,y); //0 40
    hpBar.setScale(sf::Vector2f((float) player->getFighter()->getHealthPoints() / 100, 1));
    
    // sf::Sprite hpBarP2;
    // hpBarP2.setTexture(tileHpBar->getTexture());
    // hpBarP2.setPosition(530.f,40.f); //530.f,40.f
    
    window.draw(hpBar);  
}


