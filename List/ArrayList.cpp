#include<iostream>
#include"ArrayList.h"
//using namespace std;


// 고려해야 할 점.
// 인자로 들어오는 iSize가 0 이상인지.
// 동적할당이 제대로 되었는지.
LIST* CreateList(int iSize)
{
	LIST* pTmp = nullptr;	//동적 할당을 받을 포인터
	
	//복사될 리스트 구조체 동적할당하고, 초기화. 
	if (iSize > 0)
	{
		pTmp = new(std::nothrow) LIST;

		if (pTmp != nullptr)
		{
			pTmp->iSizeOfList = iSize;
			pTmp->iNumOfElem = 0;
			pTmp->pElement = nullptr;
		}
		else
		{
			std::cout << "메모리 할당 오류. CreateList()" << std::endl;
			return nullptr;
		}
	}
	else       //인자로 들어온 배열 리스트의 최대 갯수가 0이하.
	{
		std::cout << "오류, 최대 원소 갯수는 0이상이어야 합니다." << std::endl;
		return nullptr;
	}

	pTmp->pElement = new(std::nothrow) CHARNODE[iSize];
	// 구조체의 배열 리스트를 가리킬 포인터에 동적할당이 안된 경우
	if (pTmp->pElement == nullptr)
	{
		std::cout << "메모리 할당 오류. 배열 리스트 포인터 동적할당 불가." << std::endl;
		delete pTmp;
		pTmp = nullptr;
		return nullptr;
	}
	
	//모든 노드 0으로 초기화
	memset(pTmp->pElement, 0, sizeof(CHARNODE) * iSize);

	return pTmp;
}

// 고려해야할 점
// 인자로 들어오는 리스트가 nullptr인지
void  DeleteList(LIST* ArrayList)
{
	if (ArrayList != nullptr)
	{
		if (ArrayList->pElement != nullptr)
		{
			delete [] ArrayList->pElement;
			ArrayList->pElement = nullptr;
		}
		delete ArrayList;
		ArrayList = nullptr;
	}
}

// 고려해야 할 점
// 인자로 들어오는 리스트가 nullptr인지
bool  IsFull(const LIST* ArrayList)
{
	if (ArrayList != nullptr)
	{
		if (ArrayList->iNumOfElem >= ArrayList->iSizeOfList)
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
		std::cout << "리스트를 다시 확인해주세요" << std::endl;
		return true;
	}
}

// 고려해야할 점
// 인자로 들어온 리스트가 nullptr인지
// 배열이 full인지
// 인자로 들어온 iPosition이 0과 리스트의 최대 크기 사이인지.
bool  AddElement(LIST* ArrayList, int iPosition, CHARNODE Node)
{	
	//예외 상황들 먼저 처리
	// 1. 만들어지지 않은 리스트 포인터가 들어왔을 때,
	if (ArrayList == nullptr)
	{
		std::cout << "오류 발생. 리스트가 없습니다." << std::endl;
		return false;
	}
	
	// 2. 배열이 full인지
	if (IsFull(ArrayList))
	{
		std::cout << "오류 발생. 리스트가 가득 찼습니다." << std::endl;
		return false;
	}

	// 3. 인자로 들어온 iPositon이 0과 리스트의 최대 크기 사이인지.
	if (0 > iPosition || ArrayList->iSizeOfList <= iPosition)
	{
		std::cout << "오류 발생. 위치가 잘못 되었습니다." << std::endl;
		return false;
	}

	//해당 위치에 값이 없는 경우.
	if(ArrayList->pElement[iPosition].szEelm == 0)
	{
		ArrayList->pElement[iPosition].szEelm = Node.szEelm;
	}
	else		//이미 해당 위치에 값이 있는 경우
	{
		int iStart = ArrayList->iNumOfElem - 1;
		for (int i = iStart; i >= iPosition; --i)
		{
			ArrayList->pElement[i].szEelm = ArrayList->pElement[i - 1].szEelm;
		}

		ArrayList->pElement[iPosition].szEelm = Node.szEelm;
	}
	ArrayList->iNumOfElem++;
	return true;

}

// 고려해야할 점
// 인자로 들어온 리스트가 nullptr인지,
// 인자로 들어온 iPosition이 0과 리스트의 최대 크기 사이인지.
bool RemoveElement(LIST* ArrayList, int iPosition)
{
	//예외처리 1. 인자로 들어온 리스트 확인
	if (ArrayList == nullptr)
	{
		std::cout << "오류발생. 리스트가 없습니다." << std::endl;
		return false;
	}
	//예외처리 2. 인자로 들어온 iPosition의 확인
	if (0 > iPosition || ArrayList->iSizeOfList <= iPosition)
	{
		std::cout << "오류 발생. 위치가 잘못 되었습니다." << std::endl;
		return false;
	}
	
	//데이터들을 한칸씩 앞으로.
	for (int i = iPosition; i < ArrayList->iNumOfElem; ++i)
	{
		ArrayList->pElement[i].szEelm = ArrayList->pElement[i + 1].szEelm;
	}
	ArrayList->iNumOfElem--;
	return true;
}

// 고려해야할 점
// 인자로 들어온 리스트가 nullptr인지,
// 인자로 들어온 iposition이 0고 리스트의 최대 크기 사이인지.
CHARNODE* GetElement(LIST* ArrayList, int iPosition)
{
	//예외처리 1. 인자로 들어온 리스트 확인
		if (ArrayList == nullptr)
		{
			std::cout << "오류발생. 리스트가 없습니다." << std::endl;
			return nullptr;
		}
	//예외처리 2. 인자로 들어온 iPosition의 확인
	if (0 > iPosition || ArrayList->iSizeOfList <= iPosition)
	{
		std::cout << "오류 발생. 위치가 잘못 되었습니다." << std::endl;
		return nullptr;
	}
	CHARNODE* pTmp;
	pTmp = &(ArrayList->pElement[iPosition]);

	return pTmp;
}

// 고려해야할 점
// 인자로 들어온 리스트가 nullptr인지,
void  DisplayList(LIST* ArrayList)
{
	//예외처리 1. 인자로 들어온 리스트 확인
	if (ArrayList == nullptr)
	{
		std::cout << "오류발생. 리스트가 없습니다." << std::endl;
		return;
	}

	std::cout << "최대 원소 갯수 : " << ArrayList->iSizeOfList << std::endl;
	std::cout << "현재 원소 갯수 : " << ArrayList->iNumOfElem << std::endl;
	for (int i = 0; i < ArrayList->iNumOfElem; ++i)
	{
		std::cout << GetElement(ArrayList, i)->szEelm << " ";
	}
	for (int i = ArrayList->iNumOfElem; i < ArrayList->iSizeOfList; ++i)
	{
		std::cout << "Empty" << " ";
	}
	std::cout << std::endl;
}

// 고려해야할 점
// 인자로 들어온 리스트가 nullptr인지,
void ClearList(LIST* ArrayList)
{
	//예외처리 1. 인자로 들어온 리스트 확인
	if (ArrayList == nullptr)
	{
		std::cout << "오류발생. 리스트가 없습니다." << std::endl;
		return;
	}

	// 모든 배열 0초기화
	memset(ArrayList->pElement, 0, sizeof(CHARNODE) * ArrayList->iSizeOfList);
	ArrayList->iNumOfElem = 0;
	
}

