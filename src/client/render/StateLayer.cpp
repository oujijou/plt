#include "StateLayer.h"
#include "../render.h"
#include <string>
#include <time.h>

using namespace std;
using namespace render;


StateLayer::StateLayer(sf::RenderWindow& window, const state::State& State): window(window), state(state)
{   

    
}

void StateLayer::draw()
{
    window.clear();
    background.draw(window, state);
    // window.draw(fighter1);
    // window.draw(fighter2);
    // window.draw(background);
    window.display();
}

void StateLayer::stateChanged(const state::StateEvent& stateEvent, const state::State& state)
{
    //stateLayer.registerObservers();
}