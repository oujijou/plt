#include "State.h"
#include "memory.h"
#include <memory>
#include <iostream>
#include "Fighter.h"

using namespace std;
using namespace state;




State::State(){
    level = 1;
    round = 1;
}

Terrain State::getTerrain()
{
    return terrain;
}

void State::setTerrain(Terrain terrain)
{
    this-> terrain = terrain;
}

int State::getRound(){
    return round;
}

void State::setRound(int round){
    this->round = round;
}

int State::getLevel(){
    return level;
}

void State::setLevel(int level){
    this->level = level;
}

bool State::initPlayers(){

    //Associate a fighter to a player
    //Player 1
    Player player1(1);
    

    Fighter fighter1(Kuro, 1, WAITING,100, 100, 50,0, COUPDEPOING,20);//Tkork //Kuro
    
    player1.setFighter(fighter1);

    playerList.push_back(player1);
    // ptrFighter1->setX(ptrFighter1->getX());

    //Player 2 
    // shared_ptr<Player> ptrPlayer2(new Player(2));
    // playerList.push_back(ptrPlayer2);

    // shared_ptr<Fighter> ptrFighter2(new Fighter(ptrPlayer2->getID(), Kuro));
    Player player2(2);
    

    Fighter fighter2(Flint, 1, WAITING,100, 100, 50,0, COUPDEPOING,20); // Flint // Seku

    player2.setFighter(fighter2);
    // ptrFighter2->setX(ptrFighter2->getX());
    playerList.push_back(player2);

    return true;
}

std::vector<Player> State::getPlayerList () //tableau de ref vers les players
{
    return playerList;
}

bool State::getEndFight()
{
    return endFight;
}

void State::setCurrentPlayerID(int currentPlayerID)
{
    this->currentPlayerID = currentPlayerID;
}

int State::getCurrentPlayerID()
{
    return currentPlayerID;
}

State::~State(){
    
}

