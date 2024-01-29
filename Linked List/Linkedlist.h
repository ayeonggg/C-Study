#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* link;

    Node(int value) : data(value), link(nullptr) {}
};

class HeadNode {
public:
    Node* head;

    HeadNode() : head(nullptr) {}
};

class List {
public:
    HeadNode* createList() {
        HeadNode* H = new HeadNode;
        H->head = nullptr;
        return H;
    }

    void addNode(HeadNode* H, int x) {
        Node* NewNode = new Node(x);
        Node* LastNode;

        if (H->head == nullptr) {
            H->head = NewNode;
            return;
        }

        LastNode = H->head;
        while (LastNode->link != nullptr) LastNode = LastNode->link;
        LastNode->link = NewNode;
    }

    void deleteNode(HeadNode* H) {
        Node* prevNode;
        Node* delNode;

        if (H->head == nullptr) return;
        if (H->head->link == nullptr) {
            delete H->head;
            H->head = nullptr;
            return;
        } else {
            prevNode = H->head;
            delNode = H->head->link;
            while (delNode->link != nullptr) {
                prevNode = delNode;
                delNode = prevNode->link;
            }
            delete delNode;
            prevNode->link = nullptr;
        }
    }

    void deleteThisNode(HeadNode* H, int deldata) {
        Node* delNode;
        Node* prevNode;
        prevNode = H->head;

        while (prevNode->link->data != deldata) {
            prevNode = prevNode->link;
        }

        delNode = prevNode->link;
        prevNode->link = delNode->link;
        delete delNode;

        cout << deldata << " data node delete" << endl;
    }

    void addThisNode(HeadNode* H, int afterthisdata, int adddata) {
        Node* prevNode;
        prevNode = H->head;

        while (prevNode->data != afterthisdata) {
            prevNode = prevNode->link;
        }

        Node* NewNode = new Node(adddata);
        NewNode->link = prevNode->link;
        prevNode->link = NewNode;
    }

    void searchNode(HeadNode* H, int thisdata) {
        Node* someNode;
        someNode = H->head;

        while (someNode->data != thisdata) {
            someNode = someNode->link;
        }
        cout << thisdata << " Search data success " << endl;
    }

    void printList(HeadNode* L) {
        Node* p;
        cout << "Linkedlist = ( ";
        p = L->head;

        while (p != nullptr) {
            cout << p->data;
            p = p->link;
            if (p != nullptr) cout << " --> ";
        }
        cout << " )" << endl;
    }
};
