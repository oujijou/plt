#include "../engine.h"
#include "../state.h"
#include <iostream> 
#include <unistd.h>
#include <stdlib.h>
#include "Attaq.h"

using namespace engine;
using namespace state;
using namespace std;



Attaq::Attaq (state::Fighter& attaqer, state::Fighter& target):attaqer(attaqer),target(target)
{

}


void Attaq::execute (state::State& state){
    bool attaqIsPossible=false;

    if(attaqer.getStatus()!=DEAD &&attaqer.getStatus()!=SPECIAL){

        //Target
        cout<<"Attaq is possible"<<endl;
        //target.setHealth(50);
        float oldTargetHealth=target.getHealthPoints();
        

        //Attaq
        attaqer.fight(target, COUPDEPOING);
        

        //Display on console : State 
        cout<<"Le target avait "<<oldTargetHealth<<" points de vie."<<endl;
        cout<<"Le target a "<<target.getHealthPoints()<<" de points de vie restant."<<endl;

        
        if(target.getHealthPoints()==0){
            target.setStatus(DEAD);
            // animation dead
            cout << "Le target est mort." << endl;
            sleep(2);
           
        }

    }else if(attaqer.getStatus()==DEAD){
        cout<<"Already dead!"<<endl;
    }
}