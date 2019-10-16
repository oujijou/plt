#include "Observable.h"
#include <algorithm> // find

namespace state{

    Observable::~Observable()
    {

    }

    void Observable::registerObserver(Observer *o)
    {
        this->observers.push_back(o); //{1,2,3} -> {1,2,3,4}
    }

    void Observable::unregisterObserver(Observer *o)
    {
        observers.erase(find(observers.begin(),observers.end(),o));
    }

    void Observable::unregisterObservers()
    {
        observers.clear();
    }

    const void Observable::notifyObservers(const Event &e) // State state
    {
        for(auto o:observers)
        {
           //o->stateChanged(e, state);//state
        }
    }
    
    
}