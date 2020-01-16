#include "Engine.h"
#include "../engine.h"
#include <iostream>
#include <unistd.h>
#include "../state.h"
#include "../../client/render/StateLayer.h"
#include "../../replayDumper.h"

using namespace std;
using namespace engine;
using namespace state;

Engine::Engine () : currentState(){
	changeRound = true;
	jsonCommands = new JSONCommands();
}



Engine::~Engine()
{
   
}

State& Engine::getState()
{
    return currentState;
}

void Engine::addCommand(int priority, std::shared_ptr<Command> ptr_cmd)
{
	if (dumpJSONCommands)
	{
		dumpresult += jsonCommands->toJSON(ptr_cmd) + "," + "\n";
	}
    currentCommands[priority] = move(ptr_cmd);
}

void Engine::update()
{
	if (checkGameEnd() && realEngine)
	{
		std::cout << "ENDING GAME !" << std::endl;
		logReplay("replay.txt", "[" + dumpresult + "{}]");
		delete jsonCommands;
		exit(0);
	}
    StateEvent stateEvent(FIGHTERCHANGED);
    //cout << "stateEvent ok"<< endl;

	map<int, std::unique_ptr<Command>>::iterator it;
	//cout << "command ok" << endl;
    // Execute each command of the currentCommandss table
	for(size_t i=0; i<currentCommands.size(); i++){
		//cout << "inside loop" << endl;
		currentCommands[i]->execute(currentState);
		//cout << "execution done" << endl;
		render::StateLayer::realEngine = realEngine;
		currentState.notifyObservers(stateEvent, currentState); // Notify the state which will notify render
		cout << "\n" <<endl;
	}

    // Erase all the commands which were executed
	currentCommands.clear();

}

bool Engine::checkGameEnd(){
	bool gameEnd = false;

	// For each player
	for (unsigned int i = 0; i < currentState.getPlayerList().size(); i++){
		// For each Fighter belonging to each player	
			// As long as another player has his Fighter alive the game isn't finished
			if(currentState.getPlayerList()[i]->getFighter()->getStatus()==DEAD){

				cout<<"The player "<< currentState.getPlayerList()[i]->getPlayerName()<<" lost the game!!!"<<endl;
				gameEnd=true;
			}
	}
	return gameEnd;
}

void Engine::screenRefresh(){
	StateEvent stateEvent(PLAYERCHANGED);
	if (realEngine)
	currentState.notifyObservers(stateEvent, currentState); // Notify the state which will notify render
}

bool Engine::checkRoundEnd(){
	bool playerChange = true;
	bool roundChange = true;
	bool gameEnd = true;
	int currentPlayerID;

	if(playerChange && roundChange)
	{
		currentPlayerID=currentState.getCurrentPlayerID();
		currentState.setCurrentPlayerID(currentPlayerID);
		cout << "The player 0   " << currentPlayerID << " playing."<< endl;
		playerChange = false;
		roundChange = false;
		gameEnd = false;
		
	}
	else if(playerChange && !roundChange){
		currentPlayerID=currentState.getCurrentPlayerID();
		currentState.setCurrentPlayerID(!currentPlayerID);
		cout << "The player   " << currentPlayerID << " playing."<< endl;

	}
	if(gameEnd){
		cout << "End of the game !" << endl;
		for (unsigned int i = 0; i < currentState.getPlayerList().size(); i++){
			if (currentState.getPlayerList()[i]->getFighter()->getHealthPoints() == 0){
				cout<<"The player "<< currentState.getPlayerList()[i]->getPlayerName()<<" lost the game!!!"<<endl;
			}
		}
	}
	
	return roundChange;
}

void Engine::checkRoundStart(){
	if (changeRound == true){
	
		// Change the current player
		currentState.setCurrentPlayerID(0);//Reset player ID to "0"=> first player
		cout << "\t\t--- Round " << currentState.getRound() << " ---\n" << endl;
		
		// For each player
		for (unsigned int i = 0; i < currentState.getPlayerList().size(); i++){
				// For all Fighter which do not belong to the currentPlayer and which are not DEAD
				if (currentState.getPlayerList()[i]->getFighter()->getStatus()!= DEAD ){
					// Reset Status to Available
					currentState.getPlayerList()[i]->getFighter()->setStatus(WAITING);
	
			}
		}
		changeRound = !changeRound;
	}
}

void Engine::runCommands()
{

}

std::shared_ptr<Engine> Engine::copy()
{
	std::shared_ptr<Engine> result = std::make_shared<Engine>();
	result->currentState = currentState.copy();
	result->turnOperation = turnOperation;
	result->stop = stop;
	result->turnOperation = turnOperation;
	return result;
}