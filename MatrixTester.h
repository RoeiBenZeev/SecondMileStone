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


class MatrixTester {
public:
    void testSearcher(ISearcher<Vertex *> *searcher, Searchable<Vertex *> *searchable) {

        cout << searcher->Search(searchable) << endl;
        cout << searcher->getEvaluatedNodes() << endl;

    }

    void testAlgorithms() {

        string line;

        //make test for each matrix file
//        for (int i = 10; i < 37; i += 3) {
//            if(i == 22){
//                cout << "breakpoint";
//            }
        string fileName = "Matrix" + to_string(13) + "x" + to_string(13) + ".txt";

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


        //cout << "Matrix(" + to_string(22) + "x" + to_string(22) + "): ";
        //cout << "Matrix(" + to_string(i) + "x" + to_string(i) + "): ";
        auto *BFS = new BestFSAlgorithm<Vertex *>();
  //      cout << "BFS(" <<;
        testSearcher(BFS, matrixProblem);
//        cout << ")";


        //DFS:
//        cout << ", DFS(";
//        auto *DFS = new DFSAlgorithm<Vertex *>();
//        testSearcher(DFS, matrixProblem);
//        cout << ")";
//        cout << endl;


        // Close the file
        MyReadFile.close();
    }
    // }

};


#endif //SECONDMILESTONE_MATRIXTESTER_H
