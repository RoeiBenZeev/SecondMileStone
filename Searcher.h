//
// Created by roei on 14/01/2020.
//

#ifndef SECONDMILESTONE__SEARCHER_H_
#define SECONDMILESTONE__SEARCHER_H_

#include <queue>
#include "ISearcher.h"
#include "customPriorityQueue.h"
template<typename E>
class Searcher : public ISearcher<E> {

  protected:
    customPriorityQueue<E>* myPriorityQueue = new customPriorityQueue<E>();
    int evaluatedNodes;
    string translateSolution(State<E>* state) {
        State<E>* currentState = state;
        string buffer = "";
        string solution = "";
        int i, j, cost;
        while(currentState->getCameFrom() != nullptr) {
            // calculating i,j to find where came form.
            i = currentState->GetState()->GetRow() - currentState->getCameFrom()->GetState()->GetRow();
            j= currentState->GetState()->GetColumn() - currentState->getCameFrom()->GetState()->GetColumn();
            cost = currentState->getTotalCost();

            //means we went down in the algorithm
            if( i == 1) {
                buffer = "Down (" + to_string(cost) + "), ";
                solution = buffer + solution;
            }
                //means we went up in the algorithm
            else if( i == -1) {
                buffer = "Up (" + to_string(cost) + "), ";
                solution = buffer + solution;
            }
                //means we went right in the algorithm
            else if( j == 1) {
                buffer = "Right (" + to_string(cost) + "), ";
                solution = buffer + solution;
            }
                //means we went left in the algorithm
            else if( j == -1) {
                buffer = "Left (" + to_string(cost) + "), ";
                solution = buffer + solution;
            }
            //moving to previouse state
            currentState = currentState->getCameFrom();
        }
        //delete the last coma and space chars
        solution.pop_back();
        solution.pop_back();
        return solution;
    }

  public:
    int getEvaluatedNodes() override {
        return this->evaluatedNodes;
    }

};

#endif //SECONDMILESTONE__SEARCHER_H_
