//
// Created by roei on 12/01/2020.
//

#ifndef SECONDMILESTONE__SERVER_H_
#define SECONDMILESTONE__SERVER_H_
#include "ClientHandler.h"
namespace server_side {
class Server {
  public:
    virtual void open(int, ClientHandler) = 0;
    void virtual stop() = 0;
};
}
#endif //SECONDMILESTONE__SERVER_H_
