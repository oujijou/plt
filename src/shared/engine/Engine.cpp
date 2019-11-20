#include "Engine.h"
#include "../engine.h"
#include <iostream>
#include <unistd.h>
#include "../state.h"

using namespace std;
using namespace engine;
using namespace state;

Engine::Engine (state::State)
{
    
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

// void Engine::update()
// {
//     StateEvent stateEvent(FIGHTERCHANGED);
    

// 	map<int, std::unique_ptr<Command>>::iterator it;

//     // Execute each command of the currentCommands table
// 	for(size_t i=0; i<currentCommand.size(); i++){
// 		currentCommand[i]->execute(currentState);
// 		currentState.notifyObservers(stateEvent, currentState); // Notify the state which will notify render
// 		sleep(2);
// 	}

//     // Erase all the commands which were executed
// 	for(it=currentCommand.begin(); it!=currentCommand.end(); it++){
// 		currentCommand.erase(it);
// 	}
    
// }

