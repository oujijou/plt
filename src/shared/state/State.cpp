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
    currentPlayerID = 0;
    endFight=false;
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
    //pointers are life!!!  <3 :) 03/12/2019
    //Player 1
    shared_ptr<Player> ptrPlayer1(new Player(1));
   
    shared_ptr<Fighter> ptrFighter(new Fighter(Thork, ptrPlayer1->getID(), WAITING,100, 100, 50,0, COUPDEPOING,200));
    
    ptrPlayer1->setFighter(ptrFighter);


    playerList.push_back(ptrPlayer1);


    // ptrFighter1->setX(ptrFighter1->getX());

    //Player 2 
    // shared_ptr<Player> ptrPlayer2(new Player(2));
    // playerList.push_back(ptrPlayer2);

    // shared_ptr<Fighter> ptrFighter2(new Fighter(ptrPlayer2->getID(), Kuro));


    shared_ptr<Player> ptrPlayer2(new Player(2));
   
    shared_ptr<Fighter> ptrFighter2(new Fighter(Flint, ptrPlayer2->getID(), WAITING,100, 100, 50,0, COUPDEPOING,100));
    
    ptrPlayer2->setFighter(ptrFighter2);


    playerList.push_back(ptrPlayer2);
    // Player player2(2);
    

    // Fighter fighter2(Flint, 1, WAITING,100, 100, 50,0, COUPDEPOING,50); // Flint // Seku

    // player2.setFighter(fighter2);
    // // ptrFighter2->setX(ptrFighter2->getX());
    // playerList.push_back(player2);

    return true;
}

std::vector<std::shared_ptr<Player>> State::getPlayerList () //tableau de ref vers les players
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

