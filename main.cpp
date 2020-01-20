#include <iostream>
#include "Server.h"
#include "MySerialServer.h"
#include "MyTestClientHandler.h"
#include "StringReverser.h"
#include "FileCacheManager.h"
#include "State.h"
#include "MatrixTester.h"

using namespace server_side;

namespace boot {
    class Main {
    public:
        Main() {};

        void main(int argc, char *argv[]) {
            Server *myServer = new MySerialServer();
            Solver<string, string> *solver = new StringReverser();
            CacheManager<string, string> *cm = new FileCacheManager<string, string>(1); //todo: what should be the size?
            ClientHandler *clientHandler = new MyTestClientHandler(solver, cm);

            myServer->open(5601, clientHandler);

        }
    };
}

using namespace boot;

int main(int argc, char *argv[]) {
//    Main* m = new Main();
//    m->main(argc,argv);

    auto* mt = new MatrixTester();
    mt->testAlgorithms();

//    auto *a = new Vertex(1, 4, 0);
//    auto *b = new Vertex(6, 15, 0);
//
//    State<Vertex *>* A = new State<Vertex*>(a, 0);
//    State<Vertex *>* B = new State<Vertex*>(b, 0);
//
//    struct point {
//        int x;
//        int y;
//    };
//
//    point current{};
//    current.x = A->GetState()->GetRow();
//    current.y = A->GetState()->GetColumn();
//
//    point goal{};
//    goal.x = B->GetState()->GetRow();
//    goal.y = B->GetState()->GetColumn();
//
//    //todo: check distance should be integer
//    //returns the distance rounded and as an integer.
//    cout << int  (round(sqrt(pow((current.x - goal.x), 2) + pow((current.y - goal.y), 2))));

    return 0;
}