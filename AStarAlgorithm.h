//
// Created by roei on 14/01/2020.
//

#ifndef SECONDMILESTONE__ASTARALGORITHM_H_
#define SECONDMILESTONE__ASTARALGORITHM_H_

#include <unordered_map>
#include "Searcher.h"

template<typename S,typename E>
class AStarAlgorithm : public Searcher<S,E> {
private:
    unordered_map<State<E> *, State<E> *> closedMap;
public:
    AStarAlgorithm* clone() {
        return new AStarAlgorithm<S,E>();
    }

    string Search(Searchable<E> *problem) override {
        customPriorityQueue<E> *priorityQueue = Searcher<S,E>::myPriorityQueue;
        State<E> *start = problem->getInitialState();
        State<E> *n;

        //updating heuristic
        start->SetTotalCost(start->GetStateCost());

        start->setHeuristicCost(start->getTotalCost() + problem->calcHeuristic(start));

        //first we initial our queue with start state.
        priorityQueue->push(start);

        //we run while the queue is not empty.
        //int counter = 0;

        while (!priorityQueue->empty()) {

            // n is our algorithm buffer
            n = priorityQueue->top();
            priorityQueue->pop();

            //add n to closedMap , its tell us we already visited this state and no need to check it again.
            closedMap[n] = n;

            //increase evaluated nodes
            this->evaluatedNodes += 1;

            //if this the goal state we return the answer.
            if (problem->isGoalState(n)) {
                return this->translateSolution(n);
            }

            //otherwise we go through n successors
            //n all successeros
            vector<State<E> *> successors = problem->getAllPossibleStates(n);

            //iterate over n successors
            for(State<E>* s : successors) {

                // check if s is in the priority queue ,  and in the closeMap
                auto inMap = closedMap.find(s);
                //if we go into this if then s is not in both close and open.
                bool notInBoth = ((inMap == closedMap.end()) && !(Searcher<S,E>::myPriorityQueue->isInQueue(s)));
                if(notInBoth){
                    s->setCameFrom(n);
                    s->setHeuristicCost(n->getTotalCost() + s->GetStateCost() + problem->calcHeuristic(s));
                    s->SetTotalCost(n->getTotalCost() + s->GetStateCost());
                    //or this: s->SetTotalCost(n->getTotalCost() + s->GetStateCost() + s->getHeuristicCost());
                    Searcher<S,E>::myPriorityQueue->push(s);
                }
                    //means that s is in closedMap , and we can skip
                else if(inMap != closedMap.end()){
                    continue;
                }
                    //if we get here , its means he is in the open queue and not in closedMap
                else {
                    //saving routs values to compare
                    //if newTotalCost is less then prev , we update our rout
                    if (n->getTotalCost() + s->getTotalCost() + problem->calcHeuristic(s) <= s->getHeuristicCost()) {
                        s->setHeuristicCost(n->getTotalCost() + s->getTotalCost() + problem->calcHeuristic(s));
                        Searcher<S,E>::myPriorityQueue->upDateQueue(s,n->getTotalCost() + s->getTotalCost());
                        //update we came to s from n
                        s->setCameFrom(n);
                    }
                }
            }
        }
        return "No solution";
    }

    int getEvaluatedNodes() override {
        return this->evaluatedNodes;
    }
    //return a string for this class.
    string toString() override {
        return "AStar";
    }
};

#endif //SECONDMILESTONE__ASTARALGORITHM_H_
