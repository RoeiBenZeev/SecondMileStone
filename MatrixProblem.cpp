//
// Created by roei on 14/01/2020.
//

#include "MatrixProblem.h"

State<Vertex *> *MatrixProblem::getInitialState() {
    return startState;

}
bool MatrixProblem::isGoalState(State<Vertex*>* state) {
    //need to implement equals function
}
vector<State<Vertex *> *> MatrixProblem::getAllPossibleStates(State<Vertex *> *state) {
    //have to be implemented
}
//constructor
MatrixProblem::MatrixProblem(vector<string> problemData) {
    //first i get the information into buffers so i can initial matrix before states.
    string startString;
    string goalString;
    //first the last item is the goal state
    goalString = problemData.back();
    //then we pop the goal state to get the start state
    problemData.pop_back();
    //then our start is now in the end
    startString = problemData.back();
    //then we pop the start state to get the matrix information
    problemData.pop_back();
    //now we have the matrix information left, we can initial matrix
    initialMatrix(problemData);
    //then we can initial start and goal states
    initialStart(startString);
    initialGoal(goalString);
}
/*
 * A function responssible for matrix creation.
 */
void MatrixProblem::initialMatrix(vector<string> matrixData) {

    //we get matrix size first
    columnNum = getColumnNum(matrixData.front());
    //matrix row num is the number of items we have in the vector
    rowNum = matrixData.size();
    vector<vector<int>> vec(rowNum, vector<int> (columnNum, 0));
    //initial local indexes
    int i = 0;
    int j = 0;
    string cell;
    //going over matrix data rows
    for(string rowVec:matrixData) {
        //istringstream to seperate string by delimiter
        istringstream f(rowVec);
        //initial column value each iteration
        j=0;
        //going for each column in the rowVec
        while(getline(f, cell, ',')){
            vec[i][j] = stoi(cell);
            j+=1;
        }
        //check if this column size is valid
        if (j > columnNum) {
            cout << "To many columns"<< endl;
        }
        i+=1;
    }
    //check if rows number is valid
    if (i > rowNum) {
        cout << "To many rows"<< endl;
    }
    matrix = vec;
    //todo delete this test
    cout << "Test initial matrix" << endl;
    for(vector<int> rowVec:matrix) {
        for( int c : rowVec) {
            cout<< c << ",";
        }
        cout << endl;
    }
}
/*
 * this function initial our problem starting state, by parsing the point value from string.
 */
void MatrixProblem::initialStart(string s) {
    int i;
    int j;
    string digit;
    istringstream f(s);
    //getting first argument by ',' delimiter
    getline(f, digit, ',');
    //converting string to int
    i = stoi(s);
    //getting second argument by ',' delimiter
    getline(f, digit, ',');
    //converting string to int
    j = stoi(s);
    //initializing state vertex
    Vertex* startPoint = new Vertex(i,j,matrix[i][j]);
    startState = new State<Vertex*>(startPoint);
    alreadyCreatedStates[startState->GetState()->getLocation()] = startState;

}
/*
 * this function initial our problem end state, by parsing the point value from string.
 */
void MatrixProblem::initialGoal(string s) {
    int i;
    int j;
    string digit;
    istringstream f(s);
    //getting first argument by ',' delimiter
    getline(f, digit, ',');
    //converting string to int
    i = stoi(s);
    //getting second argument by ',' delimiter
    getline(f, digit, ',');
    //converting string to int
    j = stoi(s);
    //initializing state vertex
    Vertex* startPoint = new Vertex(i,j,matrix[i][j]);
    goalState = new State<Vertex*>(startPoint);
    alreadyCreatedStates[goalState->GetState()->getLocation()] = goalState;
}
int MatrixProblem::getColumnNum(string row) {
    //counting number of items seperate by ',' in the line
    int counter=0;
    string temp;
    istringstream f(row);
    while (getline(f, temp, ',')) {
        counter += 1;
    }
    return counter;
}



