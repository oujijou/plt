#include "JSONCommands.h"
#include "../../../extern/jsoncpp-1.8.0/json/json.h"

#include "AttackCommand.h"
#include "ChangeRound.h"
#include "DefenseCommand.h"
#include "RechargeCommand.h"

#include <iostream>
#include <sstream>

namespace engine
{
    std::unique_ptr<Command>& JSONCommands::toCommand(std::string jsonCommand)
    {
        //Json::Value root;
        
    }

    std::vector<std::shared_ptr<Command>> JSONCommands::toCommands(std::string replayFile, std::shared_ptr<Engine> engine)
    {
        std::vector<std::shared_ptr<Command>> result;
        Json::Value root;
        std::stringstream s;
        s << replayFile;
        s >> root;
        for (Json::Value v : root)
        {
            std::cout << v << std::endl;
            if (v.getMemberNames().size() > 0)
            {
                std::string type = v.get("type", Json::nullValue).asString();
                Json::Value commandValue = v.get("command", Json::nullValue);
                int target = commandValue.get("target", Json::Value(0)).asInt();
                int attacker = commandValue.get("attacker", Json::Value(0)).asInt();
                if (type == "attack")
                {
                    AttackCommand attackCommand(engine->getState().getPlayerList()[attacker]->getFighter(), 
                                                engine->getState().getPlayerList()[target]->getFighter());
                    std::shared_ptr<Command> ptr_attack (new AttackCommand(attackCommand));
                    result.push_back(ptr_attack);
                }
                if (type == "defense")
                {
                    DefenseCommand defenseCommand(engine->getState().getPlayerList()[1]
                                                        ->getFighter());
                    std::shared_ptr<Command> ptr_defense (new DefenseCommand(defenseCommand));
                    result.push_back(ptr_defense);
                }
                if (type == "recharge")
                {
                    RechargeCommand rechargeCommand(engine->getState().getPlayerList()[target]
                                                        ->getFighter());
                    std::shared_ptr<Command> ptr_recharge (new RechargeCommand(rechargeCommand));
                    result.push_back(ptr_recharge);
                }
            }
        }

        return result;
    }

    std::string JSONCommands::toJSON(std::unique_ptr<Command>& command)
    {
        if (command.get() == nullptr)
        {
            std::cout << "Warning : Tried to JSONify a null pointer." << std::endl;
            return "";
        }

        std::string json = "";
        std::cout << "OK" << std::endl;
        json += "{\n\"type\":\"" + command->type + "\",\n";

        json += command->toJSON();

        json += "\n}";

        return json;
    }
}