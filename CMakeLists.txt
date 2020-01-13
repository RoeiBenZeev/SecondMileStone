cmake_minimum_required(VERSION 3.15)
project(SecondMileStone)

set(CMAKE_CXX_STANDARD 11)

add_executable(SecondMileStone main.cpp Server.cpp Server.h MySerialServer.cpp MySerialServer.h ClientHandler.cpp ClientHandler.h MyTestClientHandler.cpp MyTestClientHandler.h Solver.cpp Solver.h CacheManager.cpp CacheManager.h StringReverser.cpp StringReverser.h)
add_executable(SecondMileStone main.cpp Server.cpp Server.h MySerialServer.cpp MySerialServer.h ClientHandler.cpp ClientHandler.h MyTestClientHandler.cpp MyTestClientHandler.h Solver.cpp Solver.h CacheManager.cpp CacheManager.h FileCacheManager.cpp FileCacheManager.h)