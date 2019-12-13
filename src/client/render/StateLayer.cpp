#include "StateLayer.h"
#include "../render.h"
#include <string>
#include <time.h>
#include "state.h"
#include <iostream>
#include "HealthBar.h"


using namespace std;
using namespace render;
using namespace state;

bool StateLayer::realEngine = true;


StateLayer::StateLayer(sf::RenderWindow& window, const state::State& state): window(window)
{   
    this->state = state;
}

void StateLayer::draw()
{
    if (!StateLayer::realEngine)
    {
        return;
    }
    //cout << "enter in draw from statelayer" << endl;
    window.clear();

    background.draw(window, state);
    //cout << "background ok" << endl;
    fighterRender1.draw(window,50.f,250.f,state.getPlayerList()[0], 2);// id = 0, 2
    //cout << "fighterrenderok" << endl;
    healthBar1.draw(window,state.getPlayerList()[0], 0.f, 40.f);
    healthBar2.draw(window,state.getPlayerList()[1], 440.f, 40.f);
    fighterRender2.draw(window,500.f, 250.f,state.getPlayerList()[1],1);// id = 1, 3

    //about the Font ...
    sf::Event event;
    sf::Font font;
    if(!font.loadFromFile("../res/Fonts/FontFile.ttf"))
    {
        std::cout << "Load Failed" << std::endl;
        system("Pause");
    }
    sf::Text text1;
    text1.setFont(font);
    text1.setString("Health Points");
    text1.setCharacterSize(40);
    
    sf::Text text2;
    text2.setFont(font);
    text2.setString("Health Points");
    text2.setCharacterSize(40);
    text2.setPosition(530.f,0.f);
    
    // sf::Texture hpBarTexture;
    // if(!hpBarTexture.loadFromFile("../res/redBg.jpg",sf::IntRect(0,0,100,10)))
    // {
    //     std::cout << "Load Failed" << std::endl;
    //     system("Pause");
    // }
    
    // sf::Sprite hpBarP1;
    // hpBarP1.setTexture(hpBarTexture);
    // hpBarP1.setPosition(0.f,40.f);
    
    // sf::Sprite hpBarP2;
    // hpBarP2.setTexture(hpBarTexture);
    // hpBarP2.setPosition(530.f,40.f);
    window.draw(text1);
    window.draw(text2);
   
	// window.draw(hpBarP1);
	// window.draw(hpBarP2);
    window.display();
}


void StateLayer::stateChanged(const state::StateEvent& stateEvent, const state::State &new_state)
{
    this->state = new_state;
    this->draw();

    // if(stateEvent.getStateEventID() == FIGHTERCHANGED)
    // {
    //     state.getFighter();
    //     draw();
    // }
    //cout << "StateLayer::stateChanged" << endl; // pour debugger


    //this->stateEvent = stateEvent;
    //draw();
    //stateLayer.registerObservers();
    /*
    if(stateEvent.getStateEventID == ALLCHANGED)
    {
        state.getFighter();
        state.getTerrain();
        draw();
    }
    if(stateEvent.getStateEventID == FIGHTERCHANGED)
    {
        state.getFighter();
        draw();
    }
    if(stateEvent.getStateEventID == TERRAINCHANGED)
    {
        state.getTerrain();
        draw();
    }*/
}
