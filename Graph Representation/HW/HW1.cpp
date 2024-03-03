#include<bits/stdc++.h>
using namespace std;


/****************************************************************************
Problem #1: Edge List representation
● An edge list representation is a collection of the graph edges.
● For example, if we have 10 edges, then we have a vector of 10 edges
● typedef vector<edge> GRAPH;
● Implement a class edge that contains the relevant edges information
● The edges should be comparable based on the edge weight
● void add_edge(GRAPH &graph, int from, int to, int cost)
● void print_adjaceny_matrix(GRAPH &graph)
● Read the edges into the data structure. Print them ordered based on cost
● State the space complexity.
● State the time complexity for the possible operations
****************************************************************************/


struct edge{
    int from;
    int to;
    int cost;
};

bool compare_edges(edge& e1 , edge& e2){
    return e1.cost < e2.cost;
}

typedef vector<edge> GRAPH;

void add_edge(GRAPH& graph , int from , int to , int cost){
    graph.push_back({from , to , cost});
}

void print_adjacency_matrix(GRAPH& graph){
    sort(graph.begin() , graph.end() , compare_edges);
    for(int e = 0; e < graph.size(); e++){
        cout<<"From : "<<graph[e].from<<" , To : "<<graph[e].to<<" , cost : "<<graph[e].cost<<"\n";
    }
}

void test(){
    int edges;
    cin>>edges;
    GRAPH graph;
    for(int e = 0; e < edges; e++){
        int from , to , cost;
        cin>>from>>to>>cost;
        add_edge(graph , from , to , cost);
    }
    print_adjacency_matrix(graph);
}

int main(){
    test();
}
/*
6
0 1 3
0 2 4
1 2 1
1 4 2
2 3 5
3 4 6
*/
