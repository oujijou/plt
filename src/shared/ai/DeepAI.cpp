#include "DeepAI.h"

#include "../engine/AttackCommand.h"
#include "../engine/DefenseCommand.h"
#include "../engine/RechargeCommand.h"

#include <iostream>

using namespace ai;

struct comb
{
    int firstChoice;
    int secondChoice;
    int thirdChoice;
    float score;
};

DeepAI::DeepAI(int AiID)
{
    ArtificialId = AiID;
}

void attack(std::shared_ptr<engine::Engine> engine, int attacker, int target)
{
    engine::AttackCommand attackCommand(engine->getState().getPlayerList()[attacker]->getFighter(), 
        engine->getState().getPlayerList()[target]->getFighter());
    std::unique_ptr<engine::Command> ptr_attack (new engine::AttackCommand(attackCommand));
    engine->addCommand(0, move(ptr_attack));
    engine->update();
}

void defend(std::shared_ptr<engine::Engine> engine, int target)
{
    engine::DefenseCommand defenseCommand(engine->getState().getPlayerList()[target]->getFighter());
    std::unique_ptr<engine::Command> ptr_defense (new engine::DefenseCommand(defenseCommand));
    engine->addCommand(0, move(ptr_defense));
    engine->update();
}

void recharge(std::shared_ptr<engine::Engine> engine, int target)
{
    engine::RechargeCommand rechargeCommand(engine->getState().getPlayerList()[target]->getFighter());
    std::unique_ptr<engine::Command> ptr_recharge (new engine::RechargeCommand(rechargeCommand));
    engine->addCommand(0, move(ptr_recharge));
    engine->update();
}

float evaluateSituation(std::shared_ptr<engine::Engine> engine, int aiPlayer, int humanPlayer)
{
    float score = 0;

    score += (float) engine->getState().getPlayerList()[aiPlayer]->getFighter()->getHealthPoints() * 1.25;
    score += (float) engine->getState().getPlayerList()[aiPlayer]->getFighter()->getMana() * 0.5;

    score -= (float) engine->getState().getPlayerList()[humanPlayer]->getFighter()->getHealthPoints() * 1.25;
    score -= (float) engine->getState().getPlayerList()[humanPlayer]->getFighter()->getMana() * 0.5;

    return score;
}

comb getChoiceComb(std::shared_ptr<engine::Engine> engine, int deepness)
{
    // Calculate every possible combination for the AI
    bool firstRunB = true;
    comb bestCaseScenario;
    for (int a = 0; a < 3; a++)
    {
        for (int b = 0; b < 3; b++)
        {
            for (int c = 0; c < 3; c++)
            {
                std::shared_ptr<engine::Engine> engineCopy = engine->copy();
                engineCopy->realEngine = false;
                switch (a)
                {
                case 0:
                    attack(engineCopy, 0, 1);
                    break;
                case 1:
                    defend(engineCopy, 0);
                    break;
                case 2:
                    recharge(engineCopy, 0);
                    break;
                }
                switch (b)
                {
                case 0:
                    attack(engineCopy, 0, 1);
                    break;
                case 1:
                    defend(engineCopy, 0);
                    break;
                case 2:
                    recharge(engineCopy, 0);
                    break;
                }
                switch (c)
                {
                case 0:
                    attack(engineCopy, 0, 1);
                    break;
                case 1:
                    defend(engineCopy, 0);
                    break;
                case 2:
                    recharge(engineCopy, 0);
                    break;
                }

                // Calculate every possible combination for the player
                bool firstRunW = true;
                comb worstCaseScenario; // We get the best moves the player can do.
                for (int a2 = 0; a2 < 3; a2++)
                {
                    for (int b2 = 0; b2 < 3; b2++)
                    {
                        for (int c2 = 0; c2 < 3; c2++)
                        {
                            std::shared_ptr<engine::Engine> engineCopy2 = engineCopy->copy();
                            engineCopy2->realEngine = false;
                            switch (a)
                            {
                            case 0:
                                attack(engineCopy, 1, 0);
                                break;
                            case 1:
                                defend(engineCopy, 1);
                                break;
                            case 2:
                                recharge(engineCopy, 1);
                                break;
                            }
                            switch (b)
                            {
                            case 0:
                                attack(engineCopy, 1, 0);
                                break;
                            case 1:
                                defend(engineCopy, 1);
                                break;
                            case 2:
                                recharge(engineCopy, 1);
                                break;
                            }
                            switch (c)
                            {
                            case 0:
                                attack(engineCopy, 1, 0);
                                break;
                            case 1:
                                defend(engineCopy, 1);
                                break;
                            case 2:
                                recharge(engineCopy, 1);
                                break;
                            }
                            
                            if (evaluateSituation(engineCopy2, 0, 1) < worstCaseScenario.score && !firstRunW)
                            {
                                continue;
                            }
                            float score;
                            if (deepness <= 0)
                                score = evaluateSituation(engineCopy2, 0, 1);
                            else
                            {
                                score = getChoiceComb(engineCopy2, deepness - 1).score;
                            }
                            
                            if (firstRunW)
                            {
                                worstCaseScenario = { a, b, c, score };
                                firstRunW = false;
                            }
                            else
                            {
                                if (score < worstCaseScenario.score)
                                {
                                    worstCaseScenario = { a, b, c, score };
                                }
                            }
                        }
                    }
                }

                if (firstRunB)
                {
                    bestCaseScenario = worstCaseScenario;
                    firstRunB = false;
                }
                else
                {
                    if (worstCaseScenario.score > bestCaseScenario.score)
                    {
                        bestCaseScenario = worstCaseScenario;
                    }
                }
            }
        }
    }
    return bestCaseScenario;
}

void DeepAI::run(std::shared_ptr<engine::Engine> engine)
{
    int deepness = 1;
    std::cout << "Calculating combinations, please wait (this may take a long time)." << std::endl;
    std::cout.setstate(std::ios_base::failbit);
    comb todo = getChoiceComb(engine, deepness);
    std::cout.clear();
    std::cout << evaluateSituation(engine, 0, 1) << std::endl;
    std::cout << todo.firstChoice << " " << todo.secondChoice << " " << todo.thirdChoice << std::endl;
    switch (todo.firstChoice)
    {
    case 0:
        attack(engine, 0, 1);
        break;
    case 1:
        defend(engine, 0);
        break;
    case 2:
        recharge(engine, 0);
        break;
    }
    switch (todo.secondChoice)
    {
    case 0:
        attack(engine, 0, 1);
        break;
    case 1:
        defend(engine, 0);
        break;
    case 2:
        recharge(engine, 0);
        break;
    }
    switch (todo.thirdChoice)
    {
    case 0:
        attack(engine, 0, 1);
        break;
    case 1:
        defend(engine, 0);
        break;
    case 2:
        recharge(engine, 0);
        break;
    }

    engine->realEngine = true;
    engine->update();
    if (engine->getState().getPlayerList()[1]->getFighter()->getHealthPoints() < 0 || engine->getState().getPlayerList()[0]->getFighter()->getHealthPoints() < 0)
    {
        std::cout << "ENDING GAME !" << std::endl;
        exit(0);
    }
}