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


// void RandomAI::run (engine::Engine engine){
//     if(engine.getState().getCurrentPlayerID()==AiId){
//         int randomAction; // defense, attack or recharge
		
//         int cantAttack = false;
        
//         int waitingTime=3;
//         AI_Id=AI_Id-1;


          
//         while (engine.getState().getPlayerList()[AI_Id].getFighter().getStatus()!=DEAD && engine.getState().getPlayerList()[AI_Id].getFighter().getStatus()!=WAITING)
//         {
//             engine.getState().getPlayerList()[AI_Id].getFighter().setStatus(WAITING);

//             // initialize random seed: 
//             srand(time(NULL));
//             if (cantAttack == true){
//                 randomAction = 2;   //EndAction=2
//             }
//             else if (notAllowedMove == true && notAllowedAttack == false){
//                 randomAction = rand()%2+1;  //EndAction=2 or Attack=1
//             }
//             else if (notAllowedMove == false && notAllowedAttack == true){
//                 randomAction = rand()%2;    // Move=0 or EndAction=2
//                 if(randomAction == 1){
//                     randomAction = 2;
//                 }
//             }
//             else{randomAction = rand()%3;}//EndAction=2 or Attack=1 or Move=0

//             // 0 : Move
//             if (randomAction == 0 && engine.getState().getPlayerList()[AI_Id]->getMobileEntityList()[i]->getMovementLeft()!= 0){
//                 //Initialize a liste of allowed Move
//                 std::vector<Position> allowedMoveList =engine.getState().getPlayerList()[AI_Id]->getMobileEntityList()[i]->allowedMove(engine.getState());
//                 if (allowedMoveList.size() != 0){
//                     srand(time(NULL));
//                     randomPosition = rand()%allowedMoveList.size();
                    
//                     // Move Command
//                     Move movement (*engine.getState().getPlayerList()[AI_Id]->getMobileEntityList()[i], allowedMoveList[randomPosition]);
//                     unique_ptr<Command> ptr_movement (new Move(movement));
//                     engine.addCommand(0, move(ptr_movement));
//                     engine.update();//update engine will use state to notify render about changes

//                     notAllowedAttack = false;
//                     sleep(waitingTime);
//                 }
//                 else{notAllowedMove = true;}
//             }

//             // 1 : Attack
//             else if (randomAction == 1){
//                 //Initialize a list with all attack allowed positions
//                 std::vector<Position> allowedAttackPositionList = engine.getState().getPlayerList()[AI_Id]->getMobileEntityList()[i]->allowedAttack(engine.getState());

//                 if (allowedAttackPositionList.size() !=0){
//                     srand(time(NULL));
//                     randomAttackPosition = rand()%allowedAttackPositionList.size();
                                        
//                     // Check if there are units on the random Attack Position
//                     int target=engine.getState().isOccupied(allowedAttackPositionList[randomAttackPosition].getX(),allowedAttackPositionList[randomAttackPosition].getY());
//                     if (target ==true){
//                         // Commande d'attaque
//                         Attack attack(*engine.getState().getPlayerList()[AI_Id]->getMobileEntityList()[i], *engine.getState().getMobileEntity(allowedAttackPositionList[randomAttackPosition].getX(),allowedAttackPositionList[randomAttackPosition].getY()));
//                         unique_ptr<Command> ptr_attack (new Attack(attack));
//                         engine.addCommand(0, move(ptr_attack));
//                         engine.update();
//                         notAllowedMove = false;
//                         sleep(waitingTime);
//                     }
//                 }
//                 else{notAllowedAttack = true;}				
//             }

//             // 2 : EndEntityRound
//             else if (randomAction == 2){
//                 EndEntityRound endAction(*engine.getState().getPlayerList()[AI_Id]->getMobileEntityList()[i]);
//                 unique_ptr<Command> ptr_endAction (new EndEntityRound(endAction));
//                 engine.addCommand(0, move(ptr_endAction));
//                 engine.update();
//                 sleep(waitingTime);
//             }
//         }
        
    
//     }

// }



