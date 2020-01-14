//
// Created by roei on 12/01/2020.
//

#include <cstring>
#include "MyTestClientHandler.h"

int threadcounter = 0;
void MyTestClientHandler::handleClient(int clientSocket) {
    string problem;
    while (true) {
        char dataFromClient[1024] = {0};
        //get data from client.
        read(clientSocket, dataFromClient, 1024);
        cout << dataFromClient << endl;
        string problem(dataFromClient);
        char delimiter = '\r';
        size_t pos = problem.find(delimiter);
        problem = problem.substr(0, pos);
        cout << problem << endl;
        //todo fix string recieve
        if (problem == "end") {
            break;
        }

        string solution;
        //check if solution is in cache
        try {
            solution = cacheManager->get(problem);
        } catch (const char *e) {
            solution = solver->solve(problem);
            cout << solution;
            cacheManager->insert(problem, solution);
        }

        /*
         * solve the problem here
         */

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

    //for matrix
//    //while line is not "end" - read line
//    string delimiter = "\n";
//    size_t pos = problem.find(delimiter);
//    string token = problem.substr(0,pos);
//    //(pos = problem.find(delimiter)) != std::string::npos
//
//    while (problem != "end") {
//        token = problem.substr(0, pos);
//        //for testing:
//        std::cout << token << std::endl;
//        problem.erase(0, pos + delimiter.length());
//    }
}

MyTestClientHandler::MyTestClientHandler(Solver<string, string> *s, CacheManager<string, string> *cm) {
    this->solver = s;
    this->cacheManager = cm;
}



