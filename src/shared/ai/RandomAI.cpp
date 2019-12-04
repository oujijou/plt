#include "RandomAI.h"
#include "../engine.h"
#include "../state.h"
#include "../ai.h"
#include <iostream>
#include <unistd.h>

using namespace state;
using namespace engine;
using namespace std;
using namespace ai;


RandomAI::RandomAI (int AiID){
   ArtificialId=AiID;
}

void RandomAI::run(engine::Engine engine)
{
   if(engine.getState().getCurrentPlayerID()== ArtificialId)
   {
      int randomAction;
      while (engine.getState().getPlayerList()[ArtificialId]->getFighter()->getStatus()!=DEAD)
      {
         engine.getState().getPlayerList()[ArtificialId]->getFighter()->setStatus(WAITING);

         // initialize random seed:
         srand(time(NULL)); 
         randomAction = rand()%3;
         //cout << "random action is " <<randomAction << endl;
         
         int waitingTime = 3;
         Player ennemy;
         if(randomAction==0) //Attack
         {
            cout << "IA is attacking" <<endl;
           
            
            //AI is attacking
            AttackCommand attack(engine.getState().getPlayerList()[ArtificialId]->getFighter(),
                                 engine.getState().getPlayerList()[1]->getFighter());
            unique_ptr<Command> ptr_attack (new AttackCommand(attack));
            engine.addCommand(0, move(ptr_attack));
            engine.update();
            // cout << "\n" <<endl;
            // sleep(waitingTime);


         }
         else if(randomAction == 1) //Defense
         {
            cout << "IA is defending" <<endl;
            DefenseCommand defense(engine.getState().getPlayerList()[ArtificialId]->getFighter());
            unique_ptr<Command> ptr_defense (new DefenseCommand(defense));
            engine.addCommand(0, move(ptr_defense));
            engine.update();
            //cout << "\n" <<endl;
            //sleep(waitingTime);
         }
         else{ //Recharging
            cout << "IA is recharging" <<endl;
            RechargeCommand recharge(engine.getState().getPlayerList()[ArtificialId]->getFighter());
            unique_ptr<Command> ptr_recharge (new RechargeCommand(recharge));
            engine.addCommand(0, move(ptr_recharge));
            engine.update();
            //cout << "\n" <<endl;
            //sleep(waitingTime);
         }
      }
   }
}


