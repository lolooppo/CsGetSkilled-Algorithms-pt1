#include<bits/stdc++.h>
using namespace std;


/*****************************************************************************
Problem #8: Print Paths of length 2
● Read a directed graph (as usual), and print all paths of length 2
● Here a graph of 6 nodes and 9 edges
● 0 5 4 is 2-edges path: (0, 5) and (5, 4)
● void print_paths_len_2(GRAPH &graph)
● Implement an iterative function
*****************************************************************************/

typedef vector<vector<int>> GRAPH;

void add_directed(GRAPH &graph, int from, int to) {
	graph[from].push_back(to);
}

void print_paths_len_2(GRAPH &graph) {
	int nodes = graph.size();
	// Iterate on node and get all its neighbor
	// for each neighbor, get its neighbors too
	for (int i = 0; i < nodes; ++i) {
		for (int idx1 = 0; idx1 < (int) graph[i].size(); ++idx1) {
			int j = graph[i][idx1];
			for (int idx2 = 0; idx2 < (int) graph[j].size(); ++idx2) {
				int k = graph[j][idx2];
				cout << i << " " << j << " " << k << "\n";
			}
		}
	}
}

void test(){
    int nodes, edges;
	cin >> nodes >> edges;
	GRAPH graph(nodes);	// observe: empty lists
	for (int e = 0; e < edges; ++e) {
		int from, to;
		cin >> from >> to;
		add_directed(graph, from, to);
	}
	print_paths_len_2(graph);
}

int main() {
    test();
}

/*
 6 9
 2 1
 2 5
 2 0
 2 3
 0 5
 1 4
 5 4
 4 3
 4 2

 Output
 0 5 4
 1 4 3
 1 4 2
 2 1 4
 2 5 4
 2 0 5
 4 2 1
 4 2 5
 4 2 0
 4 2 3
 5 4 3
 5 4 2
 */
