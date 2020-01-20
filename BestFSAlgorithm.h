//
// Created by roei on 14/01/2020.
//

#ifndef SECONDMILESTONE__BESTFSALGORITHM_H_
#define SECONDMILESTONE__BESTFSALGORITHM_H_

#include <unordered_map>
#include "Searcher.h"
#include "customPriorityQueue.h"
template <typename S,typename E>
class BestFSAlgorithm : public Searcher<S,E> {
    unordered_map<State<E>*,State<E>*> closedMap;

  public:
    /*
     * search function implements beast first search algorithm , which is a searching algorithm for
     * lowest cost path in positive graph.
     */
    string Search(Searchable<E>* problem) override {
        State<E>* n;
        //first we initial our queue with start state.
        Searcher<S,E>::myPriorityQueue->push(problem->getInitialState());
        //we run while the queue is not empty.
        int counter = 0;
        while(!Searcher<S,E>::myPriorityQueue->empty()) {
            // n is our algorithm buffer
            n = Searcher<S,E>::myPriorityQueue->top();
            Searcher<S,E>::myPriorityQueue->pop();
            //increase evaluated nodes
            this->evaluatedNodes += 1;
            //add n to closedMap , its tell us we already visited this state and no need to check it again.
            closedMap[n] = n;
            //if this the goal state we return the answer.
            if(problem->isGoalState(n)) {
                return Searcher<S,E>::translateSolution(n);
            }
            //otherwise we go threw n successors
            else {
                //n all successeros
                vector<State<E>*> successors = problem->getAllPossibleStates(n);
                //iterate over n successors
                for(State<E>* s : successors) {
                    /*
                     * check if s is in the priority queue ,  and in the closeMap
                     * */
                    auto inMap = closedMap.find(s);
                    //if we go into this if then s is not in both close and open.
                    bool notInBoth = !(inMap != closedMap.end()) && !(Searcher<S,E>::myPriorityQueue->isInQueue(s));
                    if(notInBoth){
                        s->setCameFrom(n);
                        s->SetTotalCost(n->getTotalCost() + s->GetStateCost());
                        Searcher<S,E>::myPriorityQueue->push(s);
                    }
                    //means that s is in closedMap , and we can skip
                    else if(inMap != closedMap.end()){
                        continue;
                    }
                    //if we get here , its means he is in the open queue and not in closedMap
                    else {
                        //saving routs values to compare
                        int prevTotalCost = s->getTotalCost();
                        int newTotalCost = n->getTotalCost() + s->GetStateCost();
                        //if newTotalCost is less then prev , we update our rout
                        if (newTotalCost < prevTotalCost) {
                            Searcher<S,E>::myPriorityQueue->upDateQueue(s,newTotalCost);
                            //update we came to s from n
                            s->setCameFrom(n);
                        }
                    }
                }
            }
        }
        //todo delete me
        //return "aaaaa";
    }
    /*
     * make a clone of this object.
     */
    ISearcher<S,E> *clone() override {
        return new BestFSAlgorithm<S,E>;
    }
};


#endif //SECONDMILESTONE__BESTFSALGORITHM_H_
