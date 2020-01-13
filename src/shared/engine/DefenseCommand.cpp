#include "../engine.h"
#include "../state.h"
#include <iostream>
#include <unistd.h>
#include <stdlib.h>
#include "DefenseCommand.h"

using namespace std;
using namespace engine;
using namespace state;

//Constructor

DefenseCommand::DefenseCommand(std::shared_ptr<Fighter> isDefending) : isDefending(isDefending)
{
    type = "defense";
}
//Functions
void DefenseCommand::execute(state::State &state)
{

    if(isDefending->getStatus() != DEAD)
    {
        //isDefending->defend();
        isDefending->setHealthPoints(std::min(isDefending->getHealthPointsMax(), isDefending->getHealthPoints() + 5));

        string defenderName = "";
        switch(isDefending->getName())
        {
            case Flint: 
                defenderName = "Flint";
                break;
            case Kuro:
                defenderName = "Kuro";
                break;
            case Thork:
                defenderName = "Thork";
                break;
            case Seku:
                defenderName = "Seku";
                break;   
        }


        string defenderStatus = "";
        switch(isDefending->getStatus())
        {
            case DEFENSE: 
                defenderStatus = "DEFENSE";
                break;
            case WAITING:
                defenderStatus = "WAITING";
                break;
            case DEAD:
                defenderStatus = "DEAD";
                break;
            case RECHARGE:
                defenderStatus = "RECHARGE";
                break;   
        }

        cout << defenderName << " status is "<< defenderStatus << endl; 
    }
    else if(isDefending->getStatus()==DEAD){
        cout<<"Already dead!"<<endl;
    }
    
}

std::string DefenseCommand::toJSON()
{
    return "\"command\":{\"target\":" + std::to_string((int) isDefending->getName()) + "}";
}