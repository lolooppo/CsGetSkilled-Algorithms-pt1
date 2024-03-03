#include<bits/stdc++.h>
using namespace std;


/****************************************************************************
Problem #3: Adjacency matrix with multiple edges
● What if we can’t just pick up one edge from the multiple edges?
● Change the adjacency matrix representation somehow to be able to keep the multiple edges
● Print the graph such that the edges of each node are printed first
● The order of the printed edges per (source) node does not matter
● The graph edges are directed
● The graph weights are integer values
****************************************************************************/


// Each cell in the matrix graph[from][to] is a list of the cost
typedef vector<vector<vector<int>>> GRAPH;

void print_adjaceny_matrix(GRAPH &graph) {
	int nodes = graph.size();
	for (int from = 0; from < nodes; ++from) {
		for (int to = 0; to < nodes; ++to) {
			for(int weight : graph[from][to])
				cout << "From " << from << " to " << to
				     << " the cost is " << weight << "\n";
		}
	}
}

void add_directed(GRAPH &graph, int from, int to, int cost) {
	graph[from][to].push_back(cost);
}

void test(){
    int nodes, edges;
	cin>>nodes>>edges;

	GRAPH graph(nodes, vector<vector<int>>(nodes));

	for (int e = 0; e < edges; ++e) {
		int from, to, cost;
		cin >> from >> to >> cost;
		add_directed(graph, from, to, cost);
	}
	print_adjaceny_matrix(graph);
}


int main(){
    test();
}
