#pragma once

// 이중 연결 링크드 리스트를 이용하여 Deque를 구현

typedef struct DLDequeNode
{
	int iData;
	DLDequeNode* pPrev;
	DLDequeNode* pNext;
	DLDequeNode()
		: iData(0)
		, pPrev(nullptr)
		, pNext(nullptr) {}
}DLDNODE;

typedef struct DLDeque
{
	int iCurElemNum;
	DLDNODE* pHead;
	DLDNODE* pRear;
	DLDeque()
		:iCurElemNum(0)
		, pHead(nullptr)
		, pRear(nullptr) {}
}DLDQUE;

DLDQUE* CreateArrQueue();
bool CheckIsDeque(DLDeque* pque);
bool InsertFront(DLDQUE* pDeque, DLDNODE Elem);
int DeleteFront(DLDQUE* pDeque);
bool InsertRear(DLDQUE* pDeque, DLDNODE Elem);
int DeleteRear(DLDQUE* pDeque);
int PeekPront(DLDeque* pDeque);
int PeekRear(DLDeque* pDeque);
void DeleteDeque(DLDQUE* pDeque);
bool IsEmpty(DLDQUE* pDeque);
void DisplayDeque(DLDQUE* pDeque);
