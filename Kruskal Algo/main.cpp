#include <iostream>
#include <vector>
#include "functions.h"

int main() {
    t_graph myGraph;
    std::vector<int> edges;

    readGraph("inputFile.txt", myGraph);
    Kruskal(myGraph);

    for (auto& i : myGraph.edges) {
        cout << i.first << " ";
    }
    //cout << endl << myGraph.n << endl;
    return 0;
}