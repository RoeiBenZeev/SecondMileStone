//
// Created by roei on 14/01/2020.
//

#ifndef SECONDMILESTONE__VERTEX_H_
#define SECONDMILESTONE__VERTEX_H_
#include <utility>
using namespace std;
class Vertex {
  private:
    int vertexRow;
    int vertexColumn;
    int vertexCost;
  public:
    Vertex(int row, int column, int cost);
    int GetRow() const;
    int GetColumn() const;
    int GetCost() const;
    pair<int,int> getLocation();
};


#endif //SECONDMILESTONE__VERTEX_H_
