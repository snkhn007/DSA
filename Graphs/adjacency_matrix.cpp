#include <iostream>
#include <vector>
using namespace std;
// Adjacency matrix representation of an undirected graph
// vertices are assumed to be 0-indexed

int main(){
    int edge, vertices;
    cin>>edge>>vertices;
    vector<vector<int>> matrix(vertices, vector<int>(vertices, 0));
    
    for (int i = 0; i < edge; i++)
    {
        int u, v;
        cin>>u>>v;
        // undirected graph
        matrix[u][v]=1;
        matrix[v][u]=1;
    }
    
    for (int i = 0; i < vertices; i++)
    {
        for (int j = 0; j < vertices; j++)
        {
            cout<<matrix[i][j]<<" ";
        } 
        cout<<endl;
    }
    return 0;    
}
/*
Sample Input:
5 4
0 1
0 2
1 2
1 3
2 3

Output:
0 1 1 0
1 0 1 1
1 1 0 1
0 1 1 0
*/