#include <iostream>
#include <fstream>
#include "functions.h"
#include <vector>
#include <algorithm>

void readGraph(string fileName, t_graph& graph) {
    int i, weight, sourceV, destV;

    std::ifstream fichier(fileName);

    fichier >> graph.nEdges >> graph.nVertex;

    for (i = 0; i < graph.nEdges; i++) {
        fichier >> sourceV >> destV >> weight;
        auto vertexPair = make_pair(sourceV, destV);
        auto edgePair = make_pair(weight, vertexPair);
        graph.edges.push_back(edgePair);
    }

}


void Kruskal(t_graph& graph) {
    vector<int> parents;
    for (int i = 0; i < graph.nVertex; ++i) {
        parents.push_back(-1);
    }

    // trier les aretes du graphs par ordre croissant des poids (weight)
    sort(graph.edges.begin(), graph.edges.end());

    for (auto& edge : graph.edges) {
        if (find(parents, edge.second.first) != find(parents, edge.second.second)) {
            cout << edge.first << " " << edge.second.first << " " << edge.second.second << endl;
            Union(parents, edge.second.first, edge.second.second);
        }
    }
}

// A utility function to find the subset of an element i
int find(vector<int> parents, int i) {
    if (parents[i] == -1)
        return i;
    return find(parents, parents[i]);
}

// A utility function to do union of two subsets
void Union(vector<int> & parents, int x, int y) {
    parents[x] = y;
}