#include <iostream>
#include <vector>
using namespace std;
class Graphmatrix{
    public:
    int v;
    vector<vector<int>> matrix;
    Graphmatrix(int v){
        this->v = v;
        matrix.resize(v, vector<int>(v, 0));
    }
    void addEdge(int u, int v){
        matrix[u][v]=1;
        matrix[v][u]=1;
    }
    void display(){
        for (int i = 0; i < v; i++)
        {
            for (int j = 0; j < v; j++)
            {
                cout<<matrix[i][j]<<" ";
            }
            cout<<endl;            
        }        
    }
};
int main(){
    Graphmatrix g(4);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(0,1);

    g.display();
    // 0 1 0 0
    // 1 0 1 0
    // 0 1 0 1
    // 0 0 1 0

}