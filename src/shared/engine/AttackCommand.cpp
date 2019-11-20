#include "../engine.h"
#include "../state.h"
#include <iostream> 
#include <unistd.h>
#include <stdlib.h>
#include "AttackCommand.h"

using namespace engine;
using namespace state;
using namespace std;



AttackCommand::AttackCommand (state::Fighter& attaqer, state::Fighter& target):attacker(attacker),target(target)
{

}


void AttackCommand::execute (state::State& state){
    
    if(attacker.getStatus()!=DEAD){

        //Target
        cout<<"Attack is coming!!"<<endl;
        
        float oldTargetHealth=target.getHealthPoints();
        
        //Attaq
        attacker.fight(target, COUPDEPOING); //for now only this attack is available
        

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