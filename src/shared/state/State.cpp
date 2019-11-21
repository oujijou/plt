#include "State.h"
#include "memory.h"
#include <memory>
#include <iostream>

using namespace std;


namespace state{

    State::State(){
        
        //Player (false,Kuro,fighter1);
       // Fighter fighter1(Kuro,DEAD,);
        //fighter1.setName(Kuro);
        //fighter(Kuro,DEFENSE,100,)

        //fighter2.setName(Flint);

       // terrain = KuroTerrain;

        

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

    Fighter State::getFighter(){
        bool choice;
        if(choice)
        {
            return fighterList[0];
            
        }
        if(!choice)
        {
            return fighterList[1];
        }
        //return fighter; //!!!!
    }

    void State::setFighter(Fighter fighter){
        //this->fighter2 = fighter;
        this->fighter1 = fighter; //!!!!
        fighterList.push_back(fighter);
    }
    
    void State::setFighters(Fighter fighter11, Fighter  fighter22){
        
        std::cout << "test1" <<" **"<< fighter11.getName()<<  std::endl;
        this->fighter1= fighter11;
        std::cout << "test2***"<<fighter22.getName()<<std::endl;
        this->fighter2= fighter22;

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
