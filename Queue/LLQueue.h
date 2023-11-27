#pragma once
#include<iostream>
using std::cout;
using std::cin;
using std::endl;
using std::string;

typedef struct LLQueueNode
{
	char szElem;
	LLQueueNode* pNext;
}LQNODE;

typedef struct LLQueue
{
	LLQueue()
		:iCurElemNum(0),
		pFront(nullptr),
		pRear(nullptr) {}

	int iCurElemNum;
	LQNODE* pFront;
	LQNODE* pRear;
}LLQUE;

LLQUE* CreateArrQueue();
bool Enqueue(LLQUE* pQue, LQNODE Elem);
char Dequeue(LLQUE* pQue);
char Peek(LLQUE* pQue);
void DeleteLLQueue(LLQUE* pQue);
bool IsEmpty(LLQUE* pQue);