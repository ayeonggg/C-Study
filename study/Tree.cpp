#include <iostream>
#include <memory>
using namespace std;

int main() {
    Tree tree;
    std::shared_ptr<TreeNode> root = nullptr;

    int Num;
    do {
        std::cout << "Enter the operation number:\n 1.add 2.remove 3.search (Any other number to finish) ";
        std::cin >> Num;

        switch (Num) {
            case 1: {
                std::cout << "Enter the data to add: ";
                int addData;
                std::cin >> addData;
                root = tree.add(root, addData);
                list.print(root);
                break;
            }
            case 2: {
                std::cout << "Enter the data to delete: ";
                int removeData;
                std::cin >> removeData;
                root = tree.remove(root, removeData);
                list.print(root);
                break;
            }
            case 3: {
                std::cout << "Enter the data to search: ";
                int searchData;
                std::cin >> searchData;
                auto result = tree.search(root, searchData);
                if (result != nullptr) {
                    std::cout << "Found: " << result->data << std::endl;
                }
                try {
                    // Your code inside the try block
                    auto result = tree.search(root, searchData);
                    if (result == nullptr) {
                        throw runtime_error("Not Found"); //Node가 전부 nullstr일때 search함수 호출시 예외 처리
                    }
                } catch (const runtime_error& e) {
                    cout << e.what() << endl;
                }

                return 0;
                break;
            }
            default:
                std::cout << "Invalid operation number." << std::endl;
        }
    } while (Num == 1 || Num == 2 || Num == 3);

    cout << "Finish" << endl;
    return 0;
}
