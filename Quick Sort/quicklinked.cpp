#include <iostream>
#include "quicksort.h"

int main() {
    List list;

    int Num;
    do {
        std::cout << "Enter the operation number:\n 1.add 2.remove 3.search 4.quicksort (Any other number to finish) ";
        std::cin >> Num;

        switch (Num) {
            case 1: {
                std::cout << "Enter the data to add: ";
                int addData;
                std::cin >> addData;
                list.addNode(addData);
                list.printList();
                break;
            }
            case 2: {
                std::cout << "Enter the data to delete: ";
                int deleteData;
                std::cin >> deleteData;
                list.deleteThisNode(deleteData);
                list.printList();
                break;
            }
            case 3: {
                std::cout << "Enter the data to search: ";
                int searchData;
                std::cin >> searchData;
                list.searchNode(searchData);
                break;
            }
            case 4: {
                list.quickSort();
                list.printList();
                break;
            }
            default:
                std::cout << "Invalid operation number." << std::endl;
        }
    } while (Num == 1 || Num == 2 || Num == 3 || Num == 4);

    std::cout << "Finish" << std::endl;
    return 0;
}