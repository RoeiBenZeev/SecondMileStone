//
// Created by roei on 12/01/2020.
//

#include <cstring>
#include "MyTestClientHandler.h"


MyTestClientHandler::MyTestClientHandler(Solver<string, string> *s, CacheManager<string, string> *cm) {
    this->solver = s;
    this->cacheManager = cm;
}

void MyTestClientHandler::handleClient(string problem) {


    //print problem
    std::cout << problem << std::endl;





    string solution;
    //check if solution is in cache
    try{
         solution = cacheManager->get(problem);
    } catch (const char* e){
        solution = solver->solve(problem);
        cout << solution;
        cacheManager->insert(problem, solution);
    }

    //if solution is not in cache - solve it


    //insert solution to cache


    //send solution to client


    //
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