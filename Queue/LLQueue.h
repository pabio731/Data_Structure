#pragma once


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


/*
덱 생성		CreateDeque()	덱의크기n	덱D
덱 삭제		DeleteDeque()	덱D
원소추가가능 ? IsFull()		덱D			T / F
공백확인		IsEmpty()		덱D			T / F
앞 추가		InsertFront()	덱D, 원소E	성공.실패
뒤 추가		InsertRear()	덱D, 원소E	성공, 실패
앞 제거		DeleteFront()	덱D			원소E		노드 제거하고 반환
뒤 제거		DeleteRear()	덱D			원소E		노드 제거하고 반환
앞 반환		PeekFront()		덱D			원소E		제거하지 않고 반환만
뒤 반환		PeekRear()		덱D			원소E		제거하지 않고 반환만
덱표시		DisplayDeque()	덱D						덱에 저장된 원소 출력
*/