#include "StateEvent.h"

using namespace std;
using namespace state;

StateEvent ::StateEvent (StateEventID se): stateEventID(se)
{

}

void StateEvent::setStateEventID (StateEventID newID)
{
    stateEventID = newID;
}