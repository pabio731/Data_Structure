#include"pch.h"
#include"DL_Deque.h"

// ���� �����Ҵ��Ͽ� ��ȯ
DLDQUE* CreateArrQueue()
{
	DLDQUE* pDeque = new(std::nothrow) DLDQUE;
	if (!pDeque)
	{
		cout << "Fail to Memort Allocation For Deque" << endl;
		return nullptr;
	}
	else
	{
		return pDeque;
	}
}

//���� nullptr���� Ȯ��
bool CheckIsDeque(DLDeque* pDeque)
{
	if (nullptr == pDeque)
	{
		cout << "There isn't Deque. Please Create A New Deque" << endl;
		return true;
	}
	else
	{
		return false;
	}
}

//���� ���� �տ� ������ ����
bool InsertFront(DLDQUE* pDeque, DLDNODE Elem)
{
	if (CheckIsDeque(pDeque))
	{
		return false;
	}
	else
	{
		DLDNODE* pNode = new DLDNODE;
		*pNode = Elem;
		if (pDeque->pHead == nullptr)	// ���� ����� ��
		{
			pDeque->pHead = pNode;
			pDeque->pRear = pNode;
		}
		else		//���� ������� ���� ��
		{
			pDeque->pHead->pPrev = pNode;
			pNode->pNext = pDeque->pHead;
			pDeque->pHead = pNode;
		}
		++(pDeque->iCurElemNum);
		return true;
	}
}

//���� ���� ���� �����͸� ����&��ȯ
int DeleteFront(DLDQUE* pDeque)
{
	if (CheckIsDeque(pDeque))
	{
		return 0;
	}
	else
	{
		if (nullptr != pDeque->pHead)
		{
			int iRetData(0);
			iRetData = pDeque->pHead->iData;
			if (pDeque->pHead == pDeque->pRear)
			{
				delete pDeque->pHead;
				pDeque->pHead = nullptr;
				pDeque->pRear = nullptr;
			}
			else
			{
				pDeque->pHead = pDeque->pHead->pNext;
				delete pDeque->pHead->pPrev;
				pDeque->pHead->pPrev = nullptr;
			}
			--(pDeque->iCurElemNum);
			return iRetData;
		}
		else
		{
			cout << "There Isn't Node to Delete" << endl;
			return 0;
		}
	}
}

//���� �������� �����͸� ����
bool InsertRear(DLDQUE* pDeque, DLDNODE Elem)
{
	if (CheckIsDeque(pDeque))
	{
		return false;
	}
	else
	{
		DLDNODE* pNode = new DLDNODE;
		*pNode = Elem;
		if (pDeque->pRear == nullptr)	// ���� ����� ��
		{
			pDeque->pHead = pNode;
			pDeque->pRear = pNode;
		}
		else		//���� ������� ���� ��
		{
			pDeque->pRear->pNext = pNode;
			pNode->pPrev = pDeque->pRear;
			pDeque->pRear = pNode;
		}
		++(pDeque->iCurElemNum);
		return true;
	}
}

//���� �������� �����͸� ����& ��ȯ
int DeleteRear(DLDQUE* pDeque)
{
	if (CheckIsDeque(pDeque))
	{
		return 0;
	}
	else
	{
		if (nullptr != pDeque->pRear)
		{
			int iRetData(0);
			iRetData = pDeque->pRear->iData;
			if (pDeque->pHead == pDeque->pRear)
			{
				delete pDeque->pRear;
				pDeque->pHead = nullptr;
				pDeque->pRear = nullptr;
			}
			else
			{
				pDeque->pRear = pDeque->pRear->pPrev;
				delete pDeque->pRear->pNext;
				pDeque->pRear->pNext = nullptr;
			}
			--(pDeque->iCurElemNum);
			return iRetData;
		}
		else
		{
			cout << "There Isn't Node to Delete" << endl;
			return 0;
		}
	}
}

//���� ���� ���� �����͸� ��ȯ
int PeekPront(DLDeque* pDeque)
{
	if (CheckIsDeque(pDeque))
	{
		return 0;
	}
	else
	{
		if (nullptr != pDeque->pHead)
		{
			return pDeque->pHead->iData;
		}
		else
		{
			cout << "There Isn't Node to Peek" << endl;
			return 0;
		}
	}
}

//���� �������� �����͸� ��ȯ
int PeekRear(DLDeque* pDeque)
{
	if (CheckIsDeque(pDeque))
	{
		return 0;
	}
	else
	{
		if (nullptr != pDeque->pRear)
		{
			return pDeque->pRear->iData;
		}
		else
		{
			cout << "There Isn't Node to Peek" << endl;
			return 0;
		}
	}
}

//���� ����
void DeleteDeque(DLDQUE* pDeque)
{
	if (CheckIsDeque(pDeque))
	{
		return;
	}
	else
	{
		if (nullptr != pDeque->pHead)
		{
			for (int i = 0; i < pDeque->iCurElemNum; ++i)
			{
				DeleteFront(pDeque);
			}
		}

		delete pDeque;
		pDeque = nullptr;
	}
}

bool IsEmpty(DLDQUE* pDeque)
{
	if (CheckIsDeque(pDeque))
	{
		return false;
	}
	else
	{
		if (0 == pDeque->iCurElemNum)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
}
void DisplayDeque(DLDQUE* pDeque)
{
	if (CheckIsDeque(pDeque))
	{
		return;
	}
	else
	{
		DLDNODE* pTmp = pDeque->pHead;
		cout << "Every Data In Deque" << endl;
		for (int i = 0; i < pDeque->iCurElemNum; ++i)
		{
			cout << pTmp->iData << " ";
			pTmp = pTmp->pNext;
		}
		cout << endl;
	}
}