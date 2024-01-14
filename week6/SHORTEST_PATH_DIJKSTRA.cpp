//C++ 
#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> Edge;

vector<vector<Edge>> adjList;
vector<int> distanc;

void shortestPath(int start) {
    priority_queue<Edge, vector<Edge>, greater<Edge>> minHeap;
    minHeap.push({0, start});
    distanc[start] = 0;

    while (!minHeap.empty()) {
        int currentdistancance = minHeap.top().first;
        int currentVertex = minHeap.top().second;
        minHeap.pop();

        if (currentdistancance != distanc[currentVertex])
            continue;

        for (auto neighbor : adjList[currentVertex]) {
            int to = neighbor.first, len = neighbor.second;

            if (distanc[currentVertex] + len < distanc[to]) {
                distanc[to] = distanc[currentVertex] + len;
                minHeap.push({distanc[to], to});
            }
        }
    }
}

int main() {
    int vertices, edges;
    cin >> vertices >> edges;

    adjList.resize(vertices + 1);
    distanc.assign(vertices + 1, numeric_limits<int>::max());

    for (int i = 0; i < edges; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adjList[u].push_back({v, w});
    }

    int source, target;
    cin >> source >> target;

    shortestPath(source);

    if (distanc[target] != numeric_limits<int>::max())
        cout << distanc[target] << endl;
    else
        cout << -1 << endl;

    return 0;
}
