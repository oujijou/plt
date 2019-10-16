#include "State.h"

namespace state{

    State::State(){

    }

    Fighter State::getFighter(){
        return fighter1;
    }

    Fighter State::setFighter(Fighter fighter1){
        this->fighter1= fighter1;
    }

}