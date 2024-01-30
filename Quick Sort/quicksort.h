#include <iostream>

class Node {
private:
    int data;
    Node* link;

    Node(int value) : data(value), link(nullptr) {}

    friend class List; //List클래스에서 Node클래스의 멤버에 접근 가능
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
        prevNode->link=nullptr;
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

        while (p != nullptr) { //마지막 노드에 도달하기 전까지 반복
            std::cout << p->data;
            p = p->link;
            if (p != nullptr) std::cout << " --> ";
        }
        std::cout << " )" << std::endl;
    }

    Node* getNode() {
        Node* lastNode = head;
        //리스트의 끝까지 이동
        while (lastNode != nullptr && lastNode->link != nullptr) {
            lastNode = lastNode->link;
        }
        return lastNode;
    }

    Node* partition(Node* low, Node* high) {
        int pivot = high->data;
        Node* i = low;
        
        for (Node* j = low; j != high; j = j->link) { //high 이전까지 반복
            if (j->data < pivot) { //high가 가르키는 값이 pivot보다 작으면
                std::swap(i->data, j->data); //i와 j가 가르키는 값 교환
                i = i->link; //i다음 위치로 이동
            }
        }
        std::swap(i->data, high->data);
        return i;
    }

    void quickSortUtil(Node* low, Node* high) { //퀵정렬 작은부분 재귀 호출
        if (low != nullptr && high != nullptr && low != high && low->link != high) {
            Node* pivot = partition(low, high);
            quickSortUtil(low, pivot);
            quickSortUtil(pivot->link, high);
        }
    }

    void quickSort() {
        Node* lastNode = getNode();
        quickSortUtil(head, lastNode);
    }
};