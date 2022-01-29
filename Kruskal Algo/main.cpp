#include <iostream>
#include <vector>
#include "functions.h"

int main(int argc, char * argv []) {
    graph_t myGraph;
    std::vector<int> edges;
    std::string inputFileName = "inputFile.txt";

    if (argc > 1) {
        inputFileName = argv[1];
    }

    readGraph("inputFile.txt", myGraph);
    Kruskal(myGraph);

    return 0;
}