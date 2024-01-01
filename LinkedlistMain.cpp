#include <iostream>
#include "Linkedlist.h"
using namespace std;

int main() {
    List list;
    HeadNode* L;
    L = list.createList();

    cout << "Here empty linked list." << endl << endl;

    int data1, data2, data3;
    cout << "Input 3 node data ";
    cin >> data1 >> data2 >> data3;
    list.addNode(L, data1);
    list.printList(L);
    list.addNode(L, data2);
    list.printList(L);
    list.addNode(L, data3);
    list.printList(L);
    cout << endl;

    cout << "Select search node data ";
    int data4;
    cin >> data4;
    list.searchNode(L, data4);

    cout << endl;
    cout << "Which node do you want to add?";
    int data5, data6;
    cin >> data5;
    cout << "What data will you add after node";
    cin >> data6;
    list.addThisNode(L, data5, data6);
    list.printList(L);
    cout << endl;

    cout << "Select node you want to delect ";
    int data7;
    cin >> data7;
    list.deleteThisNode(L, data7);
    list.printList(L);
    cout << endl;


    cout << "Finish" << endl;

    return 0;
}