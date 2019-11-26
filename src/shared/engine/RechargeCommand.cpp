#include "../engine.h"
#include "../state.h"
#include <iostream> 
#include <unistd.h>
#include <stdlib.h>
#include "RechargeCommand.h"

using namespace engine;
using namespace state;
using namespace std;

//Constructor

RechargeCommand::RechargeCommand (state::Fighter fighter):fighter(fighter)
{

}
//Functions
void RechargeCommand::execute (state::State& state){
    
    if(fighter.getStatus()!=DEAD){
  
        //cout<<"Recharge is coming!!"<<endl;
        float oldMana=fighter.getMana();
        float oldHealthPoints = fighter.getHealthPoints();
        
        int waitingTime=40000;
		string entityNameRecharging = "";
		switch(fighter.getName()){
			case Flint: 
				entityNameRecharging = "Flint";
            break;
			case Kuro:
				entityNameRecharging = "Kuro";
            break;
			case Thork:
				entityNameRecharging = "Thork";
            break;
			case Seku:
				entityNameRecharging = "Seku";
            break;       
        }
        fighter.recharge();
        
        cout << "This fighter " << entityNameRecharging << " is recharging " << endl;

        cout<<"This fighter had "<<oldMana <<" mana points"<<endl;
        cout<<"this fighter has now "<<fighter.getMana()<<" mana points."<<endl;

        cout<<"This fighter had "<<oldHealthPoints <<" health points"<<endl;
        cout<<"This fighter has now "<<fighter.getHealthPoints()<<" healthpoints."<<endl;

    }else if(fighter.getStatus()==DEAD){
        cout<<"Already dead!"<<endl;
    }
}