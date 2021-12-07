#include "rbtree.h"

#include <stdlib.h>

rbtree *new_rbtree(void) {
  rbtree *p = (rbtree *)calloc(1, sizeof(rbtree)); // 메모리 먼저 할당하고
  p->root = NULL;
  node_t *nil = (node_t *)calloc(1, sizeof(node_t)); //t->nil에 메모리 할당
  // 어차피 nil은 다 통일! 바닥에 있으니까 이건 new tree 초기화할 때 nil 만들어둬야지.
  nil->color = RBTREE_BLACK;
  nil->key = nil->left = nil->right = NULL;
  // TODO: initialize struct if needed
  return p;
}

// 삭제: 이따가 진행
void delete_rbtree(rbtree *t) {
  // TODO: reclaim the tree nodes's memory

  
  free(t);
}

node_t * _delete(node_t * curr){
  node_t* p = curr;


}

// 삽입

//insert에 사용할 보조 함수 void left_rotate(rbtree *t, const key_t key)

void left_rotation(rbtree *t, const key_t key) {
  node_t *x = t->root; //시작은 root에서 출발 => key값까지 이동해야 됨
  if (x->key == key && x->right !=t->nil) {
      node_t *y = x->right;
      x->right = y->left; // x 오른쪽 자식에 y->left 달아
      if (y->left != t->nil)
        y->left->parent = x;
      y->parent = x->parent;
      if (x->parent ==t->nil) // x가 루트 노드이면 (루트 노드의 부모는 t->nil)
        t->root = y; // 이제 y가 루트 노드가 되어야 함
      else if (x == x->parent->left) // x가 왼쪽 자식 노드이면
        x->parent->left = y;
      else
        x->parent->right = y; // x가 오른쪽 자식 노드

      y->left = x;
      x->parent = y;
  }
}

void right_rotation(rbtree *t, const key_t key) {
  node_t *y = t->root; //시작은 root에서 출발 => key값까지 이동해야 됨
  if (y->key == key && y->left !=t->nil) { //x 기준으로는 right이었지만 y 기준으로 우회전이면 left(x에 해당)가 nil이 아니어야 회전 가능!
    node_t *x = y->left;
    y->left = x->right; // x 오른쪽 자식에 y->left 달아
    //
    if (x->right != t->nil)
      x->right->parent = y;
    x->parent = y->parent;
    if (y->parent ==t->nil) // x가 루트 노드이면 (루트 노드의 부모는 t->nil)
      t->root = x; // 이제 y가 루트 노드가 되어야 함
    else if (y == y->parent->left) // y가 왼쪽 자식 노드이면
      y->parent->left = x;
    else
      y->parent->right = x; // x가 오른쪽 자식 노드

    x->right = y;
    y->parent = x;
  }
}

node_t *rbtree_insert(rbtree *t, const key_t key) {
  // TODO: implement insert
  node_t *y = t->nil;
  node_t *x = t->root;

  while (x != t->nil){
    y = x;
    if (x->key == key) {
      printf("같은 키가 있습니다.\n");
      return x;
    }
    else if (key < x->key){
      x = x->left;
    } 
    else {
      x = x->right;
    }
  }
  //x가 null을 가리키면 그때가 z를 삽입할 때!

  node_t *z = (node_t *)calloc(1, sizeof(node_t));
  z->key = key;
  z->parent = y; //x가 NIL을 가리키고 y는 그 위 노드 가리킴 
  if (y == t->nil) //애초에 트리가 비어있다면 y는 t->nil 그대로
    t->root = z; // Case 1 (Case 2는 고려할 필요 X => 알아서 pass)
  else if (z->key < y->key) // y 왼쪽 자식으로 와야지.
    y->left = z;
  else
    y->right = z;
  
  z->left = t->nil; 
  z->right = t->nil;
  z->color = RBTREE_RED;
  rb_insert_fixup(t, z); //이거 다시 고쳐야 함
  return t->root;
}

void rb_insert_fixup(rbtree* t, node_t *z){
  node_t *y = z->parent;
  while (z->parent->color ==RBTREE_RED) {
    if (z->parent == z->parent->parent->left) //z의 parent가 왼쪽 자식 노드이면
      y = z->parent->parent->right; // 여기서 y는 uncle
      if (y->color == RBTREE_RED) { // 경우 1: z->uncle의 색이 red
        z->parent->color = RBTREE_BLACK; // 색 바꿔주고
        y->color = RBTREE_BLACK; // 색 바꿔주고
        z->parent->parent->color = RBTREE_RED; // 여기도 색 바꿔주고 & 여기서는 회전 없음.
        z= z->parent->parent; // ??? 왜 할부지 가리킴? => 할부지 밑으로 업뎃 끝났으니 그 위에서 다시 while문 돌아야 하니!
      }
      else if (z == z->parent->right) { // 경우 2, 3: uncle color가 black일 때
        z = z->parent;
        left_rotation(t, z);
      } 
    
    
    
    else {

    }
    
      
  }
  t->root->color = RBTREE_BLACK;

}







node_t *rbtree_find(const rbtree *t, const key_t key) {
  node_t* p = t;
  while (p!= NULL){
  }
  
  // TODO: implement find
  return t->root;
}

node_t *rbtree_min(const rbtree *t) {
  // TODO: implement find
  return t->root;
}

node_t *rbtree_max(const rbtree *t) {
  // TODO: implement find
  return t->root;
}

int rbtree_erase(rbtree *t, node_t *p) {
  // TODO: implement erase
  return 0;
}

int rbtree_to_array(const rbtree *t, key_t *arr, const size_t n) {
  // TODO: implement to_array
  return 0;
}
