#include "State.h"
#include "memory.h"
#include <memory>

using namespace std;

namespace state{

    State::State(){

    }

    Fighter State::getFighter(){
        return fighter1;
    }

    Fighter State::setFighter(Fighter fighter1){
        this->fighter1= fighter1;
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
        // Player Player1 {};
        // playerList.push_back(Player1);

        // Player Player2 {};
        // playerList.push_back(Player2);

        shared_ptr<Player> ptrPlayer1(new Player());
        playerList.push_back(ptrPlayer1);

        shared_ptr<Player> ptrPlayer2(new Player());
        playerList.push_back(ptrPlayer2);

        return true;
    }

    std::vector<std::shared_ptr<Player>>& State::getPlayerList () //tableau de ref vers les players
    {
        return playerList;
    }

}