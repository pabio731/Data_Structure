#pragma once
#include<iostream>
using std::cout;
using std::cin;
using std::endl;
using std::string;

//Circular queue�� ����.

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
	int iMaxElemNum;	//�ִ� ���� ����
	int iCurElemNum;	//���� ���� ����
	int iFront;			//����Ʈ ��ġ ny56mu77uumm
	int iRear;			//���� ��ġ
	QNODE* pElem;
}ARRQUE;

ARRQUE* CreateArrQueue(int iMaxElemNum);
bool Enqueue(ARRQUE* pQue, QNODE Elem);
char Dequeue(ARRQUE* pQue);
char Peek(ARRQUE* pQue);
void DeleteArrQueue(ARRQUE* pQue);
bool IsFull(ARRQUE* pQue);
bool IsEmpty(ARRQUE* pQue);