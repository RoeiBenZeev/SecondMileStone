#include <iostream>
#include "Server.h"
#include "MySerialServer.h"

using namespace server_side;

namespace boot{
    class Main{
        void main(int argc, char *argv[]){
            Server* s = new MySerialServer();

        }
    };
}

int main() {


    return 0;
}