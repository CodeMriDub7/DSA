#include <iostream>
#include <vector>
#include <list>

using namespace std;

void addEdge(vector<int> adj[], int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void DFSUtil(int u, vector<int> adj[], vector<bool> &visited) {
    visited[u] = true;
    cout << u << " ";
    for (int i = 0; i < adj[u].size(); i++) {
        if (!visited[adj[u][i]]) {
            DFSUtil(adj[u][i], adj, visited);
        }
    }
}

void DFS(vector<int> adj[], int V) {
    vector<bool> visited(V, false);
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            DFSUtil(i, adj, visited);
        }
    }
}

int main() {
    int V = 5;
    vector<int> adj[V];
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 1, 4);
    cout << "DFS Traversal: ";
    DFS(adj, V);
    return 0;
}
