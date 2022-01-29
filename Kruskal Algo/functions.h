#pragma once
#define n_max 1000
#define n_succeseur 1000

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

typedef struct t_solution {
	float m[n_max];
	int pere[n_max];
	int t[n_max];
} t_solution;

void readGraph(string fileName, graph_t & graph);
void Kruskal(graph_t & graph);
void Union(subSet_t& subsets, int x, int y);
int find(subSet_t& subsets, int i);