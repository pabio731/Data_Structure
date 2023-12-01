#pragma once
#include "CCustomer.h"

class CNode
{
private:
	CCustomer* Customer;		//고객의 정보를 저장한 클래스.
	CNode* pNext;			// 노드의 링크드리스트를 위한 노드 타입 포인터
public:
	CNode(CUSTOMERINFO CInfo)
		: Customer(new CCustomer), pNext(nullptr)
	{
		Customer->GetInfo() = CInfo;
	}
	CNode* GetNext() { return pNext; }
	CCustomer* GetCustomer() { return Customer; }
	void SetNext(CNode* pNode)
	{
		pNext = pNode;
	}
};
