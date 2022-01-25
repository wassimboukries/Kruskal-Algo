#pragma once
#define n_max 1000
#define n_succeseur 1000

#include <string>
#include <vector>

using namespace std;

typedef struct t_graph {
	int nVertex, nEdges;
	// list of all the edges of the graph, one edge is presented as (weight, (vertex source, vertex destination))
	vector<pair<int, pair<int, int>>> edges;
} t_graph;

typedef struct t_solution {
	float m[n_max];
	int pere[n_max];
	int t[n_max];
} t_solution;

void readGraph(string fileName, t_graph& graph);
void Kruskal(t_graph& graph);
void Union(vector<int> & parents, int x, int y);
int find(vector<int> parents, int i);