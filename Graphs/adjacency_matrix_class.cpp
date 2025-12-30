#include <iostream>
#include <vector>
using namespace std;

// Graph representation using Adjacency Matrix
class GraphMatrix {
public:
    int v;                              // Number of vertices
    vector<vector<int>> matrix;         // Adjacency matrix

    // Constructor to initialize graph with v vertices
    GraphMatrix(int v) {
        this->v = v;
        matrix.resize(v, vector<int>(v, 0));
    }

    // Adds an undirected edge between vertex u and v
    // Assumes vertices are 0-indexed
    void addEdge(int u, int v) {
        matrix[u][v] = 1;
        matrix[v][u] = 1;
    }

    // Displays the adjacency matrix
    void display() {
        for (int i = 0; i < v; i++) {
            for (int j = 0; j < v; j++) {
                cout << matrix[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    // Create a graph with 4 vertices (0 to 3)
    GraphMatrix g(4);

    // Adding edges
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(0, 1);

    // Display adjacency matrix
    g.display();

    /*
    Output:
    0 1 0 0
    1 0 1 0
    0 1 0 1
    0 0 1 0
    */

    return 0;
}
