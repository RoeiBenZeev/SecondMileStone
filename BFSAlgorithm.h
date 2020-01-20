//
// Created by roei on 14/01/2020.
//

#ifndef SECONDMILESTONE__BFSALGORITHM_H_
#define SECONDMILESTONE__BFSALGORITHM_H_

#include <unordered_map>
#include "Searcher.h"

template<typename E>
class BFSAlgorithm : public ISearcher<E> {
private:
int evaluatedNodes = 0;
    unordered_map<State<E> *, State<E> *> closed;
    queue<State<E> *> queueBFS;
    queue<State<E> *> queueBFS_TESTER; // TODO: delete me

public:
/*
 * Getting problem and searching for the solution using BFS algorithm
 * */

    string Search(Searchable<E>* problem) override {

        bool goalWasntFound = true;

        //get state to start from
        State<E> *start = problem->getInitialState();

        //Push first state to queue
        queueBFS.push(problem->getInitialState());

        //any push need to update closed list that state was pushed to queue
        closed.insert(pair<State<E> *, State<E> *>(start, start));

        int testingCounter = 0; //TODO: REMOVE ME

        //BFS algorithm
        while (goalWasntFound) {
            if(queueBFS.size() == 0){
                return "No Solution";
            }

            //Take queue's front element and process it (check if goal, otherwise - push successors to queue)
            State<E> *topOfQueue = queueBFS.front();

            queueBFS.pop();
            //each poped state is countered as evaluated node!
            evaluatedNodes++;

            //check if current state is the goal state
            if (problem->isGoalState(topOfQueue)) {
                //if goal state was found - stop the searching algorithm
                goalWasntFound = false;
                continue;
            }

            //get successors
            vector<State<E>*> successors = problem->getAllPossibleStates(topOfQueue);


            // push the ones which aren't in the closed list (map) to the queue
            for (State<E> *s : successors) {
                auto got = closed.find(s);
                if (got == closed.end()) {
                    s->setCameFrom(topOfQueue);
                    s->SetTotalCost(s->getCameFrom()->getTotalCost() + s->getTotalCost());
                    queueBFS.push(s);
                    closed.insert(pair<State<E>*,State<E>*>(s,s));
                }
            }


        }

        return "bfs search returns this message - need to return solution\n";
    }
   
    int getEvaluatedNodes() override {
        return evaluatedNodes;
    }
};

#endif //SECONDMILESTONE__BFSALGORITHM_H_
