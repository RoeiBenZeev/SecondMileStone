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

    void testSearcherPath(ISearcher<string,Vertex *> *searcher, Searchable<Vertex *> *searchable) {

        if ((searcher->Search(searchable)) != "No Solution") {
            cout << searcher->Search(searchable) << endl;
        } else {
            cout << "No Solution";
        }

    }

    void testSearcher(ISearcher<string,Vertex *> *searcher, Searchable<Vertex *> *searchable) {

        if ((searcher->Search(searchable)) != "No Solution") {
            cout << searcher->getEvaluatedNodes();
        } else {
            cout << "No Solution";
        }

    }

    void testAlgorithms() {

        string line;

        //make test for each matrix file
        for (int i = 10; i < 38; i += 3) {

            string fileName = "Matrix" + to_string(i) + "x" + to_string(i) + ".txt";

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

            //BFS:
            cout << "Matrix(" + to_string(i) + "x" + to_string(i) + "): ";
            auto *BFS = new BFSAlgorithm<string,Vertex*>();
            cout << "BFS(";
            testSearcher(BFS, matrixProblem);
            cout << ")";


            //DFS:
            cout << ", DFS(";
            auto *DFS = new DFSAlgorithm<string,Vertex *>();
            testSearcher(DFS, matrixProblem);
            cout << ")";


            //BestFS:
            cout << ", BestFS(";
            auto *BestFS = new BestFSAlgorithm<string,Vertex *>();
            testSearcher(BestFS, matrixProblem);
            cout << ")";


          //A*
            cout << ", A*(";
            auto *AStar = new AStarAlgorithm<string, Vertex*>();
            testSearcher(AStar, matrixProblem);
            cout << ")";
            cout << endl;

            // Close the file
            MyReadFile.close();
        }

        //##########################################################################
        //Printing solution:

        //make test for each matrix file
        for (int i = 10; i < 38; i += 3) {

            string fileName = "Matrix" + to_string(i) + "x" + to_string(i) + ".txt";

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

            //BFS:
            cout << "Matrix(" + to_string(i) + "x" + to_string(i) + "): ";
            auto *BFS = new BFSAlgorithm<string,Vertex *>();
            cout << "BFS Path: ";
            testSearcherPath(BFS, matrixProblem);
            cout << "" << endl;


            //DFS:
            ISearcher<string,Vertex*> *DFS = new DFSAlgorithm<string,Vertex *>();
            cout << "DFS Path: ";
            testSearcherPath(DFS, matrixProblem);
            cout << "" << endl;


            //BestFS:
            auto *BestFS = new BestFSAlgorithm<string,Vertex *>();
            cout << "BestFS Path: ";
            testSearcherPath(BestFS, matrixProblem);
            cout << "" << endl;


//          A*
            auto *AStar = new AStarAlgorithm<string,Vertex*>();
            cout << "A* Path: ";
            testSearcherPath(AStar, matrixProblem);
            cout << endl;

            // Close the file
            MyReadFile.close();
        }


    }

};


#endif //SECONDMILESTONE_MATRIXTESTER_H
