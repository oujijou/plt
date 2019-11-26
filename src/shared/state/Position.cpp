#include "Position.h"

using namespace std;
using namespace state;

Position::Position()
{

}

Position::Position(int x,int y){
    this->x=x;
    this->y=y;
}


void Position::setX(int x)
{
    this->x=x;
}

void Position::setY(int y)
{
    this->y=y;
}

int Position::getX()
{
    return x;
}

int Position::getY()
{
    return y;
}








Position::~Position()
{
    
}