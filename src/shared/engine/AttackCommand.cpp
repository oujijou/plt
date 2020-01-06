#include "../engine.h"
#include "../state.h"
#include <iostream> 
#include <unistd.h>
#include <stdlib.h>
#include "AttackCommand.h"

using namespace engine;
using namespace state;
using namespace std;


//Contructor
AttackCommand::AttackCommand (std::shared_ptr<Fighter> attacker, std::shared_ptr<Fighter> target):attacker(attacker),target(target)
{
    type = "attack";
}

//Functions

void AttackCommand::execute (state::State& state){
    cout << "execution is coming" << endl;
    int waitingTime = 5;
    
    if(attacker->getStatus()!=DEAD){
        float oldTargetHealth=target->getHealthPoints();
       
       
        //Fighting
        attacker->fight(target, COUPDEPOING);
        
        //int waitingTime=40000;
        
        string attackerName = "";
        string targetName = "";

        switch(attacker->getName()){
            case Flint: 
                attackerName = "Flint";
            break;
            case Kuro:
                attackerName = "Kuro";
            break;
            case Thork:
                attackerName = "Thork";
            break;
            case Seku:
                attackerName = "Seku";
            break;       
        }

        switch(target->getName()){
            case Flint: 
                targetName = "Flint";
            break;
            case Kuro:
                targetName = "Kuro";
            break;
            case Thork:
                targetName = "Thork";
            break;
            case Seku:
                targetName = "Seku";
            break;       
        }

        cout << attackerName << " will attack or try to attack " << targetName << "." << endl;
        cout<< targetName << " had "<<oldTargetHealth<<" health points."<<endl;
        cout<< targetName<< " has " << target->getHealthPoints() <<" health points now."<<endl;

        //target->setHealthPoints(target->getHealthPoints());

        //attacker->setStatus(WAITING);


        if(target->getHealthPoints()==0){
            target->setStatus(DEAD);
            // animation dead
            cout << targetName << " is dead." << endl;
        }
    }
    else if(attacker->getStatus()==DEAD){
        cout<<"Already dead!"<<endl;
    }else if(attacker->getStatus()==WAITING){
        string attackerName = "";
        switch(attacker->getName()){
            case Flint: 
                attackerName = "Flint";
            break;
            case Kuro:
                attackerName = "Kuro";
            break;
            case Thork:
                attackerName = "Thork";
            break;
            case Seku:
                attackerName = "Seku";
            break;       
        }
        cout<< attackerName << " cannot attack because his turn already ended.\n" << endl;
        usleep(waitingTime);
    }
   
}

std::string AttackCommand::toJSON()
{
    return (std::string("\"command\":{\n\"attacker\":") + std::to_string((int) attacker->getName())) + ",\n\"targed\":" + std::to_string((int) target->getName()) + "\n}";
}