//C++ 
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int id;
    vector<Node*> children;
};

unordered_map<int, Node*> nodes;
Node* root = NULL;

void taoGoc(int u) {
    if (nodes.find(u) == nodes.end()) {
        Node* node = new Node();
        node->id = u;
        nodes[u] = node;
        root = node;
    }
}

void chen(int u, int v) {
    if (nodes.find(v) != nodes.end() && nodes.find(u) == nodes.end()) {
        Node* node = new Node();
        node->id = u;
        nodes[v]->children.push_back(node);
        nodes[u] = node;
    }
}

void duyetTienTo(Node* node) {
    if (node == NULL)
        return;
    cout << node->id << " ";
    for (Node* child : node->children)
        duyetTienTo(child);
}

void duyetTrungTo(Node* node) {
    if (node == NULL)
        return;
    if (!node->children.empty())
        duyetTrungTo(node->children[0]);
    cout << node->id << " ";
    for (int i = 1; i < node->children.size(); i++)
        duyetTrungTo(node->children[i]);
}

void duyetHauTo(Node* node) {
    if (node == NULL)
        return;
    for (Node* child : node->children)
        duyetHauTo(child);
    cout << node->id << " ";
}

int main() {
    string lenh;
    while (cin >> lenh && lenh != "*") {
        if (lenh == "MakeRoot") {
            int u;
            cin >> u;
            taoGoc(u);
        } else if (lenh == "Insert") {
            int u, v;
            cin >> u >> v;
            chen(u, v);
        } else if (lenh == "PreOrder") {
            duyetTienTo(root);
            cout << endl;
        } else if (lenh == "InOrder") {
            duyetTrungTo(root);
            cout << endl;
        } else if (lenh == "PostOrder") {
            duyetHauTo(root);
            cout << endl;
        }
    }
}
