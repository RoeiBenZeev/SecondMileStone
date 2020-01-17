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

            myServer->open(5601,clientHandler);

        }
    };
}

using namespace boot;
int main(int argc, char *argv[]) {
//    Main* m = new Main();
//    m->main(argc,argv);

    auto* mt = new MatrixTester();
    mt->testAlgorithms();

    return 0;
}