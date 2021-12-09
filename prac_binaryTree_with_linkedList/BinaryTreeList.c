#include "BinaryTreeList.h"
#include <stdio.h>

// 트리
Node tree = NULL;


Node makeRoot(DATA data) {
    tree = (struct _Node*)malloc(sizeof(struct _Node)); // malloc은 void *를 리턴하니까 이걸 struct _Node를 가리키는 포인터 형으로 변환해줘야! => 루트 노드에 메모리만 확보
    tree->data = data;
    tree->lchild = tree->rchild = NULL;
    return tree;
}
Node makeLeftChild(Node cur, DATA data){
    struct _Node* newNode = (struct _Node*)malloc(sizeof(struct _Node));
    newNode->data = data;
    newNode->lchild = newNode->rchild = NULL; // newNode를 기준으로 새롭게 지정
    cur->lchild = newNode; //lchild & rchild는 둘다 구조체 가리키는 포인터 (노드가 구조체니까 그걸 가리켜야지) 원래 lchild가 NULL이었는데 lchild를 새로 만들었으니 newNode
    return newNode;
}
Node makeRightChild(Node cur, DATA data){
    struct _Node* newNode = (struct _Node*)malloc(sizeof(struct _Node));
    newNode->data = data;
    newNode->lchild = newNode->rchild = NULL; // newNode를 기준으로 새롭게 지정
    cur->rchild = newNode; 
    return newNode;
}

DATA getCurData(Node cur){
    return cur->data;
}

Node getLeftChild(Node cur){
    return cur->lchild;
}
DATA getLeftChildData(Node cur){
    return cur->lchild->data;
}
Node getRightchild(Node cur){
    return cur->rchild;
}
DATA getRightchildData(Node cur);
int isTreeEmpty(Node root){
    if (root == NULL)
        return 1;
    else
        return 0;
}
