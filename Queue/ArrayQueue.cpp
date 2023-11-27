#include"ArrayQueue.h"

//ť�� ����
ARRQUE* CreateArrQueue(int iMaxElemNum)
{
	if (iMaxElemNum > 0)
	{
		ARRQUE* pQue = new(std::nothrow) ARRQUE(iMaxElemNum, 0, -1, -1);
		if (!pQue)
		{
			cout << "ť �޸� �Ҵ� ����" << endl;
			return nullptr;
		}
		pQue->pElem = new(std::nothrow) QNODE[iMaxElemNum];
		if (!(pQue->pElem))
		{
			cout << "�迭 �޸� �Ҵ� ����" << endl;
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

//ť�� �����͸� �ִ� �Լ�
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

//ť���� �����͸� ��ȯ�ϰ� ����
char Dequeue(ARRQUE* pQue)
{	// ť�� �ִ���, ť�� �������, ù �ε����� ���ư����ϴ���
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

//ť���� ���� ���� �����͸� �������� �ʰ� ��ȯ
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

//ť�� ����
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

//ť�� ���� á���� Ȯ��
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

//ť�� ������� Ȯ��
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