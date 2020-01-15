//
// Created by roei on 14/01/2020.
//

#ifndef SECONDMILESTONE__MATRIXPROBLEM_H_
#define SECONDMILESTONE__MATRIXPROBLEM_H_

#include <string>
#include "Searchable.h"
#include "Vertex.h"

class MatrixProblem : public Searchable<Vertex>  {
  private:
    vector<vector<string>> matrix;
    State<Vertex> start;
    State<Vertex> end;

  public:
    State<Vertex> getInitialState() override;
    bool isGoalState(State<Vertex> state) override;
    vector<State<Vertex>> getAllPossibleStates(State<Vertex> state) override;

};

#endif //SECONDMILESTONE__MATRIXPROBLEM_H_
