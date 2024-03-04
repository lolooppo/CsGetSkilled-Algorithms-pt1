#include<bits/stdc++.h>
using namespace std;


/*****************************************************************************
Problem #7: Print Chains
● Write a program that reads a directed unweighted graph
● As we did. Read N nodes and M edges then read the M edges (from, to)
● The graph represents a chain: a sequence of vertices from one vertex to another using the edges. The length of a chain is the number of edges. A simple rooted tree.
        ■ [0 ⇒ 5 ⇒ 3 ⇒ 4 ⇒ 1 ⇒ 2]
● Then read integer Q, for number of queries, then read Q integers. Each query is a node number; we want to list the path start from it until the last possible node
● Implement void print_chain(GRAPH &graph, int from)
● It should be a simple recursive function
*****************************************************************************/

typedef vector<vector<int>> GRAPH;

void add_directed(GRAPH &graph, int from, int to) {
	graph[from].push_back(to);
}

void print_chain(GRAPH &graph, int from) {
	cout << from << " ";

	if (graph[from].size() > 0)
		print_chain(graph, graph[from][0]);
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

	int queries;
	cin >> queries;
	while (queries--) {
		int node;
		cin >> node;
		print_chain(graph, node);
		cout << "\n";
	}
}

int main() {
    test();
}
