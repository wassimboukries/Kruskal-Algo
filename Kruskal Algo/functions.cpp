#include <iostream>
#include <fstream>
#include "functions.h"
#include <vector>
#include <algorithm>

void readGraph(string fileName, graph_t & graph) {
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


void Kruskal(graph_t & graph) {
    // premier  le deuxième
    subSet_t subsets;
    int poidCouvrant = 0, sourceRoot, destRoot; 
    for (int i = 0; i < graph.nVertex; ++i) {
        // chaque vertex est parent de lui même à l'initialisation
        subsets.parents.push_back(i);
        // le rang est à 0 puisque chaque vertex est parent de lui même
        subsets.ranks.push_back(0);
    }

    // trier les aretes du graphs par ordre croissant des poids (weight)
    sort(graph.edges.begin(), graph.edges.end());

    for (auto& edge : graph.edges) {
        sourceRoot = find(subsets, edge.second.first);
        destRoot = find(subsets, edge.second.second);
        if (sourceRoot != destRoot) {
            cout << edge.first << " " << edge.second.first << " " << edge.second.second << endl;
            poidCouvrant += edge.first;
            Union(subsets, sourceRoot, destRoot);
        }
    }

    cout << "le poid de l'arbre minimal couvrant est : " << poidCouvrant << endl;
}

// A utility function to find the subset of an element i
int find(subSet_t & subsets, int i) {
    int parent = subsets.parents[i];
    if (i != parent)
        subsets.parents[i] = find(subsets, parent);
    return parent;
}

// A utility function to do union of two subsets
void Union(subSet_t& subsets, int x, int y) {
    int xRoot = find(subsets, x), yRoot = find(subsets, y);

    if (subsets.ranks[xRoot] > subsets.ranks[yRoot]) {
        subsets.parents[yRoot] = xRoot;
    }
    else {
        subsets.parents[xRoot] = yRoot;
    }

    if (subsets.ranks[xRoot] == subsets.ranks[yRoot]){
        subsets.ranks[yRoot]++;
    }
}