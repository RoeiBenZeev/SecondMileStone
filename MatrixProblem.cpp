//
// Created by roei on 14/01/2020.
//

#include "MatrixProblem.h"

State<Vertex *> *MatrixProblem::getInitialState() {
    return startState;
}
bool MatrixProblem::isGoalState(State<Vertex *> *state) {
    //the pointer point on same State
    if(state == goalState) {
        return true;
    }
    //the pointer point on different states
    else {
        return false;
    }
}
/*
 * this function check 4 directions possible successors and return all  successors can be reached from
 * a given state.
 * We repeat almost same code 4 times , because each direction has different argument , so it cant be dont without makeing
 * the code hard to read.
 */
//todo delete prints
vector<State<Vertex *> *> MatrixProblem::getAllPossibleStates(State<Vertex *> *state) {
    vector<State<Vertex *> *> stateSuccessors;
    //getting this state i,j indexes
    int i = state->GetState()->getLocation().first;
    int j = state->GetState()->getLocation().second;

    //we can have a successor right side this state.
    //if this cell value is -1 this is a blocking cell
    if ((j + 1 <= columnNum - 1) && (matrix[i][j + 1] != -1)) {
        //check if a State indexes are already created.
        auto got = alreadyCreatedStates.find(pair<int, int>(i, j + 1));
        //if the state already created we will return it.
        if (got != alreadyCreatedStates.end()) {
            stateSuccessors.push_back(alreadyCreatedStates[pair<int, int>(i, j + 1)]);
            //cout << "We took this from map" << i << "," << j+1 << endl;
        }
            //else a new State is created
        else {
            State<Vertex *>* rightState = new State<Vertex *>(new Vertex(i, j + 1, matrix[i][j + 1]));
            stateSuccessors.push_back(rightState);
            //add new State made to States map.
            alreadyCreatedStates[rightState->GetState()->getLocation()] = rightState;
            //cout << "We made new one" << i << "," << j+1 << endl;
        }
    }

    //we can have a successor under this state.
    //if this cell value is -1 this is a blocking cell
    if (i + 1 <= rowNum - 1 && (matrix[i + 1][j] != -1)) {
        //check if a State indexes are already created.
        auto got = alreadyCreatedStates.find(pair<int, int>(i + 1, j));
        //if the state already created we will return it.
        if (got != alreadyCreatedStates.end()) {
            stateSuccessors.push_back(alreadyCreatedStates[pair<int, int>(i + 1, j)]);
            //cout << "We took this from map " << i+1 << "," << j << endl;
        }
            //else a new State is created
        else {
            State<Vertex *>* downState =new State<Vertex *>(new Vertex(i + 1, j, matrix[i + 1][j]));
            stateSuccessors.push_back(downState);
            //add new State made to States map.
            alreadyCreatedStates[downState->GetState()->getLocation()] = downState;
            // cout << "We made new one" << i+1 << "," << j << endl;
        }
    }

    //we can have a successor left size this state.
    //if this cell value is -1 this is a blocking cell
    if ((j - 1 >= 0) && (matrix[i][j - 1] != -1)) {
        //check if a State indexes are already created.
        auto got = alreadyCreatedStates.find(pair<int, int>(i, j - 1));
        //if the state already created we will return it.
        if (got != alreadyCreatedStates.end()) {
            stateSuccessors.push_back(alreadyCreatedStates[pair<int, int>(i, j - 1)]);
            //cout << "We took this from map " << i << "," << j-1 << endl;
        }
            //else a new State is created
        else {
            State<Vertex *>* leftState = new State<Vertex *>(new Vertex(i, j - 1, matrix[i][j - 1]));
            stateSuccessors.push_back(leftState);
            //add new State made to States map.
            alreadyCreatedStates[leftState->GetState()->getLocation()] = leftState;
            //cout << "We made new one" << i << "," << j-1 << endl;
        }
    }

    //we can have a successor above this state.
    //if this cell value is -1 this is a blocking cell
    if (i - 1 >= 0 && (matrix[i - 1][j] != -1)) {
        //check if a State indexes are already created.
        auto got = alreadyCreatedStates.find(pair<int, int>(i - 1, j));
        //if the state already created we will return it.
        if (got != alreadyCreatedStates.end()) {
            stateSuccessors.push_back(alreadyCreatedStates[pair<int, int>(i - 1, j)]);
            //cout << "We took this from map " << i-1 << "," << j << endl;
        }
            //else a new State is created
        else {
            State<Vertex *>* upState = new State<Vertex *>(new Vertex(i - 1, j, matrix[i - 1][j]));
            stateSuccessors.push_back(upState);
            //add new State made to States map.
            alreadyCreatedStates[upState->GetState()->getLocation()] = upState;
            //cout << "We made new one at" << i-1 << "," << j << endl;

        }
    }


    return stateSuccessors;
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

    vector<vector<int>> vec(rowNum, vector<int>(columnNum, 0));
    //initial local indexes
    int i = 0;
    int j = 0;
    string cell;

    //going over matrix data rows
    for (string rowVec:matrixData) {
        //istringstream to seperate string by delimiter
        istringstream f(rowVec);
        //initial column value each iteration
        j = 0;
        //going for each column in the rowVec
        while (getline(f, cell, ',')) {
            vec[i][j] = stoi(cell);
            j += 1;
        }
        //check if this column size is valid
        if (j != columnNum) {
            cout << "To many or less columns" << endl;
        }
        i += 1;
    }

    //check if rows number is valid
    if (i != rowNum) {
        cout << "To many or less rows" << endl;
    }

    matrix = vec;
    //todo delete this test
//    cout << "Test initial matrix" << endl;
//    for (vector<int> rowVec:matrix) {
//        for (int c : rowVec) {
//            cout << c << ",";
//        }
//        cout << endl;
//    }
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
    i = stoi(digit);
    //getting second argument by ',' delimiter
    getline(f, digit, ',');
    //converting string to int
    j = stoi(digit);
    //initializing state vertex
    Vertex *startPoint = new Vertex(i, j, matrix[i][j]);
    startState = new State<Vertex *>(startPoint);
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
    i = stoi(digit);
    //getting second argument by ',' delimiter
    getline(f, digit, ',');
    //converting string to int
    j = stoi(digit);
    //initializing state vertex
    Vertex *startPoint = new Vertex(i, j, matrix[i][j]);
    goalState = new State<Vertex *>(startPoint);
    alreadyCreatedStates[goalState->GetState()->getLocation()] = goalState;
}
/*
 * this function count a row length which is the number of our columns
 */
int MatrixProblem::getColumnNum(string row) {
    //counting number of items seperate by ',' in the line
    int counter = 0;
    string temp;
    istringstream f(row);
    while (getline(f, temp, ',')) {
        counter += 1;
    }
    return counter;
}



