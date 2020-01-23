#include <iostream>
#include "Server.h"
#include "MySerialServer.h"
#include "MyTestClientHandler.h"
#include "StringReverser.h"
#include "FileCacheManager.h"
#include "State.h"
#include "MatrixTester.h"
#include "Vertex.h"
#include "customPriorityQueue.h"
#include "SearchSolverAdapter.h"

using namespace server_side;

namespace boot {
    class Main {
    public:
        Main() {};

        void main(int argc, char *argv[]) {
            //if we didnt get port as parameter
            if(strlen(*argv) == 0) {
                Server *myServer = new MySerialServer();
                Solver<MatrixProblem *, string> *solver =
                    new SearchSolverAdapter<MatrixProblem *, string>(new BFSAlgorithm<string, Vertex *>());
                CacheManager<string, string>
                    *cm = new FileCacheManager<string, string>(1); //todo: what should be the size?
                ClientHandler *clientHandler = new MyTestClientHandler(solver, cm);
                myServer->open(5600, clientHandler);
            }
            //if we do get port as parameter
            else {
                Server *myServer = new MySerialServer();
                Solver<MatrixProblem*, string> *solver =
                    new SearchSolverAdapter<MatrixProblem*,string>(new BFSAlgorithm<string,Vertex*>());
                CacheManager<string, string> *cm = new FileCacheManager<string, string>(1); //todo: what should be the size?
                ClientHandler *clientHandler = new MyTestClientHandler(solver, cm);
                myServer->open(stoi(argv[argc-(argc-1)]),clientHandler);
            }
            //

        }
    };
}

using namespace boot;
int main(int argc, char *argv[]) {
    Main* m = new Main();
    m->main(argc,argv);

//    auto* mt = new MatrixTester();
//    mt->testAlgorithms();

    return 0;
}