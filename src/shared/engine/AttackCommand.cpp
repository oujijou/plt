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
AttackCommand::AttackCommand (state::Fighter& attacker, state::Fighter& target):attacker(attacker),target(target)
{

}

//Functions

void AttackCommand::execute (state::State& state){
    
    if(attacker.getStatus()!=DEAD){
  
        //Target
        cout<<"Attack is coming!!"<<endl;
        float oldTargetHealth=target.getHealthPoints();
        
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
        bool attack = true;
        // if(attack){
        //         attacker.setX(destination.getX());
        //         selectedUnit.setY(destination.getY());
        //         selectedUnit.setMovementLeft(selectedUnit.getMovementLeft()-1);
        //         state.getCursor().setX(destination.getX());
        //         state.getCursor().setY(destination.getY());

        
        if(target.getStatus()==DEFENSE){
            attacker.fight(target, COUPDEPOING);
            attacker.setHealthPoints(attacker.getHealthPoints()+10); //for now only this attack is available
		}
		else{
			attacker.fight(target, COUPDEPOING);
		}
    }

        //Display on console : State 
        cout<<"Le target avait "<<oldTargetHealth<<" points de vie."<<endl;
        cout<<"Le target a "<<target.getHealthPoints()<<" de points de vie restant."<<endl;

        if(target.getHealthPoints()==0){
            target.setStatus(DEAD);
            // animation dead
            cout << "Le target est mort." << endl;
            sleep(2);
        }
    
    }else if(attacker.getStatus()==DEAD){
        cout<<"Already dead!"<<endl;
    }
}
