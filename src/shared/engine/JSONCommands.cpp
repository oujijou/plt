#include "JSONCommands.h"
//#include "../../../extern/jsoncpp-1.8.0/json/json.h"

#include "AttackCommand.h"
#include "ChangeRound.h"
#include "DefenseCommand.h"
#include "RechargeCommand.h"

#include <iostream>

namespace engine
{
    std::unique_ptr<Command>& JSONCommands::toCommand(std::string jsonCommand)
    {
        //Json::Value root;
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