#pragma once
#include "CCustomer.h"

class CNode
{
private:
	CCustomer* Customer;		//���� ������ ������ Ŭ����.
	CNode* pNext;			// ����� ��ũ�帮��Ʈ�� ���� ��� Ÿ�� ������
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
