//
// Created by roei on 14/01/2020.
//

#ifndef SECONDMILESTONE__MATRIXPROBLEM_H_
#define SECONDMILESTONE__MATRIXPROBLEM_H_

#include <string>
#include "Searchable.h"
#include "Vertex.h"
#include <string>
#include <sstream>
#include <algorithm>
#include <iostream>
#include <vector>
#include <iterator>
#include <unordered_map>
using namespace std;
struct PairHash {
  size_t operator()(const std::pair<int, int>& p) const {
      int x = p.first;
      int y = p.second;
      return ((((x+y+1)*(x+y))/2)+y);
  }
};

class MatrixProblem : public Searchable<Vertex*>  {
  private:
    unordered_map<pair<int,int>, State<Vertex*>*,PairHash> alreadyCreatedStates;

    vector<vector<int>> matrix;

    State<Vertex*>* startState;
    State<Vertex*>* goalState;
    int rowNum;
    int columnNum;
    void initialMatrix(vector<string> matrixData);
    void initialStart(string s);
    void initialGoal(string s);
    int getColumnNum(string row);

  public:
    State<Vertex*>* getInitialState() override;
    bool isGoalState(State<Vertex*>* state) override;
    vector<State<Vertex*>*> getAllPossibleStates(State<Vertex*>* state) override;
    MatrixProblem(vector<string> problemData);
};

#endif //SECONDMILESTONE__MATRIXPROBLEM_H_
