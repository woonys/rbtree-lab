#include <stdio.h>
#include <stdlib.h>

typedef char data;
typedef struct _Node {
    char key; // 데이터부
    struct _Node* left; 
    struct _Node* right;
} Node;


Node* searchBST(Node* root, char x){
    Node* p = root;
    while (p!=NULL){
        if (p->key == x)
            return p;
        else if (p->key < x) 
            p = p->right;
        else
            p = p->left;
    } 
    return NULL;
}

Node* insertBST(Node* root, char x){
    Node* p = root;
    Node* parent = NULL; //p의 발자취를 따라가는 변수 -> parent가 한 발짝도 못 갈 수 있음 -> 그때는 루트 자체에다가 새 노드 삽입! 
    while (p!=NULL){
        parent = p;
        if (p->key == x)  {
            printf("같은 키가 있습니다.\n");
            return p;
        }
        else if (p->key <x)
            p = p->right;
        else
            p = p->left;
    }
    // 이 시점이 찾기 실패했을 때! 즉, p가 가리키는 값이 NULL인 상황
    // 1. 새 노드 할당: 아직 기존 트리에 붙이지는 않고 노드만 만들어둔 상황

    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->key = x;
    newNode->left = newNode->right = NULL;

    //2.parent의 자식으로 새 노드 붙이기: 왼쪽 자식에 붙일 거니 오른쪽 자식에 붙일 거니?
    if (parent != NULL) {
        if (parent->key < newNode->key)
            parent->right = newNode; //newNode가 포인터니까
        else
            parent->left = newNode;
    }
    return newNode;
}

// 노드 삭제
Node* deleteBST(Node* root, char x){
    Node* p = root;
    Node* parent = NULL; //p의 발자취를 따라가는 변수 -> parent가 한 발짝도 못 갈 수 있음 -> 그때는 루트 자체에다가 새 노드 삽입! 
    while((p!=NULL) && (p->key != x)) { // key를 만나거나 삭제할 게 없으면 while문 종료!
        parent = p;
        if (p->key < x)
            p = p->right;
        else
            p = p->left;
    }
    if (p == NULL) {
        printf("찾는 노드가 없습니다.\n");
        return root;
    }
    // 이 아래부터는 p->key == x인 상황

    if (p->left == NULL && p->right == NULL) { // 차수가 0인 경우
        if (parent == NULL)
            root = NULL; // 해당 노드가 루트 노드인 경우! 루트를 삭제
        else {
            if (parent->left == p)
                parent->left = NULL;
            else
                parent->right = NULL;

        }
    }

    else if (p->left == NULL || p->right == NULL) { // 차수가 1인 경우! 이렇게 쓰면 0인 것도 들어오는데 차수가 0인 케이스는 위에서 걸러짐.
        Node* child = (p->left != NULL) ? p->left : p->right; //3항 연산자: p->left가 0이 아니면 걔를 child가 가리키게 하고 p->right !=0이면 걔를 child가 가리키게.
        if (parent == NULL) // 루트 노드를 삭제하는 케이스
            root = child; // 바로 아래 자식이 루트가 된다. => 최종적으로 root 반환
        else {
            if (parent->left == p)
                parent->left = child;
            else
                parent->right = child;
        }
    }

    else {// 차수가 2 => 후계자를 찾으러 떠나야 하니까 succ_parent, succ를 만드는 것!
        Node* succ_parent = p; // 후계자의 parent 노드를 유지하면서 따라간다
        Node* succ = p->right; // 후계자를 오른쪽 서브트리에서 찾으려고 하니 p->right 
        while (succ->left != NULL) {
            succ_parent = succ; // succ parent는 현재 succ를 가리키게 하고
            succ = succ->left; // succ는 왼쪽 자식 노드를 가리키게 옮겨. 
        }

        p->key = succ->key; // 후계자가 해당 노드의 값으로 가게 한다. 우리는 p를 삭제하는 게 아니라 succ를 삭제할 것.
        if (succ_parent->left == succ) // 후계자가 후계자 부모의 왼쪽 자식 노드라면 
            succ_parent->left = succ->right; // 현재 succ_parent의 왼쪽노드에는 암것도 없어야 할 상황이니 오른쪽 자식을 가리키게 한다.
        else
            succ_parent->right = succ->right; // 오른쪽 가리키던 곳은 그대로 오른쪽.
        p = succ;
    }
    
    free(p);
    return root; // root가 위의 과정을 통해 값이 바뀌었을 수 있으니 root를 반환!
}

void inorder(Node* root) {
    if (root == NULL)
        return;
    inorder(root->left);
    printf("%c ", root->key);
    inorder(root->right);
}

int main(){

    Node* root = insertBST(NULL, 'D');
    insertBST(root, 'I');
    insertBST(root, 'F');
    insertBST(root, 'A');
    insertBST(root, 'G');
    insertBST(root, 'C');
    inorder(root); printf("\n");
    return 0;

}