//
// Created by roei on 14/01/2020.
//

#include "Vertex.h"
Vertex::Vertex(int row, int column, int cost) : row(row), column(column), cost(cost) {}

int Vertex::GetRow() const {
    return row;
}
int Vertex::GetColumn() const {
    return column;
}
int Vertex::GetCost() const {
    return cost;
}
pair<int, int> Vertex::getLocation() {
    return make_pair(row,column);
}
