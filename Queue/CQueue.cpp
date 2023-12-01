#include "CQueue.h"
#include "pch.h"

CQueue::CQueue()
	: pHead(nullptr), iLenth(0)
{}

bool CQueue::Enqueue(CUSTOMERINFO CInfo)
{
	CNode* pNode = new(std::nothrow) CNode(CInfo);
	if (!pNode)	return false;

	if (pHead == nullptr)		//현재 노드가 없는 경우.
	{
		pHead = pNode;
	}
	else
	{
		pHead->SetNext(pNode);
	}
	++iLenth;
	return true;
}

CCustomer* CQueue::Dequeue()
{
	if (nullptr != pHead)
	{
	}
}

CUSTOMERINFO CQueue::Peek()
{
	return CUSTOMERINFO();
}

int CQueue::GetLenth()
{
	return 0;
}