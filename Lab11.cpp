#include <iostream>
#include <vector>
#include <climits>
using namespace std;

vector<int> primMST(const vector<vector<int>>& graph, int start) {
    int n = graph.size();

    // Create a vector to store the parent of each node in MST
    vector<int> parent(n, -1);

    // Create a vector to store the minimum weight of each node in MST
    vector<int> key(n, INT_MAX);

    // Create a vector to keep track of whether a node is included in MST
    vector<bool> included(n, false);

    // Start with the given start node
    key[start] = 0;
    parent[start] = -1;

    for (int count = 0; count < n - 1; ++count) {
        // Find the vertex with the minimum key value among the vertices not yet included in MST
        int minKey = INT_MAX, minIndex = -1;
        for (int v = 0; v < n; ++v) {
            if (!included[v] && key[v] < minKey) {
                minKey = key[v];
                minIndex = v;
            }
        }

        // Include the selected vertex in MST
        included[minIndex] = true;

        // Update the key value and parent index of adjacent vertices
        for (int v = 0; v < n; ++v) {
            if (graph[minIndex][v] && !included[v] && graph[minIndex][v] < key[v]) {
                parent[v] = minIndex;
                key[v] = graph[minIndex][v];
            }
        }
    }

    return parent;
}

int main() {
    vector<vector<int>> graph = {
        {0, 3, 0, 0, 0, 1},
        {3, 0, 2, 1, 10, 0},
        {0, 2, 0, 3, 0, 5},
        {0, 1, 3, 0, 5, 0},
        {0, 10, 0, 5, 0, 4},
        {1, 0, 5, 0, 4, 0}
    };

    int start;
    cout << "Enter the starting node: ";
    cin >> start;

    vector<int> parent = primMST(graph, start);

    cout << "Minimum Spanning Tree:\n";
    for (int i = 1; i < parent.size(); ++i) {
        cout << parent[i] << " - " << i << "\n";
    }

    return 0;
}
