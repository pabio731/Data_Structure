#include"LLQueue.h"

LLQUE* CreateArrQueue()
{
	LLQUE* RetVal = new LLQUE;
	if (nullptr == RetVal)
	{
		cout << "Fail To Memort Allocation For Queue" << endl;
	}
	return RetVal;
}
bool Enqueue(LLQUE* pQue, LQNODE Elem)
{
	if (pQue != nullptr)
	{
		LQNODE* pNode = new(std::nothrow) LQNODE;
		if (!pNode)
		{
			cout << "Fail To Dynamic Allocation For Node" << endl;
			return false;
		}
		else
		{
			*pNode = Elem;
			pNode->pNext = nullptr;
			if (nullptr == pQue->pFront)
			{
				pQue->pFront = pNode;
				pQue->pRear = pNode;
			}
			else
			{
				pQue->pRear->pNext = pNode;
				pQue->pRear = pNode;
			}
			++(pQue->iCurElemNum);
			return true;
		}
	}
	else
	{
		cout << "There Isn't A Queue. Please Create New Queue" << endl;
		return false;
	}
}

char Dequeue(LLQUE* pQue)
{
	if (nullptr != pQue)
	{
		if (0 != pQue->iCurElemNum)
		{
			char szRet = pQue->pFront->szElem;
			LQNODE* pTmp = pQue->pFront->pNext;
			delete pQue->pFront;
			pQue->pFront = pTmp;
			--(pQue->iCurElemNum);
			return szRet;
		}
		else
		{
			cout << "Fail to Read Node. please Enqueue A New Node to Queue" << endl;
			return 0;
		}
	}
	else
	{
		cout << "There Isn't A Queue. Please Create New Queue" << endl;
		return 0;
	}
}

char Peek(LLQUE* pQue)
{
	if (nullptr != pQue)
	{
		if (0 != pQue->iCurElemNum)
		{
			return pQue->pFront->szElem;
		}
		else
		{
			cout << "Fail to Read Node.please Enqueue A New Node to Queue" << endl;
			return 0;
		}
	}
	else
	{
		cout << "There Isn't A Queue. Please Create New Queue" << endl;
		return 0;
	}
}

void DeleteLLQueue(LLQUE* pQue)
{
	if (nullptr != pQue)
	{
		if (0 != pQue->iCurElemNum)
		{
			LQNODE* pTmp = pQue->pFront;
			while (nullptr != pTmp)
			{
				pQue->pFront = pQue->pFront->pNext;
				delete pTmp;

				pTmp = pQue->pFront;
			}
		}
		delete pQue;
		pQue = nullptr;
	}
	else
	{
		cout << "Queue Is Already Deleted." << endl;
	}
	return;
}

bool IsEmpty(LLQUE* pQue)
{
	if (nullptr != pQue)
	{
		if (0 == pQue->iCurElemNum)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		cout << "There Isn't A Queue. Please Create New Queue" << endl;
		return false;
	}
}