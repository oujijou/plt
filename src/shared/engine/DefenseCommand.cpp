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

 DefenseCommand::DefenseCommand (state::Fighter& isDefending):isDefending(isDefending)
 {

 }
 //Functions
 void DefenseCommand::execute (state::State& state){
    
    
     if(isDefending.getStatus()!=DEAD){
		
 		cout<<"Defense is coming!!"<<endl;
         
     isDefending.defend(isDefending);
		cout << "Le fighter est en mode" << isDefending.getStatus() << endl;
 }
 }
