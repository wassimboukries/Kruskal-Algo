/**
 * @file functions.cpp
 * @author Wassim Boukries (wassim.boukries@etu.uca.com)
 * @brief fichier qui comporte l'implémentation des fonctions déclarés dans functions.h
 * @date 2022-01-17
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>
#include <fstream>
#include "functions.h"
#include <vector>
#include <algorithm>

/**
 * @brief lire les paramétres du graphique à partir d'un fichier texte et les stocker dans un objet graph
 * 
 * @param fileName nom du fichier qui contient les données du graphiques, la première ligne comporte respectivement le nombre des edges 
 * puis celui des vertex, puis chaque représentera un edge (weight, (vertex source, vertex destination)))
 * @param graph objet qui modélise le graphe comme un ensemble de edges
 */
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

/**
 * @brief Algortithme de création de l'arbre minimal couvrant du graph passé en paramètre
 * 
 * @param graph objet qui modélise le graphe comme un ensemble de edges
 */
void Kruskal(graph_t & graph) {
    // Objet qui contient les deux vecteurs parents et ranks
    subSet_t subsets;
    int poidCouvrant = 0,
        sourceRoot, destRoot; 
    
    for (int i = 0; i < graph.nVertex; ++i) {
        // chaque vertex est parent de lui même à l'initialisation
        subsets.parents.push_back(i);
        // le rang est à 0 puisque chaque vertex est parent de lui m�me
        subsets.ranks.push_back(0);
    }

    // trier les aretes du graphs par ordre croissant des poids (weight)
    sort(graph.edges.begin(), graph.edges.end());

    cout << "W\tS\tD" << endl << endl;

    for (auto& edge : graph.edges) {
        sourceRoot = find(subsets, edge.second.first);
        destRoot = find(subsets, edge.second.second);

        if (sourceRoot != destRoot) {
            cout << edge.first << "\t" << edge.second.first << "\t" << edge.second.second << endl;
            poidCouvrant += edge.first;
            Union(subsets, sourceRoot, destRoot);
        }
    }

    cout << "le poid de l'arbre minimal couvrant est : " << poidCouvrant << endl;
}

/**
 * @brief fonction qui return le parent le plus haut, qui sera utilisé pour vérifier si le vertex i crée un cycle en l'ajoutant au subset ou pas
 * 
 * @param subsets Objet qui contient les deux vecteurs parents et ranks
 * @param i le vertex à trouver dans le subset
 * @return int parent absolu dans le subset
 */
int find(subSet_t & subsets, int i) {
    if (i != subsets.parents[i])
        subsets.parents[i] = find(subsets, subsets.parents[i]);
    return subsets.parents[i];
}

/**
 * @brief fonction qui merge les deux vertex x et y en un nouveau subset et l'ajout au subset passé en argument
 * 
 * @param subsets Objet qui contient les deux vecteurs parents et ranks
 * @param x source Vertex
 * @param y destination Vertex
 */
void Union(subSet_t& subsets, int x, int y) {
    int xRoot = find(subsets, x), yRoot = find(subsets, y);

    if (subsets.ranks[xRoot] > subsets.ranks[yRoot]) {
        subsets.parents[yRoot] = xRoot;
    }
    else if (subsets.ranks[xRoot] < subsets.ranks[yRoot]) {
        subsets.parents[xRoot] = yRoot;
    }
    else {
        subsets.parents[yRoot] = xRoot;
        subsets.ranks[yRoot]++;
    }
}