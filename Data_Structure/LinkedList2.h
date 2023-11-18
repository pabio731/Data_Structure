#pragma once
#include<iostream>
// 양뱡향 링크드 리스크 구현하기.
// 단방향 링크드 리스트 코드가 조금 중구 난방인 감이 있으니 더 깔끔하게.
// Head의 Prev는 마지막 노드를 가리킬 예정이며,
// 노드가 없을 때는 Next,Prev는 nullptr.
/*
	매개변수로 들어오는 위치값과 현재 리스트가 비어 있는지
	확인 하는 코드 멤버 함수로 따로 빼놓기.
	노드 만들어 주는 작업 멤버 함수 안에서.
	구현 할 것
	삽입 삭제 탐색 모두확인
	길이확인 초기화
*/

//********** Node 클래스 ************
class Node
{
private:
	friend class List;
	int iData;
	Node* Prev;	//이전 노드를 가리킴
	Node* Next;	//다음 노드를 가리킴
public:
	Node(int iData);
	int GetData();
};
//**********************************

//헤드와 테일로 할 수 있는 것..
//처음이랑 마지막에 넣을 때 쓰는거.
//************ List 클래스 ************
class List
{
private:
	int iLenth;
	Node* Head;
	Node* Tail;
public:	// 오류시 메세지를 띄우고 성공시 메세지는 없애기
	List();
	bool IsEmpty();
	bool CheckPosition(int iPosition);
	void InsertHead(int iData);					//앞에서 삽입
	void Insert(int iPosition, int iData);		//중간 삽입
	void InsertTail(int iData);					//끝 삽입
	void DeleteNode(int iPosition);				//노드 삭제
	int GetData(int iPosition);					//탐색
	void GetAll();								//모두 보이기
	int GetLenth();								//길이 확인
	void Clear();								//초기화
};	// 메모리 누수 확인 필수
