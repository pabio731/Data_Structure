#include"ArrayStack.h"
#include <iostream>

// 스택 구조체 메모리를 할당하여 주소를 반환하는 함수
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
			std::cout << "스택 생성 메모리 할당 오류." << std::endl;
			return nullptr;
		}

		pStack->pElem = new ARRNODE[pStack->iMaxElem];
		return pStack;
	}
	else
	{
		std::cout << "스택의 갯수는 0이상이어야 합니다." << std::endl;
		return nullptr;
	}
}

// 스택을 삭제하는 함수(스택에 할당받은 힙메모리 권한 반한)
void DeleteStack(ARRSTACK* pStack)
{
	if (pStack == nullptr)
	{
		std::cout << "스택이 없습니다.";
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

// 스택에 노드를 추가(푸시)
bool Push(ARRSTACK* pStack, const char& szData)
{
	if (pStack == nullptr)
	{
		std::cout << "스택이 없습니다.";
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
			std::cout << "스택이 가득 찼습니다." << std::endl;
			return false;
		}
		return true;
	}
}

// 스택에서 노드를 꺼내면서 데이터를 리턴
char Pop(ARRSTACK* pStack)
{
	if (pStack == nullptr)
	{
		std::cout << "스택이 없습니다.";
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
			std::cout << "스택에 데이터가 없습니다." << std::endl;
			return 0;
		}
	}
}

// 스택에서 노드를 꺼내지 않고 데이터만 리턴
char Peek(ARRSTACK* pStack)
{
	if (pStack == nullptr)
	{
		std::cout << "스택이 없습니다.";
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
			std::cout << "스택이 비어있습니다." << std::endl;
			return 0;
		}
	}
}

// 스택이 가득 찼는지 확인
bool IsFull(ARRSTACK* pStack)
{
	if (pStack == nullptr)
	{
		std::cout << "스택이 없습니다.";
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

// 스택이 비어있는지 확인
bool IsEmpty(ARRSTACK* pStack)
{
	if (pStack == nullptr)
	{
		std::cout << "스택이 없습니다.";
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