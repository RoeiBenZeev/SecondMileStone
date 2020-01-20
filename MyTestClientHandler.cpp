//
// Created by roei on 12/01/2020.
//

#include <cstring>
#include "MyTestClientHandler.h"
#include "SearchSolverAdapter.h"
#include "BestFSAlgorithm.h"
int threadcounter = 0;


void MyTestClientHandler::handleClient(int clientSocket) {
    threadcounter +=1;
    cout << "Client connectd" << endl;
    vector<string> problemData;
    string key = "";
    string problem;
    while (true) {
        char dataFromClient[1024] = {0};
        //get data from client.
        read(clientSocket, dataFromClient, 1024);
        //cout << dataFromClient << std::flush;
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
        //cout << dataString << endl;
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
    cout << "thread " +to_string(threadcounter) +" finished recive data" << endl;

//  todo make this Solver Adapter with a problem object
    MatrixProblem* mProblem = new MatrixProblem(problemData);
    cout << "thread " +to_string(threadcounter) +" have the problem" << endl;
//    cout << BFS->Search(mProblem) << endl;
//    SearchSolverAdapter<MatrixProblem,string>* sa =
//        new SearchSolverAdapter<MatrixProblem,string>();
    string solution;// = solver->solve(mProblem);
//    //check if solution is in the database
    try {
        //check if solution is in the cache .
        cout << "thread " +to_string(threadcounter) +" try to find a solution in cache" << endl;
        solution = cacheManager->get(mProblem->toString());
        //if the solution is not in the data base we will solve it
    } catch (const char *e) {
        cout << e << endl;
        cout << "thread " +to_string(threadcounter) +" try to solve the problem" << endl;
        solution = solver->solve(mProblem);
        cout << "thread " +to_string(threadcounter) +" solved the problem" << endl;
        //inserting the new solution to the data base
        cacheManager->insert(mProblem->toString(), solution);
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

MyTestClientHandler::MyTestClientHandler(Solver<MatrixProblem*, string> *s, CacheManager<string, string> *cm) {
    this->solver = s;
    this->cacheManager = cm;
}
ClientHandler *MyTestClientHandler::clone() {
    //deep clone solver field.
    Solver<MatrixProblem*,string>* tempSolver = solver->clone();
    //return new instance of class.
    ClientHandler* temp = new MyTestClientHandler(tempSolver, cacheManager);
    return temp;
}
MyTestClientHandler::~MyTestClientHandler() {
    delete solver;
    delete cacheManager;
}



