#include <iostream>
#include <memory>
using namespace std;

class TreeNode {
public:
    int data;
    shared_ptr<TreeNode> left;
    shared_ptr<TreeNode> right;
};

class List {
public:
    shared_ptr<TreeNode> search(shared_ptr<TreeNode> node, int data) {
        if (node == nullptr || data == node->data) {
            return node;
        } else if (data < node->data) {
            return search(node->left, data);
        } else {
            return search(node->right, data);
        }
    }

    shared_ptr<TreeNode> newNode(int item) {
        std::shared_ptr<TreeNode> temp = std::make_shared<TreeNode>();
        temp->data = item;
        temp->left = temp->right = nullptr;
        return temp;
    }

    shared_ptr<TreeNode> add(shared_ptr<TreeNode> node, int data) {
        if (node == nullptr) return newNode(data);

        if (data < node->data) {
            node->left = add(node->left, data);
        } else if (data > node->data) {
            node->right = add(node->right, data);
        }
        return node;
    }

    shared_ptr<TreeNode> remove(shared_ptr<TreeNode> node, int data) { //함수명 delete로 하고 싶었는데 메모리 해제 연산자로 사용되도록 설정되어 있기 때문에 변수의 이름으로 사용하면 문제 생김
        if (node == nullptr) {
            return node;
        }

        if (data < node->data) {
            node->left = remove(node->left, data);
        } else if (data > node->data) {
            node->right = remove(node->right, data);
        } else {
            if (node->left == nullptr) {
                return node->right; //입력받은 data값을 찾았을 경우 트리의 왼쪽노트 비어있으면 노드는 오른쪽 값으로 채워짐
            } else if (node->right == nullptr) {
                return node->left; //입력받은 data값을 찾았을 경우 트리의 오른쪽 노트 비어있으면 노드는 왼쪽 값으로 채워짐
            }


            node->data = minValue(node->right); //오른쪽 중 중위가 삭제되면 아래 값 중 가장 작은 값이 중위node 자리로 이동해야함.


            node->right = remove(node->right, node->data);
        }
        return node;
    }

    int minValue(shared_ptr<TreeNode> node) {
        int minValue = node->data;
        while (node->left != nullptr) {
            minValue = node->left->data;
            node = node->left;
        }
        return minValue; //가장 작은 값 탐색
    }

    void print(shared_ptr<TreeNode> node) { // 이진 탐색 트리를 중위 순회하여 노드 값을 출력
        if (node != nullptr) {
            print(node->left);
            cout << node->data << " ";
            print(node->right);
        }
    }
};