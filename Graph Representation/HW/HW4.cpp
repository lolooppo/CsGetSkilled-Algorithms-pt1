#include<bits/stdc++.h>
using namespace std;


/*****************************************************************************
Problem #4: Adjacency-based repr for flights v1
● In the airports, there are many flights (from, to, cost)
● Where from and to are strings (no spaces) and cost is an integer value
● Represent the directed graph based on adjacency style
● There are multiple edges
● Your print function must do the following:
● Flights from are printed sorted (alphabetical order)
● For each from airport: print the to cities based on
                        ■ alphabetical order
                        ■ If there is a tie, the one with smaller cost first
*****************************************************************************/


struct edge{
    string to;
    int cost;
    bool operator < (const edge& e) const{
        if(to != e.to)
            return to < e.to;
        return cost < e.cost;
    }
};

typedef map<string , multiset<edge>> GRAPH;

void add_directed(GRAPH& graph , string from , string to , int cost){
    graph[from].insert({to , cost});
}

void print_adjaceny_matrix(GRAPH& graph){
    for(auto& e : graph){
        cout<<"From : "<<e.first<<"\n";
        for(auto& x : e.second){
            cout<<"\tTo : "<<x.to<<" with cost of : "<<x.cost<<"\n";
        }
        cout<<"\n";
    }
}

void test(){
  int nodes, edges;
	cin >> nodes >> edges;
	GRAPH graph;
	for (int e = 0; e < edges; ++e) {
		string from, to;
		int cost;
		cin >> from >> to >> cost;
		add_directed(graph, from, to, cost);
	}
	print_adjaceny_matrix(graph);
}

int main(){
    test();
}
/*
5 9
California Texas 30
California Texas 10
Florida California 70
California Florida 75
NewYork California 35
Pennsylvania Florida 18
Pennsylvania Florida 28
California Texas 35
California Pennsylvania 37
*/
