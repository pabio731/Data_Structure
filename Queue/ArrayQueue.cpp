#include"ArrayQueue.h"

//큐를 생성
ARRQUE* CreateArrQueue(int iMaxElemNum)
{
	if (iMaxElemNum > 0)
	{
		ARRQUE* pQue = new(std::nothrow) ARRQUE(iMaxElemNum, 0, -1, -1);
		if (!pQue)
		{
			cout << "큐 메모리 할당 실패" << endl;
			return nullptr;
		}
		pQue->pElem = new(std::nothrow) QNODE[iMaxElemNum];
		if (!(pQue->pElem))
		{
			cout << "배열 메모리 할당 실패" << endl;
			return nullptr;
		}
		return pQue;
	}
	else
	{
		cout << "Please Input Positive Number." << endl;
		return nullptr;
	}
}

//큐에 데이터를 넣는 함수
bool Enqueue(ARRQUE* pQue, QNODE Elem)
{
	if (nullptr != pQue)
	{
		if (false == IsFull(pQue))
		{
			if (++(pQue->iRear) == pQue->iMaxElemNum)
			{
				pQue->iRear = 0;
			}
			pQue->pElem[pQue->iRear] = Elem;
			++(pQue->iCurElemNum);
			return true;
		}
		else
		{
			cout << "ArrayQueue is Full" << endl;
		}
	}
	else
	{
		cout << "There isn't Queue" << endl;
	}
	return false;
}

//큐에서 데이터를 반환하고 삭제
char Dequeue(ARRQUE* pQue)
{	// 큐가 있는지, 큐가 비었는지, 첫 인덱스로 돌아가야하는지
	if (nullptr != pQue)
	{
		if (false == IsEmpty(pQue))
		{
			if (++(pQue->iFront) >= pQue->iMaxElemNum)
			{
				pQue->iFront = 0;
			}
			char szTmp = pQue->pElem[pQue->iFront].Element;
			--(pQue->iCurElemNum);
			return szTmp;
		}
		else
		{
			cout << "There isn't Data in Queue" << endl;
			return 0;
		}
	}
	else
	{
		cout << "There isn't Queue" << endl;
		return 0;
	}
}

//큐에서 다음 나올 데이터를 삭제하지 않고 반환
char Peek(ARRQUE* pQue)
{
	if (nullptr != pQue)
	{
		if (false == IsEmpty(pQue))
		{
			int iTmpIdx = (pQue->iFront) + 1;
			if (iTmpIdx >= pQue->iMaxElemNum)
			{
				iTmpIdx = 0;
			}
			return pQue->pElem[iTmpIdx].Element;
		}
		else
		{
			cout << "Queue is Empty" << endl;
			return 0;
		}
	}
	else
	{
		cout << "There isn't Queue" << endl;
		return 0;
	}
}

//큐를 삭제
void DeleteArrQueue(ARRQUE* pQue)
{
	if (nullptr != pQue)
	{
		delete[] pQue->pElem;
		pQue->pElem = nullptr;
		delete pQue;
		pQue = nullptr;
	}
	else
	{
		cout << "There isn't Queue" << endl;
	}
}

//큐가 가득 찼는지 확인
bool IsFull(ARRQUE* pQue)
{
	if (nullptr != pQue)
	{
		if (pQue->iMaxElemNum == pQue->iCurElemNum)
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
		cout << "There isn't Queue" << endl;
		return false;
	}
}

//큐가 비었는지 확인
bool IsEmpty(ARRQUE* pQue)
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
		cout << "There isn't Queue" << endl;
		return false;
	}
}