#include "Engine.h"

using namespace std;
using namespace engine;


Engine::Engine ()
{
    nextTour = false;
    currentPlayer = true;
}

Engine::~Engine ()
{
   
}

state::State& Engine::getState()
{
    state::State& refState = currentState;
    return refState;
}

void Engine::addCommand(int priority, std::unique_ptr<Command> ptr_cmd)
{
    currentCommand[priority] = move(ptr_cmd);
}

// void Engine :: update(sf::RenderWindow& window)
// {
//     // StateEvent
// }
