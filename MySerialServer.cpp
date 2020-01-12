//
// Created by roei on 12/01/2020.
//

#include "MySerialServer.h"
void MySerialServer::open(int port, ClientHandler* ch) {
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

    //making socket listen to the port
    if (listen(socketfd, 5) == -1) { //can also set to SOMAXCON (max connections)
        std::cerr << "Error during listening command" << std::endl;
        //return -3;
        throw "-3";
    } else {
        std::cout << "Server is now listening ..." << std::endl;
    }
    int addrlen = sizeof(address);

    // accepting a client
    int client_socket = accept(socketfd, (struct sockaddr *) &address,
                               (socklen_t *) &addrlen);

    //cout << "server is now Connected" << endl;

    if (client_socket == -1) {
        std::cerr << "Error accepting client" << std::endl;
        //return -4;
        throw "-4";
    }

    close(socketfd); //closing the listening socket

    //std::thread threadServer(receiveData, client_socket);
    //threadServer.detach();
}
void MySerialServer::stop() {

}
