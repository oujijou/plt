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
    //cout << "execution is coming" << endl;
    int waitingTime = 5;
    float oldTargetHealth=target.getHealthPoints();
    if(attacker.getStatus()!=DEAD){
        
        //Target
        //cout<<"Attack is coming!!"<<endl;
       

        //Fighting
        attacker.fight(target, COUPDEPOING);
            //attacking animation
        //int waitingTime=40000;
        float targetHealthPoints = target.getHealthPoints();
        string attackerName = "";
        string targetName = "";

        switch(attacker.getName()){
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

        switch(target.getName()){
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

        cout << attackerName << " will attack or try to attack the " << targetName << "." << endl;
        cout<<targetName << " had "<<oldTargetHealth<<" health points."<<endl;
        cout<<targetName<< " has " << targetHealthPoints <<" health points now."<<endl;

        

        attacker.setStatus(WAITING);


         if(target.getHealthPoints()==0){
            target.setStatus(DEAD);
            // animation dead
            cout << "The opponent is dead. You win! " << endl;
            sleep(2);
        }
    }
    else if(attacker.getStatus()==DEAD){
        cout<<"Already dead!"<<endl;
    }else if(attacker.getStatus()==WAITING){
        string attackerName = "";
        switch(attacker.getName()){
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
