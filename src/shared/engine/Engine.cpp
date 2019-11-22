#include "Engine.h"
#include "../engine.h"
#include <iostream>
#include <unistd.h>
#include "../state.h"

using namespace std;
using namespace engine;
using namespace state;

// Engine::Engine () : currentState(){
// 	changeRound = false;
// }

Engine::Engine () : currentState()
{
    
}

Engine::~Engine()
{
   
}

State& Engine::getState()
{
    return currentState;
}

void Engine::addCommand(int priority, std::unique_ptr<Command> ptr_cmd)
{
    currentCommand[priority] = move(ptr_cmd);
}

void Engine::update()
{
    StateEvent stateEvent(FIGHTERCHANGED);
    

	map<int, std::unique_ptr<Command>>::iterator it;

    // Execute each command of the currentCommands table
	for(size_t i=0; i<currentCommand.size(); i++){
		currentCommand[i]->execute(currentState);
		currentState.notifyObservers(stateEvent, currentState); // Notify the state which will notify render
		sleep(2);
	}

    // Erase all the commands which were executed
	for(auto it=currentCommand.begin(); it!=currentCommand.end(); it++){
		currentCommand.erase(it);
	}

}

bool Engine::checkGameEnd(){
	bool gameEnd = true;

	// For each player
	for (unsigned int i = 0; i < currentState.getPlayerList().size(); i++){
		// For each Fighter belonging to each player
		for(unsigned int j = 0;j<currentState.getPlayerList()[i]->getFighterList().size(); j++){
			// As long as another player has a Fighter alive the game isn't finished
			if(currentState.getPlayerList()[i]->getFighterList()[j]->getStatus()!=DEAD){

				//cout<<"The player "<< currentState.getPlayerList()[i]->getName()<<" win the game!!!"<<endl;
				gameEnd=false;
			}
		}
	}
	return gameEnd;

}

void Engine::screenRefresh(){
	StateEvent stateEvent(PLAYERCHANGED);
	currentState.notifyObservers(stateEvent, currentState); // Notify the state which will notify render

}

bool Engine::checkRoundEnd(){
	bool playerChange = true;
	bool roundChange = true;
	bool gameEnd = true;
	int currentPlayerID=currentState.getCurrentPlayerID();

	// For each player
	for (unsigned int i = 0; i < currentState.getPlayerList().size(); i++){
		// For each Fighter belonging to each player
		for(unsigned int j = 0;j<currentState.getPlayerList()[i]->getFighterList().size(); j++){

			// As long as a player has a Fighter with which he didn't play --> the round is not finished
			if(currentState.getPlayerList()[i]->getID() == currentState.getCurrentPlayerID()){
				if (currentState.getPlayerList()[i]->getFighterList()[j]->getStatus()!= DEAD ){
					if (currentState.getPlayerList()[i]->getFighterList()[j]->getStatus() != WAITING){
						playerChange = false;
					}
				}
			}
			if (currentState.getPlayerList()[i]->getFighterList()[j]->getStatus()!= DEAD ){
				if (currentState.getPlayerList()[i]->getFighterList()[j]->getStatus() != WAITING){
					roundChange = false;
				}
			}
			// As long as another player has a Fighter alive the game isn't finished
			if(currentState.getPlayerList()[i]->getID()!=currentPlayerID){
				if(currentState.getPlayerList()[i]->getFighterList()[j]->getStatus()!=DEAD){
					gameEnd=false;
				}
			}
		}
	}

	if(playerChange && !roundChange){
		cout << "The player " << currentState.getCurrentPlayerID() << " ends his round.\n"<< endl;
		currentState.setCurrentPlayerID(currentState.getCurrentPlayerID()+1);//Increase the Player ID
		cout << "The player " << currentState.getCurrentPlayerID() << " starts his round.\n" << endl;

	// If the round changes and the game has ended --> the actual player win the game because all ennemies Fighter are dead
	} else if(roundChange && gameEnd){
		cout << "End of the game !" << endl;

		for (unsigned int i = 0; i < currentState.getPlayerList().size(); i++){
			if (currentState.getPlayerList()[i]->getID() == currentState.getCurrentPlayerID()){
				cout<<"The player "<< currentState.getPlayerList()[i]->getPlayerName()<<" win the game!!!"<<endl;
			}
		}
		
		roundChange=false;
	}else if(roundChange && !gameEnd){
		cout << "Round has ended.\n" << endl;
		currentState.setRound(currentState.getRound() + 1);
		changeRound=true;
	}
	
	return roundChange;
}
