#include<bits/stdc++.h>
using namespace std;


/*****************************************************************************
Problem #5: Adjacency-based repr for flights v2
● The solution provided to the previous problem is interesting, but has a great drawback
● If we have N standard graph algorithms, we will rewrite them all to work with the new representation
● Find a way to reduce this problem’s requirements (working on strings mainly) to the normal adjacency list representation. In this way, the implemented algorithms can be used as they are
● Edge: int from, to, weight;
● typedef vector<edge> GRAPH;
● void add_edge(GRAPH &graph, int from, int to, int cost)
● For simplicity: Printing can be print in any order
*****************************************************************************/

class MAPPER{
private:
    map<string , int>str_to_int;
    map<int , string>int_to_str;
public:
    int get_id(string str){
        if(str_to_int.count(str))
            return str_to_int[str];
        int id = str_to_int.size();
        str_to_int[str] = id;
        int_to_str[id] = str;
        return id;
    }

    string get_str(int id){
        return int_to_str[id];
    }
};

struct edge{
    int to;
    int cost;
};

typedef vector<vector<edge>> GRAPH;

void add_directed(GRAPH& graph , int from , int to , int cost){
    graph[from].push_back({to , cost});
}

void print_adjaceny_matrix(GRAPH& graph , MAPPER& mapper){
    int nodes = graph.size();
    for(int from = 0;from < nodes;from++){
        if((int)graph[from].size() == 0)
            continue;
        cout<<"From : "<<mapper.get_str(from)<<":\n";
        for(int to = 0;to < (int)graph[from].size();to++){
            cout<<"\tTo : "<<mapper.get_str(graph[from][to].to)<<" ,with cost of : "<<graph[from][to].cost<<"\n";
        }
        cout<<"\n";
    }
}

void test(){
  int nodes, edges;
	cin >> nodes >> edges;
	GRAPH graph(nodes);
	MAPPER mapper;
	for (int e = 0; e < edges; ++e) {
		string from, to;
		int cost;
		cin >> from >> to >> cost;
		int from_id = mapper.get_id(from);
		int to_id = mapper.get_id(to);
		add_directed(graph , from_id , to_id , cost);
	}
	print_adjaceny_matrix(graph , mapper);
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
