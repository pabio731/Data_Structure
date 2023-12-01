#pragma once
#include"CNode.h"

class CQueue
{
private:
	CNode* pHead;
	int iLenth;

public:
	CQueue();
	bool Enqueue(CUSTOMERINFO CInfo);
	CCustomer* Dequeue();
	CUSTOMERINFO Peek();
	int GetLenth();
};
