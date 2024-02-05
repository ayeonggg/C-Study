#include <iostream>
#include <vector>
#include "merge_sort.h"


int main() {
    std::vector<int> vec; 
    Sort sort;

    int num;
    do {
        std::cout<< "1.push 2.pop 3.merge sort (Any other number to finish)";
        std::cin>>num;
        switch(num){
            case 1: {
                std::cout<<"Enter the data to push";
                int pushdata;
                std::cin>>pushdata;
                vec.push_back(pushdata);
                for (const auto& element : vec) {
                    std::cout << element << " ";
                     }
                std::cout << std::endl;
                break;
            }

            case 2: {
                std::cout<<"Enter the data to pop";
                vec.pop_back();
                for (const auto& element : vec) {
                    std::cout << element << " ";
                     }
                std::cout << std::endl;
                break;
            }

            case 3: {
                sort.mergeSort(vec);
                for (const auto& element : vec) {
                    std::cout << element << " ";
                     }
                std::cout << std::endl;
                break;
            }
            default:
                std::cout<<"Invalid opertaion number."<<std::endl;

        }
     } while (num==1||num==2||num==3);
        
        std::cout<<"Finish"<<std::endl;
        return 0;
}
