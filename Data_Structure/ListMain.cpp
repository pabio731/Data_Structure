#pragma once
#include<iostream>
//#include"ArrayList.h"
#include"LinkedList.h"
using namespace std;

#pragma region �迭 ����Ʈ

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

#pragma region ��ũ�� ����Ʈ

int main()
{
	List* LinkedList = new List;
	Node* NewNode = new Node(0);
	int iValue(0), iPosition(0), iMenu(0);
	bool bCheck = false;
	std::cout << "Linked List�� �۵��� Ȯ���մϴ�." << std::endl;
	while (true)
	{
		system("cls");
		std::cout << "1. ù ������.   2. �߰� ������.   3. ������ ������." << std::endl;
		std::cout << "4. ����.   5. ����Ȯ��.   6. Ư�� ��ġ ������ Ȯ��   7. ��� ����" << std::endl;
		std::cin >> iMenu;

		switch (iMenu)
		{
		case 1:
			std::cout << "���ϴ� ������ ��(����)�� �Է� >>";
			std::cin >> iValue;
			bCheck = LinkedList->AddDataFirst(NewNode, iValue);
			if (bCheck)	std::cout << "����" << std::endl;
			break;

		case 2:
			std::cout << "���ϴ� ������ ��(����)�� �Է� >>";
			std::cin >> iValue;
			std::cout << "���ϴ� ��ġ(����)�� �Է� >>";
			std::cin >> iPosition;
			bCheck = LinkedList->AddDataMiddle(NewNode, iPosition, iValue);
			if (bCheck)	std::cout << "����" << std::endl;
			break;

		case 3:
			std::cout << "���ϴ� ������ ��(����)�� �Է� >>";
			std::cin >> iValue;
			bCheck = LinkedList->AddDataLast(NewNode, iValue);
			if (bCheck)	std::cout << "����" << std::endl;
			break;

		case 4:
			std::cout << "���ϴ� ��ġ(����)�� �Է� >>";
			std::cin >> iPosition;
			bCheck = LinkedList->RemoveData(iPosition);
			break;

		case 5:
			std::cout << "���� ���� >>" << LinkedList->GetLenth() << std::endl;
			break;

		case 6:
			std::cout << "���ϴ� ��ġ(����)�� �Է� >>";
			std::cin >> iPosition;
			if(LinkedList->GetData(iPosition))
				std::cout << iPosition << "�ε����� ���� " << LinkedList->GetData(iPosition) << std::endl;
			break;

		case 7:
			std::cout << "��� ���� ����մϴ�" << std::endl;
			LinkedList->DisplayAll();
			break;

		default:
			std::cout << "�߸� �Է��߽��ϴ�. �ٽ� �Է� ���ּ���" << std::endl;
			break;
		}
		system("pause");
	}
}

#pragma endregion
