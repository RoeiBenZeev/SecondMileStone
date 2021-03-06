//
// Created by roei on 12/01/2020.
//

#include "MySerialServer.h"
#include "FileCacheManager.h"
#include "MyClientHandler.h"
bool keepRun = true;
void MySerialServer::open(int port, ClientHandler *ch) {

    // the port parameter have to be const.
    const int PORT = port;
    //create socket
    int socketfd = socket(AF_INET, SOCK_STREAM, 0);
    if (socketfd == -1) {
        //error
        std::cerr << "Could not create a socket" << std::endl;
        //return -1;
        throw "-1";
    }
    //bind socket to IP sim
    // we first need to create the sockaddr obj.
    sockaddr_in address; //in means IP4
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY; //give me any IP allocated for my machine
    //we need to convert our number
    // to a number that the network understands.
    address.sin_port = htons(PORT);

    //the actual bind command
    if (bind(socketfd, (struct sockaddr *) &address, sizeof(address)) == -1) {
        std::cerr << "Could not bind the socket to an IP" << std::endl;
        //return -2;
        throw "-2";
    }

    try {
        //loop running to accept multiple clients.
        while (keepRun) {
            //making socket listen to the port
            if (listen(socketfd, 5) == -1) { //can also set to SOMAXCON (max connections)
                std::cerr << "Error during listening command" << std::endl;
                //return -3;
                throw "-3";
            } else {
                std::cout << "Server is now listening ..." << std::endl;
            }
            int addrlen = sizeof(address);
            //time out definition, if there is no connection for 10 seconds.
            struct timeval tv;
            tv.tv_sec = 120;
            setsockopt(socketfd, SOL_SOCKET, SO_RCVTIMEO, (const char *) &tv, sizeof tv);
            // accepting a client
            int client_socket = accept(socketfd, (struct sockaddr *) &address,
                                       (socklen_t *) &addrlen);

            cout << "server is now Connected" << endl;

            if (client_socket == -1) {
                std::cerr << "Error accepting client" << std::endl;
                //return -4;
                throw "-4";
            }
            //each client run in different thread.
            thread clientThread(start, ch->clone(), client_socket);
            clientThread.detach();
        }
        //thread clientThread2(start, ch ,socketfd,address);

    } catch (char *e) {
        cout << e << endl;
    }

    //close server socket
    close(socketfd);

}

void MySerialServer::stop() {
    keepRun = false;
}
void MySerialServer::start(ClientHandler *ch, int client_socket) {
    //handle each client
    ch->handleClient(client_socket);
    //closing client socket after handling the problem
    close(client_socket);
}

MySerialServer::MySerialServer() {}
MySerialServer::~MySerialServer() {

}
