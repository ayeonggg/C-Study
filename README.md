# C++ Study 구현

### 코드 특성

 +각각의 노드가 1개의 노드

 +data는 Node 안에 들어가는 int 값

 +헤더파일에 검색, 추가, 삭제 기능 함수 정의
 
## Linked List

    searchNode(HeadNode* H, int thisdata); #리스트에 들어있는 숫자를 검색하는 함수
    addThisNode(HeadNode* H, int afterthisdata, int adddata); #숫자를 입력할 수 있는 함수
    deleteThisNode(HeadNode* H, int deldata); #숫자를 삭제할 수 있는 함수
    printList(HeadNode* L); #data값을 화면에 출력해주는 함수
 
## Binary Search Tree


    search(shared_ptr<TreeNode> node, int data); #구조에 들어있는 숫자를 검색하는 함수
    add(shared_ptr<TreeNode> node, int data); #숫자를 추가할 수 있는 함수
    remove(shared_ptr<TreeNode> node, int data); #숫자를 삭제할 수 있는 함수
    
