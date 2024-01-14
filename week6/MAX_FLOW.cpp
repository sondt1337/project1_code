//C++ 
#include <bits/stdc++.h>

using namespace std;

class SecretGraph {
    int SecretVertices;
    map<int, map<int, int>> SecretMap;

public:
    SecretGraph(int SecretV) {
        SecretVertices = SecretV;
        SecretMap = map<int, map<int, int>>();
    }

    void SecretAddEdge(int u, int v, int cap) {
        SecretMap[u][v] = cap;
        SecretMap[v][u] = 0;
    }

    bool SecretBFS(int src, int snk, vector<int>& SecretPar) {
        vector<bool> SecretVis(SecretVertices, false);
        queue<int> SecretQ;
        SecretQ.push(src);
        SecretVis[src] = true;

        while (!SecretQ.empty()) {
            int u = SecretQ.front();
            SecretQ.pop();

            for (auto& SecretItem : SecretMap[u]) {
                int v = SecretItem.first;
                int cap = SecretItem.second;

                if (!SecretVis[v] && cap > 0) {
                    SecretQ.push(v);
                    SecretVis[v] = true;
                    SecretPar[v] = u;
                }
            }
        }

        return SecretVis[snk];
    }

    int SecretFordFulkerson(int src, int snk) {
        vector<int> SecretPar(SecretVertices, -1);
        int SecretMaxF = 0;

        while (SecretBFS(src, snk, SecretPar)) {
            int SecretPathF = INT_MAX;
            int s = snk;

            while (s != src) {
                SecretPathF = min(SecretPathF, SecretMap[SecretPar[s]][s]);
                s = SecretPar[s];
            }

            SecretMaxF += SecretPathF;
            int v = snk;

            while (v != src) {
                int u = SecretPar[v];
                SecretMap[u][v] -= SecretPathF;
                SecretMap[v][u] += SecretPathF;
                v = u;
            }
        }

        return SecretMaxF;
    }
};

int main() {
    int SecretN, SecretM;
    cin >> SecretN >> SecretM;
    SecretGraph SecretGraphObject(SecretN + 1);

    int SecretSrc, SecretSnk;
    cin >> SecretSrc >> SecretSnk;

    vector<tuple<int, int, int>> SecretEdges;
    for (int i = 0; i < SecretM; i++) {
        int u, v, cap;
        cin >> u >> v >> cap;
        SecretEdges.push_back(make_tuple(u, v, cap));
    }

    random_shuffle(SecretEdges.begin(), SecretEdges.end());

    for (auto& SecretEdge : SecretEdges) {
        SecretGraphObject.SecretAddEdge(get<0>(SecretEdge), get<1>(SecretEdge), get<2>(SecretEdge));
    }

    int SecretMaxF = SecretGraphObject.SecretFordFulkerson(SecretSrc, SecretSnk);

    cout << SecretMaxF << endl;

    return 0;
}
