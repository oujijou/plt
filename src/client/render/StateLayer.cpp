#include "StateLayer.h"
#include "../render.h"
#include <string>
#include <time.h>
#include "state.h"

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
    fighterRender1.draw(window,50.f,250.f,state);
    fighterRender2.draw(window,500.f, 250.f,state);
    background.draw(window, state);
    window.display();
}

void StateLayer::stateChanged(const state::StateEvent& stateEvent, const state::State state)
{
    draw();
    //stateLayer.registerObservers();
}