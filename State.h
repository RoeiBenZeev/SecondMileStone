//
// Created by roei on 14/01/2020.
//

#ifndef SECONDMILESTONE__STATE_H_
#define SECONDMILESTONE__STATE_H_
template<typename E>
class State {
    E state;
    int totalCost;
    State<E>* cameFrom;
};

#endif //SECONDMILESTONE__STATE_H_
