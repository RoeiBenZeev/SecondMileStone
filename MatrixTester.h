
//
// Created by asaf on 16/01/2020.
//

#ifndef SECONDMILESTONE_MATRIXTESTER_H
#define SECONDMILESTONE_MATRIXTESTER_H


#include <fstream>
#include "Searcher.h"
#include "MatrixProblem.h"
#include "DFSAlgorithm.h"
#include "BFSAlgorithm.h"
#include "BestFSAlgorithm.h"
#include "AStarAlgorithm.h"

class MatrixTester {
  public:

    void testSearcherPath(ISearcher<string, Vertex *> *searcher, Searchable<Vertex *> *searchable) {

        if ((searcher->Search(searchable)) != "A2") {
            cout << searcher->Search(searchable) << endl;
        } else {
            cout << "A3";
        }
    }

    int testSearcher(ISearcher<string, Vertex *> *searcher, Searchable<Vertex *> *searchable, int printOption) {

        if (printOption == 1) {
            if ((searcher->Search(searchable)) != "A4") {
                //cout << searcher->getSolutionCost();
            } else {
                cout << "A5";
            }
        } else {
            if ((searcher->Search(searchable)) != "A6") {
                cout <<searcher->Search(searchable);
                //searcher->getEvaluatedNodes();
            } else {
                cout << "A7";
            }
        }

        return searcher->getEvaluatedNodes();
    }


    void testAlgorithms(int option) {

        string line;

        int BfsAverage = 0, DfsAverge = 0, AstarAverge = 0, BestFSAverage = 0;
        int BfsAverageCost = 0, DfsAvergeCost = 0, AstarAvergeCost = 0, BestFSAverageCost = 0;

        const int numberOfIterations = 9; //NOTE: if you change loop change this as well
        //make test for each matrix file
        //    for (int i = 10; i < 38; i += 3) {

        string fileName = "Matrix" + to_string(10) + "x" + to_string(10) + ".txt";

        // Read from the text file
        ifstream MyReadFile(fileName);

        vector<string> matrixLines;
        // Use a while loop together with the getline() function to read the file line by line
        while (getline(MyReadFile, line)) {
            //create vector of lines
            if (line == "end") {
                break;
            }
            matrixLines.push_back(line);
        }

        auto *matrixProblem = new MatrixProblem(matrixLines);

//            //BFS:
        cout << "Matrix(" + to_string(10) + "x" + to_string(10) + "): ";
        auto *BFS = new BFSAlgorithm<string, Vertex *>();
        cout << "BFS(";
        BfsAverage = BfsAverage + testSearcher(BFS, matrixProblem, option);
        //BfsAverageCost += BFS->getSolutionCost();
        cout << ")";

//
////            DFS:
//            cout << ", DFS(";
//            auto *DFS = new DFSAlgorithm<string, Vertex *>();
//            DfsAverge = DfsAverge + testSearcher(DFS, matrixProblem, option);
//            DfsAvergeCost += DFS->getSolutionCost();
//            cout << ")";
////
//
//            //BestFS:
//            cout << ", BestFS(";
//            auto *BestFS = new BestFSAlgorithm<string, Vertex *>();
//            BestFSAverage = BestFSAverage + testSearcher(BestFS, matrixProblem, option);
//            BestFSAverageCost += BestFS->getSolutionCost();
//            cout << ")";
//
//
//            //A*
//            cout << ", A*(";
//            auto *AStar = new AStarAlgorithm<string, Vertex *>();
//            AstarAverge = AstarAverge + testSearcher(AStar, matrixProblem, option);
//            AstarAvergeCost += AStar->getSolutionCost();

        cout << ")";
        cout << endl;;
        // Close the file
        MyReadFile.close();
        //}

//        enum algoName {
//            BFS,
//            DFS,
//            Astar,
//            BestFS
//        };

        //calc average cost:
        BfsAverageCost = BfsAverageCost / numberOfIterations;
        DfsAvergeCost = DfsAvergeCost / numberOfIterations;
        AstarAvergeCost = AstarAvergeCost / numberOfIterations;
        BestFSAverageCost = BestFSAverageCost / numberOfIterations;


/*
        vector<int> costAverages = {BfsAverageCost, DfsAvergeCost, AstarAvergeCost, BestFSAverageCost};

        //find algorithms with minumum costs
        int flagLocationCost = 0;
        int min = costAverages[0];
        for (int k = 0; k < 4; ++k) {
            if (costAverages[k] < min) {
                min = costAverages[k];
                flagLocationCost = k;
            }
        }


        //save all algorithms which got the min cost:
        vector<algoName> sameCostAlgorithms;
        for (int k = 0; k < 4; k++) {
            if(costAverages[k] == min){
             switch(k){
                 case algoName::BFS :
                     sameCostAlgorithms.push_back(algoName::BFS);
                     break;
                 case algoName::DFS:
                     sameCostAlgorithms.push_back(algoName::DFS);
                     break;
                 case algoName::Astar:
                     sameCostAlgorithms.push_back(algoName::Astar);
                     break;
                 case algoName::BestFS:
                     sameCostAlgorithms.push_back(algoName::BestFS);
                     break;
                 default:
                     break;
             }
            }
        }
*/

        //get the algorithm with the minimal cost & the minimal evaluated nodes.



        //calc averages of evaluated nodes
        BfsAverage = BestFSAverage / numberOfIterations;
        DfsAverge = DfsAverge / numberOfIterations;
        AstarAverge = AstarAverge / numberOfIterations;
        BestFSAverage = BestFSAverage / numberOfIterations;


/*        vector<int> nodesAverages = {BfsAverage, DfsAverge, AstarAverge, BestFSAverage};
        int flagLocation = 0;
        int minNodes = nodesAverages[0];
        for (int j = 0; j < 4; ++j) {
            if (nodesAverages[j] < min) {
                minNodes = nodesAverages[j];
                flagLocation = j;
            }
        }

        for (algoName i : sameCostAlgorithms){

        }

        //print the name of the best algorithm:
        cout << "\nThe best algorithm has " + to_string() + "cost and " + to_string() +  "evaluated nodes and\n";*/

        if (option == 1) {
            cout << "\n\n";
            cout << "~~~~~~ Averages ~~~~~~\n";
            cout << "DFS average nodes: " + to_string(DfsAverge) + " | average cost: " + to_string(DfsAvergeCost) +
                "\n";
            cout << "BFS average nodes: " + to_string(BfsAverage) + " | average cost: " + to_string(BfsAverageCost) +
                "\n";
            cout << "BestFS average nodes: " + to_string(BestFSAverage) + " | average cost: " +
                to_string(BestFSAverageCost) + "\n";
            cout << "A* average nodes: " + to_string(AstarAverge) + " | average cost: " + to_string(AstarAvergeCost) +
                "\n";
        }
    }

};


#endif //SECONDMILESTONE_MATRIXTESTER_H