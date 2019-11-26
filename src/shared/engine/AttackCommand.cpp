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
AttackCommand::AttackCommand (state::Fighter attacker, state::Fighter target):attacker(attacker),target(target)
{

}

//Functions

void AttackCommand::execute (state::State& state){
    cout << "execution is coming" << endl;
    if(attacker.getStatus()!=DEAD){
  
        //Target
        cout<<"Attack is coming!!"<<endl;
        float oldTargetHealth=target.getHealthPoints();
        
        int waitingTime=40000;
		string FigtherTarget = "";
		switch(attacker.getName()){
			case Flint: 
				FigtherTarget = "flint";
            break;
			case Kuro:
				FigtherTarget = "kuro";
            break;
			case Thork:
				FigtherTarget = "thork";
            break;
			case Seku:
				FigtherTarget = "seku";
            break;       
    }

        //Attack
             
		string FigtherAttacker = "";
		switch(attacker.getName()){
			case Flint: 
				FigtherAttacker = "flint";
            break;
        case Kuro:
            FigtherAttacker = "kuro";
            break;
        case Thork:
            FigtherAttacker = "thork";
            break;
        case Seku:
            FigtherAttacker = "seku";
            break;
        cout << "The " << FigtherAttacker << " will attack or try to attack the " << FigtherTarget << "." << endl;
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
