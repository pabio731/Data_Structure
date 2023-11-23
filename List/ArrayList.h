#pragma once


//이 구조체 하나가 노드가 될 것임. 
// 원소를 굳이 구조체로 관리하는 이유는 배열 리스트의 범용성을 위해서. + 추상 자료형의 정의를 따르기 위해
typedef struct Node
{
	char szEelm;
}CHARNODE;

typedef struct ArrayList
{
	CHARNODE* pElement;
	int iSizeOfList;
	int iNumOfElem;
	
}LIST;


LIST* CreateList(int iSize);			//배열 리스트를 생성해주는 함수. 리스트의 데이터 타입은 char로
void  DeleteList(LIST* ArrayList);		//배열 리스트를 삭제 하는 함수. 
bool  IsFull(const LIST* ArrayList);	//배열 리스트에 데이터 추가 가능성 여부를 확인하는 함수
bool  AddElement(LIST* ArrayList, int iPosition, CHARNODE Node); // 원소를 추가하는 함수. 성공하면 true 실패하면 false 반환,
bool  RemoveElement(LIST* ArrayList, int iPosition);  //원소를 삭제하는 함수. 성공하면 true, 실패하면 false 반환.
CHARNODE* GetElement(LIST* ArrayList, int iPosition); // iPosition 위치의 노드 데이터를 반환하는 함수.
void  DisplayList(LIST* ArrayList); //리스트의 모든 노드 데이터를 보여주는 함수.
void ClearList(LIST* ArrayList); // 리스트를 초기화 하는 함수.
//int GetListLenth(LIST* ArrayList); //리스트의 길이를 반환하는 함수




