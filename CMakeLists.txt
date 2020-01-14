cmake_minimum_required(VERSION 3.15)
project(SecondMileStone)

set(CMAKE_CXX_STANDARD 11)

add_executable(SecondMileStone main.cpp Server.cpp Server.h MySerialServer.cpp MySerialServer.h
        ClientHandler.cpp ClientHandler.h MyTestClientHandler.cpp MyTestClientHandler.h Solver.cpp
        Solver.h CacheManager.cpp CacheManager.h FileCacheManager.cpp FileCacheManager.h
        StringReverser.h StringReverser.cpp SearchSolverAdapter.cpp SearchSolverAdapter.h MatrixProblem.cpp MatrixProblem.h Searchable.cpp Searchable.h Searcher.cpp Searcher.h Vertex.cpp Vertex.h DFSAlgorithm.cpp DFSAlgorithm.h BFSAlgorithm.cpp BFSAlgorithm.h BestFSAlgorithm.cpp BestFSAlgorithm.h AStarAlgorithm.cpp AStarAlgorithm.h)

SET(CMAKE_CXX_FLAGS -pthread)