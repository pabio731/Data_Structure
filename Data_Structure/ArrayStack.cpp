#include"ArrayStack.h"
#include <iostream>

// ���� ����ü �޸𸮸� �Ҵ��Ͽ� �ּҸ� ��ȯ�ϴ� �Լ�
ARRSTACK* CreateStack(const int& iMaxElem)
{
	ARRSTACK* pStack = nullptr;

	if (iMaxElem > 0)
	{
		pStack = new(std::nothrow) ARRSTACK;
		if (pStack != nullptr)
		{
			pStack->iMaxElem = iMaxElem;
			pStack->iCurElem = 0;
		}
		else
		{
			std::cout << "���� ���� �޸� �Ҵ� ����." << std::endl;
			return nullptr;
		}

		pStack->pElem = new ARRNODE[pStack->iMaxElem];
		return pStack;
	}
	else
	{
		std::cout << "������ ������ 0�̻��̾�� �մϴ�." << std::endl;
		return nullptr;
	}
}

// ������ �����ϴ� �Լ�(���ÿ� �Ҵ���� ���޸� ���� ����)
void DeleteStack(ARRSTACK* pStack)
{
	if (pStack == nullptr)
	{
		std::cout << "������ �����ϴ�.";
		return;
	}
	else
	{
		delete[]pStack->pElem;
		pStack->pElem = nullptr;

		delete pStack;
		pStack = nullptr;
	}
}

// ���ÿ� ��带 �߰�(Ǫ��)
bool Push(ARRSTACK* pStack, const char& szData)
{
	if (pStack == nullptr)
	{
		std::cout << "������ �����ϴ�.";
		return false;
	}
	else
	{
		if (pStack->iCurElem < pStack->iMaxElem)
		{
			pStack->pElem[pStack->iCurElem].szData = szData;
			pStack->iCurElem++;
		}
		else
		{
			std::cout << "������ ���� á���ϴ�." << std::endl;
			return false;
		}
		return true;
	}
}

// ���ÿ��� ��带 �����鼭 �����͸� ����
char Pop(ARRSTACK* pStack)
{
	if (pStack == nullptr)
	{
		std::cout << "������ �����ϴ�.";
		return 0;
	}
	else
	{
		if (IsEmpty(pStack) == false)
		{
			pStack->iCurElem--;
			char szRet = pStack->pElem[pStack->iCurElem].szData;
			pStack->pElem[pStack->iCurElem].szData = 0;
			return szRet;
		}
		else
		{
			std::cout << "���ÿ� �����Ͱ� �����ϴ�." << std::endl;
			return 0;
		}
	}
}

// ���ÿ��� ��带 ������ �ʰ� �����͸� ����
char Peek(ARRSTACK* pStack)
{
	if (pStack == nullptr)
	{
		std::cout << "������ �����ϴ�.";
		return 0;
	}
	else
	{
		if (IsEmpty(pStack) == false)
		{
			return pStack->pElem[pStack->iCurElem - 1].szData;
		}
		else
		{
			std::cout << "������ ����ֽ��ϴ�." << std::endl;
			return 0;
		}
	}
}

// ������ ���� á���� Ȯ��
bool IsFull(ARRSTACK* pStack)
{
	if (pStack == nullptr)
	{
		std::cout << "������ �����ϴ�.";
		return false;
	}
	else
	{
		if (pStack->iCurElem >= pStack->iMaxElem)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
}

// ������ ����ִ��� Ȯ��
bool IsEmpty(ARRSTACK* pStack)
{
	if (pStack == nullptr)
	{
		std::cout << "������ �����ϴ�.";
		return 0;
	}
	else
	{
		if (0 == pStack->iCurElem)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
}