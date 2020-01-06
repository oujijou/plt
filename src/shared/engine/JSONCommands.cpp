#include "JSONCommands.h"
//#include "../../../extern/jsoncpp-1.8.0/json/json.h"

#include "AttackCommand.h"
#include "ChangeRound.h"
#include "DefenseCommand.h"
#include "RechargeCommand.h"

namespace engine
{
    std::unique_ptr<Command>& JSONCommands::toCommand(std::string jsonCommand)
    {
        //Json::Value root;
    }

    std::string JSONCommands::toJSON(std::unique_ptr<Command>& command)
    {
        std::string json = "";
        json += "{\n\"type\":\"" + command->type + "\",\n";

        json += command->toJSON();

        json += "\n}";

        return json;
    }
}