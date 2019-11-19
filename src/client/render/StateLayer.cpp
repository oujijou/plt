#include "StateLayer.h"
#include "../render.h"
#include <string>
#include <time.h>
#include "state.h"
#include <iostream>

using namespace std;
using namespace render;
using namespace state;


StateLayer::StateLayer(sf::RenderWindow& window, const state::State& state): window(window)
{   
    this->state = state;
}

void StateLayer::draw()
{
   // state::Fighter f1;
    window.clear();
    background.draw(window, state);
    fighterRender1.draw(window,50.f,250.f,state, 0);
    fighterRender2.draw(window,500.f, 250.f,state, 1);
    
    sf::Event event;
                sf::Font font;
				if(!font.loadFromFile("/home/ensea/plt/res/Fonts/FontFile.ttf"))
				{
				//return false;
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
				
				sf::Texture hpBarTexture;
				if(!hpBarTexture.loadFromFile("/home/ensea/plt/res/redBg.jpg",sf::IntRect(0,0,100,10)))
				{
					//return false;
				}
				
				sf::Sprite hpBarP1;
				hpBarP1.setTexture(hpBarTexture);
				hpBarP1.setPosition(0.f,40.f);
				
				sf::Sprite hpBarP2;
				hpBarP2.setTexture(hpBarTexture);
				hpBarP2.setPosition(530.f,40.f);
    window.draw(text1);
    window.draw(text2);
	window.draw(hpBarP1);
	window.draw(hpBarP2);
    window.display();
}

void StateLayer::stateChanged(const state::StateEvent& stateEvent,
                              const state::State &new_state)
{
    this->state = new_state;
    this->draw();
    cout << "StateLayer::stateChanged" << endl;
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
