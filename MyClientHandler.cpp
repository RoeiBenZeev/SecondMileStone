//
// Created by roei on 12/01/2020.
//

#include <cstring>
#include "MyClientHandler.h"
#include "SearchSolverAdapter.h"
#include "BestFSAlgorithm.h"
int threadcounter = 0;


void MyClientHandler::handleClient(int clientSocket) {
    threadcounter +=1;
    cout << "Client connectd" << endl;
    vector<string> problemData;
    string key = "";
    string problem;
    while (true) {
        char dataFromClient[1024] = {0};
        //get data from client.
        read(clientSocket, dataFromClient, 1024);
        //making a string with out char array buffer
        string dataString(dataFromClient);
        key = key + dataString;
        //delete irrelevant chars in string.
        char delimiter = '\n';
        size_t pos = dataString.find(delimiter);
        dataString = dataString.substr(0, pos);
        delimiter = '\r';
        pos = dataString.find(delimiter);
        dataString = dataString.substr(0, pos);
        //if client send end we will terminate the connection.
        if (dataString == "end") {
            break;
        }
        //patch to handle the timeout
        if (dataString == "") {
            continue;
        }
        //add each line data from client to vector
        problemData.push_back(dataString);
    }

    //creating a problem object from the data we get.
    MatrixProblem* mProblem = new MatrixProblem(problemData);
    string solution;
    //check if solution is in the database
    try {
        //check if solution is in the cache .
        solution = cacheManager->get(mProblem->toString() + solver->toString());
        //if the solution is not in the data base we will solve it
    } catch (const char *e) {
        cout << e << endl;
        solution = solver->solve(mProblem);
        //inserting the new solution to the data base
        cacheManager->insert(mProblem->toString() + solver->toString(), solution);
    }
    cout << solution << endl;
    //return the solution
    char *h = new char[solution.length() + 1];
    strcpy(h, solution.c_str());
    //sending the command to the server.
    int is_sent = send(clientSocket, h, strlen(h), 0);
    if (is_sent == -1) {
        cout << "Error sending msg" << endl;
    } else {
    }
}

MyClientHandler::MyClientHandler(Solver<MatrixProblem*, string> *s, CacheManager<string, string> *cm) {
    this->solver = s;
    this->cacheManager = cm;
}
ClientHandler *MyClientHandler::clone() {
    //deep clone solver field.
    Solver<MatrixProblem*,string>* tempSolver = solver->clone();
    //return new instance of class.
    ClientHandler* temp = new MyClientHandler(tempSolver, cacheManager);
    return temp;
}
MyClientHandler::~MyClientHandler() {
    delete solver;
    delete cacheManager;
}



