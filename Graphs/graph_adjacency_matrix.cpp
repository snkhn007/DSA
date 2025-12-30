#include <iostream>
#include <vector>
using namespace std;
int main(){
    int edge, vertices;
    cin>>edge>>vertices;

    vector<vector<int>> matrix(vertices, vector<int>(vertices, 0));
    
    for (int i = 0; i < edge; i++)
    {
        int u, v;
        cin>>u>>v;
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