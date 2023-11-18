#pragma once
#include <iostream>
//List With Pointer -> Linked list
// 클래스로 링크드리스트 만들어보기
// 단방향 단순 연결 링크드리스트.

//필요하다 생각되는 부분들 정리하기
/* 노드는 private에 선언하고, 노드도 클래스로.
 데이터 변수인 링크드 리스트의 크기, Head노드도 private에
 데이터를 저장하는 노드 클래스의 멤버는
 데이터 자체와 다음 노드와 연결을 위한
 해당 노드 타입 포인터.

 public에는 링크드 리스트의 기능들
 노드 추가, 크기 리턴 함수. 데이터 출력,
 데이터 값 변경, 노드 삭제, 연결된 노드가 없는지 확인.
*/

//********** Node 클래스의 선언 **********
class Node
{
private:
	int iData;
public:
	Node(const int& iData);
	Node* NextNode;
	int GetData();
};
//****************************************

//********** List 클래스의 선언 **********
class List
{
private:
	
	int iLenth;
	Node* Head;
	Node* Tail;
	Node* Cur;

public:
	List();
	~List();
	//bool AddDataFirst(Node NewNode, int iData);		//데이터 추가 성공시 true, 실패시 false
	bool AddData(Node* NewNode, int iPosition);
	bool AddDataLast(Node* NewNode, int iData);
	bool RemoveData(int iPosition);
	int GetLenth();
	int GetData(int iPosition);
	void DisplayAll();
// 외의 데이터 변경 함수, 리스트가 비어있는지 확인 등은 생략
};
//***************************************


//********** 리스트와 노드 객체를 만드는 정적 멤버 함수
class Create
{
public:
	static List* CreateList();
	static Node* CreateNode(int iData);
};
//*********************************************