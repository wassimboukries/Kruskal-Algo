/**
 * @file functions.h
 * @author Wassim Boukries (wassim.boukries@etu.uca.com)
 * @brief fichier qui comporte les déclarations des différentes fonctions et classes ou structures et les constantes globales.
 * @version 0.1
 * @date 2022-01-17
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#pragma once

#include <string>
#include <vector>

using namespace std;

typedef struct graph {
	int nVertex, nEdges;
	// list of all the edges of the graph, one edge is presented as (weight, (vertex source, vertex destination))
	vector<pair<int, pair<int, int>>> edges;
} graph_t;

typedef struct subSet {
	// vecteur qui représente les parents de chaque vertex,
	vector<int> parents;
	// vecteur qui représente le rang de chaque vertex
	vector<int> ranks;
} subSet_t;

void readGraph(string fileName, graph_t & graph);
void Kruskal(graph_t & graph);
void Union(subSet_t& subsets, int x, int y);
int find(subSet_t& subsets, int i);