# 이진트리 연결 리스트 C로 구현해보기
Reference: https://www.youtube.com/watch?v=e5Wa0VTubh8
그대로 따라치기 연습

* RB트리 만들기 전 C언어에 익숙해지기 위해 C언어로 연결 리스트 연습

## ADT(Abstract Data Type)

* ADT는 구현은 하지 않고 기능 명세를 적는 것을 말함.
* 우리가 구상한 ADT를 헤더 파일로, *.h라는 파일로 마련
    * 이렇게 하면 이진트리 기능을 제공하는 소스(binaryTree.c)와
    * 헤더 파일(binaryTree.h)와
    * 이진트리 기능을 사용하는 소스(main.c)를 완벽하게 분리 가능!
* 

## 노드 안에 들어갈 데이터 정의

* <code>typedef char DATA</code>: 노드에 저장될 자료 - 이번 예제에서는 노드 안에 단일 문자 하나 들어가는 걸로 하자. 


## 구조체 정의

### node
* <code>char Data</code>: 노드에 저장될 자료 - 이번 예제에서는 노드 안에 단일 문자 char만 들어간다고 생각해보기
* <code>struct node *next</code>: 다음 노드를 가리키는 포인터

### linkedlist
* <code>node *head</code>: 연결리스트의 맨 앞을 가리키는 포인터
* <code>node *tail</code>: 연결리스트의 맨 뒤를 가리키는 포인터

## 기능 체크 리스트

### 리스트 생성 & 삭제

* <code>generate_linkdelist()</code>: 연결리스트 생성
    * malloc으로 동적 할당하고 각 노드 포인터 NULL로 초기화
* <code>delete_linkedlist(linkedlist *p)</code>: 연결리스트 삭제
    * 재귀함수를 이용해서 끝에서부터 메모리 해제
    * 모든 노드를 제거한 후 연결리스트 삭제





