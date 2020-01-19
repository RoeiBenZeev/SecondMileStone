//
// Created by roei on 12/01/2020.
//

#include <cstring>
#include "MyTestClientHandler.h"
#include "SearchSolverAdapter.h"
#include "BestFSAlgorithm.h"

int threadcounter = 0;
void MyTestClientHandler::handleClient(int clientSocket) {
    cout << "Client connectd" << endl;
    vector<string> problemData;
    string problem;
    while (true) {
        char dataFromClient[1024] = {0};
        //get data from client.
        read(clientSocket, dataFromClient, 1024);
        //cout << dataFromClient << std::flush;
        //making a string with out char array buffer
        string dataString(dataFromClient);
//        char delimiter = '\r';
//        size_t pos = dataString.find(delimiter);
//        dataString = dataString.substr(0, pos);
        cout << dataString << endl;
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
//  todo make this Solver Adapter with a problem object
    MatrixProblem* mProblem = new MatrixProblem(problemData);
    auto *BFS = new BestFSAlgorithm<Vertex *>();
//    cout << BFS->Search(mProblem) << endl;
//    SearchSolverAdapter<MatrixProblem,string>* sa =
//        new SearchSolverAdapter<MatrixProblem,string>();
    string solution = BFS->Search(mProblem);
//    //check if solution is in the database
//    try {
//        solution = cacheManager->get(problem);
//        //if the solution is not in the data base we will solve it
//    } catch (const char *e) {
//        solution = solver->solve(problem);
//        cout << "we solve using the solver" <<solution << endl;
//        //inserting the new solution to the data base
//        cacheManager->insert(problem, solution);
//    }
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

MyTestClientHandler::MyTestClientHandler(Solver<string, string> *s, CacheManager<string, string> *cm) {
    this->solver = s;
    this->cacheManager = cm;
}



