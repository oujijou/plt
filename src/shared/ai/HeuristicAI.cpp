#include "HeuristicAI.h"
#include <iostream>
#include "RandomAI.h"
#include "../engine.h"
#include "../state.h"
#include "../ai.h"
#include <unistd.h>

using namespace std;
using namespace engine;
using namespace state;
using namespace ai;

HeuristicAI::HeuristicAI(int AiID)
{
    ArtificialId=AiID;
}

void HeuristicAI::run(std::shared_ptr<Engine> engine)
{
      cout << "IA not dead" <<endl;
        if(engine->getState().getCurrentPlayerID() == ArtificialId)
        {  
            while (engine->getState().getPlayerList()[ArtificialId]->getFighter()->getStatus()!=DEAD)
            { 
                cout << "IA has to play" <<endl;
                //if the opponent is defending
                // if(engine->getState().getPlayerList()[!engine->getState().getCurrentPlayerID()]->getFighter()->getStatus()== DEFENSE)
                // {

                // }
                // If AI is not in danger
                //if AI can't attack so he'll defend if opponent has enough mana or recharge if he hasn't
                if (engine->getState().getPlayerList()[ArtificialId]->getFighter()->getHealthPoints()>20)
                {
                    cout << "IA 1" <<endl;
                    if(engine->getState().getPlayerList()[ArtificialId]->getFighter()->getMana()<30)
                    {   
                        cout << "IA 2" <<endl;
                        
                        if(engine->getState().getPlayerList()[!ArtificialId]->getFighter()->getMana()>=30){
                            DefenseCommand defenseCommand(engine->getState().getPlayerList()[ArtificialId]->getFighter());
                            unique_ptr<Command> ptr_defense (new DefenseCommand(defenseCommand));
                            engine->addCommand(0, move(ptr_defense));

                            ChangeRound changeRound(engine->getState().getPlayerList()[0]->getFighter());
                            unique_ptr<Command> ptr_change (new ChangeRound(changeRound));
                            engine->addCommand(1, move(ptr_change));
                
                            engine->update();


                        }else if(engine->getState().getPlayerList()[!ArtificialId]->getFighter()->getMana()<30){
                            RechargeCommand rechargeCommand(engine->getState().getPlayerList()[engine->getState().getCurrentPlayerID()]
                                                            ->getFighter());
                            unique_ptr<Command> ptr_recharge (new RechargeCommand(rechargeCommand));
                            engine->addCommand(0, move(ptr_recharge));

                             ChangeRound changeRound(engine->getState().getPlayerList()[0]->getFighter());
                            unique_ptr<Command> ptr_change (new ChangeRound(changeRound));
                            engine->addCommand(1, move(ptr_change));
                
                            engine->update();
                        }
                    }
                    //if AI can attack he will attack
                    else if(engine->getState().getPlayerList()[ArtificialId]->getFighter()->getMana()>=30)
                    {   //AI will attack as long as he got enough energy
                    cout << "IA attack" <<endl;

                    AttackCommand attackCommand(engine->getState().getPlayerList()[ArtificialId]->getFighter(), 
                                                engine->getState().getPlayerList()[1]->getFighter());
                    unique_ptr<Command> ptr_attack (new AttackCommand(attackCommand));
                    engine->addCommand(0, move(ptr_attack));

                    ChangeRound changeRound(engine->getState().getPlayerList()[0]->getFighter());
                    unique_ptr<Command> ptr_change (new ChangeRound(changeRound));
                    engine->addCommand(1, move(ptr_change));
        
                    engine->update();
                    // cout << "\n" <<endl;
                    //sleep(waitingTime);
                    break;

                       
                    }
                }//if AI is in danger -> defense
                else if (engine->getState().getPlayerList()[ArtificialId]->getFighter()->getHealthPoints()<=20)
                {
                    DefenseCommand defenseCommand(engine->getState().getPlayerList()[ArtificialId]->getFighter());
                    unique_ptr<Command> ptr_defense (new DefenseCommand(defenseCommand));
                    engine->addCommand(0, move(ptr_defense));

                    ChangeRound changeRound(engine->getState().getPlayerList()[0]->getFighter());
                    unique_ptr<Command> ptr_change (new ChangeRound(changeRound));
                    engine->addCommand(1, move(ptr_change));
        
                    engine->update();
                }
            }
        }
    
}