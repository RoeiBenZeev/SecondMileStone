//
// Created by roei on 14/01/2020.
//

#include "Vertex.h"
Vertex::Vertex(int row, int column, int cost) : vertexRow(row), vertexColumn(column), vertexCost(cost) {}

int Vertex::GetRow() const {
    return vertexRow;
}
int Vertex::GetColumn() const {
    return vertexColumn;
}
int Vertex::GetCost() const {
    return vertexCost;
}
pair<int, int> Vertex::getLocation() {
    return make_pair(vertexRow,vertexColumn);
}
