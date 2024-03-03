#include<bits/stdc++.h>
using namespace std;


/****************************************************************************
Problem #2: Adjacency Hashset Representation
● Can we iterate on neighbours efficiently (O(Degree )), while still checking whether an edge exists or not in O(1)? The best of 2 worlds?
● Simply, yes. Instead of a list per node, use a hashset!
● typedef vector<unordered_set<int>> GRAPH;
● Assume it is unweighted graph
● State the time and space complexity
● State the disadvantages of this representation
****************************************************************************/


typedef vector<unordered_set<int>> GRAPH;

void add_directed(GRAPH& graph , int from , int to){
    graph[from].insert(to);
}

void add_undirected(GRAPH& graph , int from , int to){
    graph[from].insert(to);
    graph[to].insert(from);
}

void print_adjacency_matrix(GRAPH& graph){
    int nodes = graph.size();
    for(int from = 0; from < nodes; from++){
        cout<<"neighbors of : "<<from<<" are : ";
        for(int to : graph[from])
            cout<<to<<" , ";
        cout<<"\n";
    }
}

void test1(){
    int nodes , edges;
    cin>>nodes>>edges;
    GRAPH graph(nodes);
    for(int i = 0; i < edges; i++){
        int from , to;
        cin>>from>>to;
        add_undirected(graph , from , to);
    }
    print_adjacency_matrix(graph);
}

void test2(){
    int nodes , edges;
    cin>>nodes>>edges;
    GRAPH graph(nodes);
    for(int i = 0; i < edges; i++){
        int from , to;
        cin>>from>>to;
        add_directed(graph , from , to);
    }
    print_adjacency_matrix(graph);
}


int main(){
    cout<<"Undirected Graph :\n";
    test1();
    cout<<"\nDirected Graph :\n";
    test2();
}
/*
5 6
0 1
0 2
1 2
1 4
2 3
3 4
*/
