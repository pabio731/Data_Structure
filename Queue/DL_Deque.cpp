#include"pch.h"
#include"DL_Deque.h"

// 덱을 동적할당하여 반환
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

//덱이 nullptr인지 확인
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

//덱의 가장 앞에 데이터 삽입
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
		if (pDeque->pHead == nullptr)	// 덱이 비었을 때
		{
			pDeque->pHead = pNode;
			pDeque->pRear = pNode;
		}
		else		//덱이 비어있지 않을 때
		{
			pDeque->pHead->pPrev = pNode;
			pNode->pNext = pDeque->pHead;
			pDeque->pHead = pNode;
		}
		++(pDeque->iCurElemNum);
		return true;
	}
}

//덱의 가장 앞의 데이터를 삭제&반환
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

//덱의 마지막에 데이터를 삽입
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
		if (pDeque->pRear == nullptr)	// 덱이 비었을 때
		{
			pDeque->pHead = pNode;
			pDeque->pRear = pNode;
		}
		else		//덱이 비어있지 않을 때
		{
			pDeque->pRear->pNext = pNode;
			pNode->pPrev = pDeque->pRear;
			pDeque->pRear = pNode;
		}
		++(pDeque->iCurElemNum);
		return true;
	}
}

//덱의 마지막의 데이터를 삭제& 반환
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

//덱의 가장 앞의 데이터를 반환
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

//덱의 먀지막의 데이터를 반환
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

//덱을 삭제
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