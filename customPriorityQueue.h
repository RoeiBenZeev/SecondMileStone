//
// Created by roei on 16/01/2020.
//

#ifndef SECONDMILESTONE__CUSTOMPRIORITYQUEUE_H_
#define SECONDMILESTONE__CUSTOMPRIORITYQUEUE_H_
#include <queue>
#include <algorithm>
#include "State.h"
template <typename E>
struct CompareStates {
  bool operator()(State<E>* const &s1, State<E>* const &s2) {
      // return "true" if "s1" is ordered before "s2", for example:
      bool b = s1->getTotalCost() > s2->getTotalCost();
      return (b);
  }
};
template <typename E>
class customPriorityQueue : public std::priority_queue<State<E>*, std::vector<State<E>*>,CompareStates<E>> {
  public:
    /*
     * If value is in the queue the function remove him , and return true
     */
    bool remove(const State<E>* value) {
        auto it = std::find(this->c.begin(), this->c.end(), value);
        if (it != this->c.end()) {
            this->c.erase(it);
            std::make_heap(this->c.begin(), this->c.end(), this->comp);
            return true;
        } else {
            return false;
        }
    }
    /*
     * this function is check if an items is in the queue
     */
    bool isInQueue(const State<E>* value) {
        auto it = std::find(this->c.begin(), this->c.end(), value);
        if (it != this->c.end()) {
            return true;
        } else {
            return false;
        }
    }
    /*
     * Thr function first check if the queue contains the item , if it does , its remove
     * him from queue , and add him with new value. its works because we work with pointers.
     */
    bool upDateQueue(State<E>* value, int newTotalCost) {
        //we update our items value.
        value->SetTotalCost(newTotalCost);
        //we remove the item from the queue if there, and add to put in right place.
        auto it = std::find(this->c.begin(), this->c.end(), value);
        if (it != this->c.end()) {
            this->c.erase(it);
            this->c.push_back(value);
            std::make_heap(this->c.begin(), this->c.end(), this->comp);
            return true;
        } else {
            return false;
        }
    }
};

#endif //SECONDMILESTONE__CUSTOMPRIORITYQUEUE_H_
