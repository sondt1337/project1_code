//C++ 
#include<bits/stdc++.h>
using namespace std;

struct Node {
    int khoa;
    Node* trai;
    Node* phai;
};

Node* crtNode(int khoa) {
    Node* newNode = new Node();
    newNode->khoa = khoa;
    newNode->trai = newNode->phai = NULL;
    return newNode;
}

Node* ins(Node* node, int khoa) {
    if (node == NULL) return crtNode(khoa);
    if (khoa < node->khoa)
        node->trai  = ins(node->trai, khoa);
    else if (khoa > node->khoa)
        node->phai = ins(node->phai, khoa);   
    return node;
}

void preOrder(Node *node) {
    if (node != NULL) {
        cout << node->khoa << " ";
        preOrder(node->trai);
        preOrder(node->phai);
    }
}

int main() {
    Node *goc = NULL;
    string cmd;
    int khoa;

    while(true) {
        cin >> cmd;
        if(cmd == "#") break;
        cin >> khoa;
        goc = ins(goc, khoa);
    }
    preOrder(goc);
    return 0;
}
