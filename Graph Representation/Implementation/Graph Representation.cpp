#include<bits/stdc++.h>
using namespace std;


        /*******************************************************************************************************
                        @Author : Alaa Omran
                        @Object : Graph representation by adjacency list with cost for every edge.
        ********************************************************************************************************/


struct edge{
    int to;
    int cost;
};

typedef vector<vector<edge>> GRAPH;

void add_directed(GRAPH& graph , int from , int to , int cost){
    graph[from].push_back({to , cost});
}

void add_undirected(GRAPH& graph , int from , int to , int cost){
    graph[from].push_back({to , cost});
    graph[to].push_back({from , cost});
}

void print_adjacency_matrix(GRAPH& graph){
    int nodes = (int)graph.size();
    for(int from = 0; from < nodes; from++){
        cout<<"Node : "<<from<<" has neighbors : ";
        for(int edge = 0; edge < (int)graph[from].size(); edge++){
                cout<<"to : "<<graph[from][edge].to<<" , cost : "<<graph[from][edge].cost;
        }
    cout<<"\n";
    }
}

int main(){

}
