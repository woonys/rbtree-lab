#ifndef BINARYTREE_H_
#define BINARYTREE_H_

#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

// 노드의 데이터 타입
typedef char DATA;

// 노드: tree[]의 index로써 노드를 가리킴
typedef struct _Node{
    DATA data;
    struct _Node* lchild;
    struct _Node* rchild;
} *Node; // 구조체에 대한 포인터 타입을 노드라고 해야! 다음 구조체를 가리켜야 하니 

Node makeRoot(DATA data);
Node makeLeftChild(Node cur, DATA data);
Node makeRightChild(Node cur, DATA data);

DATA getCurData(Node cur);
Node getLeftChild(Node cur);
DATA getLeftChildData(Node cur);
Node getRightchild(Node cur);
DATA getRightchildData(Node cur);
int isTreeEmpty(Node root);

#endif