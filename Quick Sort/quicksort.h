#include <iostream>

class Node {
private:
    int data;
    Node* link;

    Node(int value) : data(value), link(nullptr) {}
    friend class List; //List클래스에서 Node클래스의 멤버에 접근할 수 있도록
};

class List {
public:
    Node* head;

    List() : head(nullptr) {}

    void addNode(int x) {
        Node* newNode = new Node(x);
        Node* lastNode;

        if (head == nullptr) {
            head = newNode;
            return;
        }

        lastNode = head;
        while (lastNode->link != nullptr) lastNode = lastNode->link;
        lastNode->link = newNode;
    }

    void deleteNode() {
        if (head == nullptr) return;

        Node* prevNode = nullptr;
        Node* currentNode = head;

        while (currentNode->link != nullptr) {
            prevNode = currentNode;
            currentNode = currentNode->link;
        }

        if (prevNode == nullptr) {
            delete head;
            head = nullptr;
        } else {
            delete currentNode;
            prevNode->link = nullptr;
        }
    }

    void deleteThisNode(int deldata) {
        Node* delNode;
        Node* prevNode;
        prevNode = head;

        while (prevNode->link != nullptr && prevNode->link->data != deldata) {
            prevNode = prevNode->link;
        }

        if (prevNode->link == nullptr) {
            std::cout << "Node with data " << deldata << " not found." << std::endl;
            return;
        }

        delNode = prevNode->link;
        prevNode->link = delNode->link;
        delete delNode;

        std::cout << deldata << " data node deleted" << std::endl;
    }

    void addThisNode(int afterthisdata, int adddata) {
        Node* prevNode;
        prevNode = head;

        while (prevNode != nullptr && prevNode->data != afterthisdata) {
            prevNode = prevNode->link;
        }

        if (prevNode == nullptr) {
            std::cout << "Node with data " << afterthisdata << " not found." << std::endl;
            return;
        }

        Node* NewNode = new Node(adddata);
        NewNode->link = prevNode->link;
        prevNode->link = NewNode;
    }

    void searchNode(int thisdata) {
        Node* someNode;
        someNode = head;

        while (someNode != nullptr && someNode->data != thisdata) {
            someNode = someNode->link;
        }

        if (someNode == nullptr) {
            std::cout << "Node with data " << thisdata << " not found." << std::endl;
        } else {
            std::cout << thisdata << " Search data success " << std::endl;
        }
    }

    void printList() {
        Node* p;
        std::cout << "Linkedlist = ( ";
        p = head;

        while (p != nullptr) {
            std::cout << p->data;
            p = p->link;
            if (p != nullptr) std::cout << " --> ";
        }
        std::cout << " )" << std::endl;
    }

    Node* getLastNode() {
        Node* lastNode = head;
        while (lastNode != nullptr && lastNode->link != nullptr) {
            lastNode = lastNode->link;
        }
        return lastNode;
    }

    Node* partition(Node* low, Node* high) {
        int pivot = high->data;
        Node* i = low;
        
        for (Node* j = low; j != high; j = j->link) {
            if (j->data < pivot) {
                std::swap(i->data, j->data);
                i = i->link;
            }
        }
        std::swap(i->data, high->data);
        return i;
    }

    void quickSortUtil(Node* low, Node* high) {
        if (low != nullptr && high != nullptr && low != high && low->link != high) {
            Node* pivot = partition(low, high);
            quickSortUtil(low, pivot);
            quickSortUtil(pivot->link, high);
        }
    }

    void quickSort() {
        Node* lastNode = getLastNode();
        quickSortUtil(head, lastNode);
    }
};