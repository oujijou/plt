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