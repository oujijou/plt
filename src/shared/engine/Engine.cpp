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
    currentCommands[priority] = move(ptr_cmd);
}

void Engine::update()
{
    StateEvent stateEvent(FIGHTERCHANGED);
    //cout << "stateEvent ok"<< endl;

	map<int, std::unique_ptr<Command>>::iterator it;
	//cout << "command ok" << endl;
    // Execute each command of the currentCommandss table
	for(size_t i=0; i<currentCommands.size(); i++){
		//cout << "inside loop" << endl;
		currentCommands[i]->execute(currentState);
		//cout << "execution done" << endl;
		currentState.notifyObservers(stateEvent, currentState); // Notify the state which will notify render
	//	cout << "\n" <<endl;
		sleep(2);
		
	}

    // Erase all the commands which were executed
	currentCommands.clear();

}

bool Engine::checkGameEnd(){
	bool gameEnd = true;

	// For each player
	for (unsigned int i = 0; i < currentState.getPlayerList().size(); i++){
		// For each Fighter belonging to each player
		
			// As long as another player has a Fighter alive the game isn't finished
			if(currentState.getPlayerList()[i].getFighter().getStatus()!=DEAD){

				//cout<<"The player "<< currentState.getPlayerList()[i]->getName()<<" win the game!!!"<<endl;
				gameEnd=false;
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
		
			// As long as a player has a Fighter with which he didn't play --> the round is not finished
			if(currentState.getPlayerList()[i].getID() == currentState.getCurrentPlayerID()){
				if (currentState.getPlayerList()[i].getFighter().getStatus()!= DEAD ){
					if (currentState.getPlayerList()[i].getFighter().getStatus() != WAITING){
						playerChange = false;
					}
				}
			}
			if (currentState.getPlayerList()[i].getFighter().getStatus()!= DEAD ){
				if (currentState.getPlayerList()[i].getFighter().getStatus() != WAITING){
					roundChange = false;
				}
			}
			// As long as another player has a Fighter alive the game isn't finished
			if(currentState.getPlayerList()[i].getID()!=currentPlayerID){
				if(currentState.getPlayerList()[i].getFighter().getStatus()!=DEAD){
					gameEnd=false;
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
			if (currentState.getPlayerList()[i].getID() == currentState.getCurrentPlayerID()){
				cout<<"The player "<< currentState.getPlayerList()[i].getPlayerName()<<" win the game!!!"<<endl;
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

void Engine::checkRoundStart(){
	if (changeRound == true){
	
		// Change the current player
		currentState.setCurrentPlayerID(1);//Reset player ID to "1"=> first player
		cout << "\t\t--- Round " << currentState.getRound() << " ---\n" << endl;
		
		// For each player
		for (unsigned int i = 0; i < currentState.getPlayerList().size(); i++){
			// For each Fighter belonging to each player
			

				// For all Fighter which do not belong to the currentPlayer and which are not DEAD
				if (currentState.getPlayerList()[i].getFighter().getStatus()!= DEAD ){
					// Reset Status to Available
					//currentState.getPlayerList()[i]->getFighterList()[j]->setStatus(AVAILABLE);
					
					// Reset health points for each unit
					// if (currentState.getPlayerList()[i]->getFighterList()[j]->getEntityId() == KNIGHT){
					// 	currentState.getPlayerList()[i]->getFighterList()[j]->setMovementRange(2);
					// 	currentState.getPlayerList()[i]->getFighterList()[j]->setMovementLeft(2);

					// }
					// else if(currentState.getPlayerList()[i]->getFighterList()[j]->getEntityId() == TROLL) {
					// 	currentState.getPlayerList()[i]->getFighterList()[j]->setMovementRange(3);
					// 	currentState.getPlayerList()[i]->getFighterList()[j]->setMovementLeft(3);

					// }else if(currentState.getPlayerList()[i]->getFighterList()[j]->getEntityId() == MAGE) {
					// 	currentState.getPlayerList()[i]->getFighterList()[j]->setMovementRange(4);
					// 	currentState.getPlayerList()[i]->getFighterList()[j]->setMovementLeft(4);

					// }	
				
				
			}
		}
		changeRound = !changeRound;
	}
}
