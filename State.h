//
// Created by roei on 14/01/2020.
//

#ifndef SECONDMILESTONE__STATE_H_
#define SECONDMILESTONE__STATE_H_
template<typename E>
class State {
  private:
    E state;
    int totalCost;
    State<E>* cameFrom;
  public:
    E GetState() const;
    int GetTotalCost() const;
    State<E> *GetCameFrom() const;

    State(E state, int total_cost, State<E> *came_from);
    State(E state);
};

template<typename E>
int State<E>::GetTotalCost() const {
    return totalCost;
}
template<typename E>
State<E> *State<E>::GetCameFrom() const {
    return cameFrom;
}

//thisCost is the cost of getting to this state from cameFrom State
template<typename E>
State<E>::State(E state, int thisCost, State<E> *came_from) : state(state), cameFrom(came_from) {
    totalCost = came_from->GetTotalCost() + thisCost;
}
template<typename E>
State<E>::State(E state):state(state) {

}
template<typename E>
E State<E>::GetState() const {
    return state;
}

#endif //SECONDMILESTONE__STATE_H_
