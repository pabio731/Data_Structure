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
�� ����		CreateDeque()	����ũ��n	��D
�� ����		DeleteDeque()	��D
�����߰����� ? IsFull()		��D			T / F
����Ȯ��		IsEmpty()		��D			T / F
�� �߰�		InsertFront()	��D, ����E	����.����
�� �߰�		InsertRear()	��D, ����E	����, ����
�� ����		DeleteFront()	��D			����E		��� �����ϰ� ��ȯ
�� ����		DeleteRear()	��D			����E		��� �����ϰ� ��ȯ
�� ��ȯ		PeekFront()		��D			����E		�������� �ʰ� ��ȯ��
�� ��ȯ		PeekRear()		��D			����E		�������� �ʰ� ��ȯ��
��ǥ��		DisplayDeque()	��D						���� ����� ���� ���
*/