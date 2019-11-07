#include "Observable.h"
#include <algorithm> // find

using namespace std;

namespace state{

    Observable::~Observable()
    {

    }

    void Observable::registerObserver(IObserver *o)
    {
        observers.push_back(o); //{1,2,3} -> {1,2,3,4}
    }

    void Observable::unregisterObserver(IObserver *o)
    {
        observers.erase(find(observers.begin(),observers.end(),o));
    }

    void Observable::unregisterObservers()
    {
        observers.clear();
    }

    const void Observable::notifyObservers(const state::StateEvent& e, const State& state) // State state
    {
        for(auto observer:observers)
        {
           observer->stateChanged(e, state);//state
        }
    }
    
    
}