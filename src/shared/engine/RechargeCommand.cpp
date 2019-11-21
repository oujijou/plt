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

RechargeCommand::RechargeCommand (state::Fighter& fighter):fighter(fighter)
{

}
//Functions
void RechargeCommand::execute (state::State& state){
    
    if(fighter.getStatus()!=DEAD){
  
        
        cout<<"Recharge is coming!!"<<endl;
        float oldMana=fighter.getMana();
        
        int waitingTime=40000;
		string entityNameRecharging = "";
		switch(fighter.getName()){
			case Flint: 
				entityNameRecharging = "flint";
            break;
			case Kuro:
				entityNameRecharging = "kuro";
            break;
			case Thork:
				entityNameRecharging = "thork";
            break;
			case Seku:
				entityNameRecharging = "seku";
            break;       
    }
    fighter.recharge(fighter);
    cout << "This fighter" << entityNameRecharging << " is recharging " << endl;
    cout<<"Le fighter avait "<<oldMana<<" points de vie."<<endl;
    cout<<"Le target a "<<fighter.getMana()<<" de points de vie restant."<<endl;

}
}
