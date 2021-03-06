//
// Created by roei on 14/01/2020.
//

#ifndef SECONDMILESTONE__DFSALGORITHM_H_
#define SECONDMILESTONE__DFSALGORITHM_H_

#include <stack>
#include <unordered_map>
#include "ISearcher.h"

template<typename S,typename E>
class DFSAlgorithm : public ISearcher<S,E> {

private:
    int evaluatedNodes = 0;
    unordered_map<State<E> *, State<E> *> closed;
    stack<State<E>*> stackDfs;

public:

    //The DFS algorithm
    string Search(Searchable<E>* problem) override {

        State<E>* start = problem->getInitialState();

        bool goalWasntFound = true;

        //push to stack the state
        stackDfs.push(problem->getInitialState());
        closed.insert(pair<State<E> *, State<E> *>(start,start));
        evaluatedNodes++; //each insertion to closed list is countered

        while(goalWasntFound){

            if( stackDfs.size() == 0){
                return "No Solution";
            }
            //Take stack's top element and process it (check if goal, otherwise - push one successor to stack)
            State<E> *topOfStack = stackDfs.top();

            //check if goal
            if(problem->isGoalState(topOfStack)){
                goalWasntFound = false;
                return ISearcher<S,E>::translateSolution(topOfStack);
            }

            // Push to stack one successor which is not in the visited list.
            vector<State<E>*> successors =  problem->getAllPossibleStates(topOfStack);
            bool hasSuccessor = false;
            for(State<E>* s : successors){
                //find one successor which wasn't visited yet and push it to stack
                auto got = closed.find (s);
                if ( got == closed.end()){
                    hasSuccessor = true;
                    s->setCameFrom(topOfStack);
                    s->SetTotalCost(s->getCameFrom()->getTotalCost() + s->GetStateCost());
                    stackDfs.push(s);
                    closed.insert(pair<State<E> *, State<E> *>(s,s));
                    evaluatedNodes++; //each insertion to closed list is countered
                    break; //gets only one successor.
                }
            }
            if(!hasSuccessor){
                stackDfs.pop();
            }
        }
    }
    //return all evaluaterd nodes
    int getEvaluatedNodes() override {
        return evaluatedNodes;
    }
    //make a clone of this object.
    DFSAlgorithm* clone() {
        return new DFSAlgorithm<S,E>();
    }
    //return a string for this class.
    string toString() override {
        return "DFS";
    }

};


#endif //SECONDMILESTONE__DFSALGORITHM_H_
