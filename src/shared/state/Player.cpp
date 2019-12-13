#include "Player.h"

using namespace std;
using namespace state;


Player::Player()
{
   
}


Player::Player(int id)
{
    this->id = id;
    this->playerName =  "Player " + to_string(id);
}

Player::Player(int id, string name)
{
    this->id = id;
    this->playerName = name;
}

Player::Player(bool IA, std::string& playerName, std::shared_ptr<Fighter> fighter)
{
    this->IA = IA;
    this->playerName = playerName;
    this->fighter = fighter;
}

void Player::setFighter(std::shared_ptr<Fighter> fighter)
{
    this->fighter = fighter;
}

std::shared_ptr<Fighter> Player::getFighter()
{
    return fighter;
}

 std::string Player::setPlayerName (std::string playerName)
 {
    this->playerName = playerName;
 }

 std::string Player::getPlayerName ()
 {
    return playerName;
 }

 bool Player::setIA (bool IA)
 {
    this->IA = IA;
 }

 bool Player::getIA()
 {
    return IA;
 }



void Player::setID(int id)
{
    this->id = id;
}

int Player::getID()
{
    return id;
}

std::shared_ptr<Player> Player::copy()
{
    std::shared_ptr<Player> result = make_shared<Player>();
    result->IA = IA;
    result->id = id;
    result->playerName = playerName;
    result->fighter = fighter->copy();
    return result;
}