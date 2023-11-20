#pragma once
#include<iostream>
//#include"ArrayList.h"
//#include"LinkedList.h"
#ifdef _DEBUG

#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

#ifndef DBG_NEW

#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
#define new DBG_NEW

#endif
#endif

using namespace std;

#pragma region 배열 리스트

//int main()
//{
//	LIST* pList = nullptr;
//	CHARNODE* pValue = nullptr;
//
//	pList = CreateList(10);
//	if (pList != nullptr)
//	{
//		CHARNODE Node;
//
//		Node.szEelm = 'K';
//		AddElement(pList, 0, Node);
//
//		Node.szEelm = 'u';
//		AddElement(pList, 1, Node);
//
//		Node.szEelm = 'H';
//		AddElement(pList, 2, Node);
//
//		Node.szEelm = 'a';
//		AddElement(pList, 3, Node);
//
//		Node.szEelm = 'o';
//		AddElement(pList, 4, Node);
//
//		Node.szEelm = 'R';
//		AddElement(pList, 5, Node);
//
//		DisplayList(pList);
//		RemoveElement(pList, 4);
//		GetElement(pList, 4);
//		DisplayList(pList);
//		ClearList(pList);
//		DisplayList(pList);
//
//	}
//}
#pragma endregion

#pragma region 링크드 리스트

//int main()
//{
//	List* LinkedList = new List;
//	Node* NewNode = new Node(0);
//	int iValue(0), iPosition(0), iMenu(0);
//	bool bCheck = false;
//	std::cout << "Linked List의 작동을 확인합니다." << std::endl;
//	while (true)
//	{
//		system("cls");
//		std::cout << "1. 첫 데이터.   2. 중간 데이터.   3. 마지막 데이터." << std::endl;
//		std::cout << "4. 삭제.   5. 길이확인.   6. 특정 위치 데이터 확인   7. 모두 보기" << std::endl;
//		std::cin >> iMenu;
//
//		switch (iMenu)
//		{
//		case 1:
//			std::cout << "원하는 데이터 값(정수)를 입력 >>";
//			std::cin >> iValue;
//			bCheck = LinkedList->AddDataFirst(NewNode, iValue);
//			if (bCheck)	std::cout << "성공" << std::endl;
//			break;
//
//		case 2:
//			std::cout << "원하는 데이터 값(정수)를 입력 >>";
//			std::cin >> iValue;
//			std::cout << "원하는 위치(정수)를 입력 >>";
//			std::cin >> iPosition;
//			bCheck = LinkedList->AddDataMiddle(NewNode, iPosition, iValue);
//			if (bCheck)	std::cout << "성공" << std::endl;
//			break;
//
//		case 3:
//			std::cout << "원하는 데이터 값(정수)를 입력 >>";
//			std::cin >> iValue;
//			bCheck = LinkedList->AddDataLast(NewNode, iValue);
//			if (bCheck)	std::cout << "성공" << std::endl;
//			break;
//
//		case 4:
//			std::cout << "원하는 위치(정수)를 입력 >>";
//			std::cin >> iPosition;
//			bCheck = LinkedList->RemoveData(iPosition);
//			break;
//
//		case 5:
//			std::cout << "현재 길이 >>" << LinkedList->GetLenth() << std::endl;
//			break;
//
//		case 6:
//			std::cout << "원하는 위치(정수)를 입력 >>";
//			std::cin >> iPosition;
//			if(LinkedList->GetData(iPosition))
//				std::cout << iPosition << "인덱스의 값은 " << LinkedList->GetData(iPosition) << std::endl;
//			break;
//
//		case 7:
//			std::cout << "모든 값을 출력합니다" << std::endl;
//			LinkedList->DisplayAll();
//			break;
//
//		default:
//			std::cout << "잘못 입력했습니다. 다시 입력 해주세요" << std::endl;
//			break;
//		}
//		system("pause");
//	}
//}

#pragma endregion

#pragma region 이중 링크드 리스트

#include "LinkedList2.h"
int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	int iMenu(0), iData(0), iPosition(0);
	List DLinkedList;
	std::cout << "이중 링크드 리스트 테스트" << std::endl;

	while (true)
	{
		system("pause");
		system("cls");
		std::cout << "1. 0번 인덱스에 데이터 추가\n";
		std::cout << "2. 중간 인덱스에 데이터 추가\n";
		std::cout << "3. 마지막 인덱스에 데이터 추가\n";
		std::cout << "4. 원하는 인덱스의 데이터 삭제\n";
		std::cout << "5. 원하는 인덱스의 데이터 확인\n";
		std::cout << "6. 모든 인덱스의 데이터 확인\n";
		std::cout << "7. 리스트의 길이 확인\n";
		std::cout << "8. 리스트의 모든 데이터 삭제\n";
		std::cout << "9. 종료\n";

		std::cin >> iMenu;

		switch (iMenu)
		{
		case 1:
			std::cout << "원하는 값 입력 >>";
			std::cin >> iData;
			DLinkedList.InsertHead(iData);
			continue;

		case 2:
			std::cout << "원하는 값 입력 >>";
			std::cin >> iData;
			std::cout << "원하는 인덱스 입력 >>";
			std::cin >> iPosition;
			DLinkedList.Insert(iPosition, iData);
			continue;

		case 3:
			std::cout << "원하는 값 입력 >>";
			std::cin >> iData;
			DLinkedList.InsertTail(iData);
			continue;

		case 4:
			std::cout << "삭제를 원하는 위치 입력 >>";
			std::cin >> iPosition;
			DLinkedList.DeleteNode(iPosition);
			continue;

		case 5:
			std::cout << "원하는 인덱스 입력 >>";
			std::cin >> iPosition;
			std::cout << DLinkedList.GetData(iPosition) << std::endl;
			continue;

		case 6:
			DLinkedList.GetAll();
			continue;

		case 7:
			std::cout << "현재 리스트의 길이 : " << DLinkedList.GetLenth() << std::endl;
			continue;

		case 8:
			std::cout << "모든 데이터를 삭제합니다." << std::endl;
			DLinkedList.Clear();
			continue;

		case 9:
			return 0;

		default:
			std::cout << "잘못 입력 했습니다" << std::endl;
			continue;
		}
	}
}
#pragma endregion