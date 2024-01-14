//C++ 
#include<bits/stdc++.h>
using namespace std;

unordered_map<int, vector<int>> graph;
unordered_map<int, int> visited;

void dfs(int current_node) {
    cout << current_node << " ";
    visited[current_node] = 1;
    for (int neighbor : graph[current_node]) {
        if (!visited[neighbor]) {
            dfs(neighbor);
        }
    }
}

int main() {
    int num_nodes, num_edges;
    cin >> num_nodes >> num_edges;

    for (int i = 0; i < num_edges; i++) {
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    for (int i = 1; i <= num_nodes; i++) {
        sort(graph[i].begin(), graph[i].end());
    }

    for (int i = 1; i <= num_nodes; i++) {
        if (!visited[i]) {
            dfs(i);
        }
    }

    return 0;
}
