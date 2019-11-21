#include "../engine.h"
#include "../state.h"
#include <iostream> 
#include <unistd.h>
#include <stdlib.h>
#include "DefenseCommand.h"


//Constructor

DefenseCommand::DefenseCommand (state::Fighter& fighter):fighter(fighter)
{

}
//Functions
void DefenseCommand::execute (state::State& state){
    
    
    if(attacker.getStatus()!=DEAD){
		
		cout<<"Defense is coming!!"<<endl;
        float oldTargetHealth=target.getHealthPoints();
        
        //Target
        int waitingTime=40000;
		string entityNameTarget = "";
		switch(attacker.getName()){
			case Flint: 
				entityNameTarget = "flint";
            break;
			case Kuro:
				entityNameTarget = "kuro";
            break;
			case Thork:
				entityNameTarget = "thork";
            break;
			case Seku:
				entityNameTarget = "seku";
            break;       
    }

        //Attack
        attacker.fight(target, COUPDEPOING); //for now only this attack is available
       
		string entityNameAttacker = "";
		switch(attacker.getName()){
			case Flint: 
				entityNameAttacker = "flint";
            break;
        case Kuro:
            entityNameAttacker = "kuro";
            break;
        case Thork:
            entityNameAttacker = "thork";
            break;
        case Seku:
            entityNameAttacker = "seku";
            break;
        cout << "The " << entityNameAttacker << " will attack or try to attack the " << entityNameTarget << "." << endl;
           
    }
        
        cout<<"Defense is coming!!"<<endl;
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
    fighter.defend(fighter);
}
}
