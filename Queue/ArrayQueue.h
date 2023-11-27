#pragma once
#include<iostream>
using std::cout;
using std::cin;
using std::endl;
using std::string;

//Circular queue로 구현.

typedef struct ArrayQueueNode
{
	char Element;
}QNODE;

typedef struct ArrayQueue
{
	ArrayQueue(int iMaxElemNum, int iCurElemNum, int iFront, int iRear)
		:iMaxElemNum(iMaxElemNum),
		iCurElemNum(iCurElemNum),
		iFront(iFront), iRear(iRear), pElem(nullptr) {}
	int iMaxElemNum;	//최대 원소 개수
	int iCurElemNum;	//현재 원소 개수
	int iFront;			//프론트 위치 ny56mu77uumm
	int iRear;			//리어 위치
	QNODE* pElem;
}ARRQUE;

ARRQUE* CreateArrQueue(int iMaxElemNum);
bool Enqueue(ARRQUE* pQue, QNODE Elem);
char Dequeue(ARRQUE* pQue);
char Peek(ARRQUE* pQue);
void DeleteArrQueue(ARRQUE* pQue);
bool IsFull(ARRQUE* pQue);
bool IsEmpty(ARRQUE* pQue);