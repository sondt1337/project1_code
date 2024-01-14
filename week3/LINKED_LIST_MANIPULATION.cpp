//C++ 
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
};

struct SList {
    Node* head;
    Node* tail;
};

Node* CreateNode(int newData) {
    Node* newNode = new Node();
    newNode->data = newData;
    newNode->next = NULL;
    return newNode;
}

void AddLast(SList* list, int newData) {
    if (list->tail == NULL) {
        list->tail = CreateNode(newData);
        list->head = list->tail;
    }
    else {
        list->tail->next = CreateNode(newData);
        list->tail = list->tail->next;
    }
}

void AddFirst(SList* list, int newData) {
    if (list->head == NULL) {
        list->tail = CreateNode(newData);
        list->head = list->tail;
    }
    else {
        Node* temp = CreateNode(newData);
        temp->next = list->head;
        list->head = temp;
    }
}

void AddBetween(Node* before, Node* after, int value) {
    Node* newNode = CreateNode(value);
    newNode->next = after;
    before->next = newNode;
}

void AddBefore(SList* list, int valueToInsert, int valueToFind) {
    Node* current = list->head;
    Node* nextNode = current->next;
    while (nextNode != NULL) {
        if (nextNode->data == valueToFind) {
            AddBetween(current, nextNode, valueToInsert);
            break;
        }
        current = nextNode;
        nextNode = nextNode->next;
    }
}

void AddAfter(SList* list, int valueToInsert, int valueToFind) {
    Node* current = list->head;
    Node* nextNode = current->next;
    while (nextNode->next != NULL) {
        if (current->data == valueToFind) {
            AddBetween(current, nextNode, valueToInsert);
            break;
        }
        current = nextNode;
        nextNode = nextNode->next;
    }
}

void Print(SList* list) {
    Node* current = list->head;
    while (current != NULL) {
        cout << current->data << " ";
        current = current->next;
    }
}

void Remove(SList* list, int value) {
    Node* current = list->head;
    Node* nextNode = current->next;
    if (current->data == value) {
        list->head = nextNode;
    }
    else {
        while (nextNode != NULL) {
            if (nextNode->data == value) {
                current->next = nextNode->next;
                if (nextNode == list->tail) {
                    list->tail = current;
                }
                break;
            }
            current = nextNode;
            nextNode = nextNode->next;
        }
    }
}

void Reverse(SList* list) {
    Node* before = list->head;
    Node* after = before->next;
    list->head->next = NULL;
    while (after != NULL) {
        before = after;
        after = after->next;
        before->next = list->head;
        list->head = before;
    }
    list->tail = before;
}

bool Contains(SList* list, int value) {
    Node* current = list->head;
    while (current != NULL) {
        if (current->data == value) {
            return true;
        }
        current = current->next;
    }
    return false;
}

int main() {
    SList list;
    list.head = NULL;
    list.tail = NULL;

    int n;
    cin >> n;
    while (n--) {
        int m;
        cin >> m;
        AddLast(&list, m);
    }

    string cmd;
    while (cin >> cmd) {
        if (cmd == "addlast") {
            int value;
            cin >> value;
            if (!Contains(&list, value)) {
                AddLast(&list, value);
            }
            // Print(&list);
        }
        if (cmd == "addfirst") {
            int value;
            cin >> value;
            if (!Contains(&list, value)) {
                AddFirst(&list, value);
            }
            // Print(&list);
        }
        if (cmd == "addafter") {
            int u, v;
            cin >> u >> v;
            if (!Contains(&list, u)) {
                if (list.tail->data == v) {
                    AddLast(&list, u);
                }
                else {
                    AddAfter(&list, u, v);
                }
            }
            // Print(&list);
        }
        if (cmd == "addbefore") {
            int u, v;
            cin >> u >> v;
            if (!Contains(&list, u)) {
                if (list.head->data == v) {
                    AddFirst(&list, u);
                }
                else {
                    AddBefore(&list, u, v);
                }
            }
             // Print(&list);
        }
        if (cmd == "remove") {
            int value;
            cin >> value;
            Remove(&list, value);
              // Print(&list);
        }
        if (cmd == "reverse") {
            Reverse(&list);
        }
        if (cmd == "#") {
            Print(&list);
            break;
        }
    }
}
