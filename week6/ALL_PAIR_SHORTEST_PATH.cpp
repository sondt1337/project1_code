//C++ 
#include <bits/stdc++.h>
using namespace std;

const int MAX_VERTICES = 111111;
const int MAX_EDGES = 311111;

vector<pair<int, int>> graph[MAX_EDGES];
bool visited[MAX_VERTICES];
int minDistance[MAX_VERTICES];
int numVertices, numEdges;

void applyDijkstra(int startVertex) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
    fill(minDistance, minDistance + numVertices + 1, INT_MAX);
    fill(visited, visited + numVertices + 1, false);
    minDistance[startVertex] = 0;
    minHeap.push({0, startVertex});

    while (!minHeap.empty()) {
        int currentVertex = minHeap.top().second;
        minHeap.pop();

        if (!visited[currentVertex]) {
            for (auto neighbor : graph[currentVertex]) {
                int nextVertex = neighbor.first;
                int edgeWeight = neighbor.second;

                if (minDistance[nextVertex] > minDistance[currentVertex] + edgeWeight) {
                    minDistance[nextVertex] = minDistance[currentVertex] + edgeWeight;
                    minHeap.push({minDistance[nextVertex], nextVertex});
                }
            }
        }

        visited[currentVertex] = true;
    }
}

int main() {
    cin >> numVertices >> numEdges;

    for (int i = 0; i < numEdges; i++) {
        int source, destination, weight;
        cin >> source >> destination >> weight;
        graph[source].push_back({destination, weight});
    }

    for (int i = 1; i <= numVertices; i++) {
        applyDijkstra(i);

        for (int j = 1; j <= numVertices; j++) {
            if (i == j) {
                cout << 0 << " ";
            } else {
                cout << minDistance[j] << " ";
            }
        }

        cout << "\n";
    }

    return 0;
}
