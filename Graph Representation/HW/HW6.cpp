#include<bits/stdc++.h>
using namespace std;


/*****************************************************************************
Problem #6: Image as a graph
● In the Image Processing domain, we may need to represent the image as a graph. Assume, the image is represented originally as a rectangle RxC. This means we have R*C nodes.
● What about edges? The surrounding cells are your neighbours nodes.
● Let’s use the 4 neighbours cell around a cell as its neighbours to build edges
● We can flatten a 2D matrix so that we have an index for each cell [0, R*C-1]
● Design a program that reads 2 integers (Rows and Cols)
● Rows, Cols >= 1
● Task: Create a graph and print it
● Make proper graph choices x
*****************************************************************************/

typedef vector<vector<int>> GRAPH;

int position(int x , int y , int columns){
    return x * columns + y;
}

void create_edges(GRAPH& graph , int rows , int columns){
    for(int r = 0;r < rows;r++){
        for(int c = 0;c < columns;c++){
            int node = position(r , c , columns);

            int up_x = r - 1, up_y = c;
            int down_x = r + 1, down_y = c;
            int right_x = r, right_y = c + 1;
            int left_x = r, left_y = c - 1;

            if(up_x >= 0)
                graph[node].push_back(position(up_x , up_y , columns));
            if(down_x < rows)
                graph[node].push_back(position(down_x , down_y , columns));
            if(right_y < columns)
                graph[node].push_back(position(right_x , right_y , columns));
            if(left_y >= 0)
                graph[node].push_back(position(left_x , left_y , columns));
        }
    }
}

void print_adjacency_matrix(GRAPH& graph){
    int nodes = graph.size();
    for(int n = 0;n < nodes;n++){
        cout<<"Node : "<<n<<" has neighbours :\n";
        for(int i = 0;i < (int)graph[n].size();i++){
            cout<<graph[n][i]<<" , ";
        }
        cout<<"\n";
    }
}

void test(){
    int rows , columns;
    cin>>rows>>columns;
    GRAPH graph(rows * columns);
    create_edges(graph , rows , columns);
    print_adjacency_matrix(graph);
}

int main(){
    test();
}
