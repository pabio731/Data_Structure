#include<iostream>

#pragma region ArrayStack

//#include "ArrayStack.h"
//int main()
//{
//	int iSize(0), iMenu(0);
//	char szData;
//	ARRSTACK* ArrStack;
//
//	std::cout << "������ ����� �Է� >>";
//	std::cin >> iSize;
//
//	ArrStack = CreateStack(iSize);
//
//	while (true)
//	{
//		system("pause");
//		system("cls");
//		std::cout << "1. Ǫ��  2. ��  3. ��ũ  4. ����á���� Ȯ��  5. ����ִ��� Ȯ�� 6. ���� ���� >>";
//		std::cin >> iMenu;
//
//		switch (iMenu)
//		{
//		case 1:
//			std::cout << "���ϴ� ���� �Է� >>";
//			std::cin >> szData;
//			Push(ArrStack, szData);
//			continue;
//		case 2:
//			std::cout << ArrStack->iCurElem << "��° ������ : " << Pop(ArrStack) << " ����" << std::endl;
//			continue;
//		case 3:
//			std::cout << "���� Top ������ : " << Peek(ArrStack) << std::endl;
//			continue;
//		case 4:
//			if (IsFull(ArrStack))
//			{
//				std::cout << "���� ������ ���� á���ϴ�." << std::endl;
//			}
//			else
//			{
//				std::cout << "���� ������ ���� ���� �ʾҽ��ϴ�" << std::endl;
//			}
//			continue;
//		case 5:
//			if (IsEmpty(ArrStack) == true)
//			{
//				std::cout << "���� ������ ����ֽ��ϴ�." << std::endl;
//			}
//			else
//			{
//				std::cout << "���� ������ ������� �ʽ��ϴ�." << std::endl;
//			}
//			continue;
//		case 6:
//			DeleteStack(ArrStack);
//			std::cout << "�����Ϸ�" << std::endl;
//			return 0;
//		default:
//			break;
//		}
//	}
//}

#pragma endregion

#pragma region Stack With Linked List
//#include"L.ListStack.h"
//#include"L.ListStack.cpp"
//
//int main()
//{
//	int iMenu(0), iData(0), iTmp(0), iDst(0);
//	LStack<int>* pStack = new LStack<int>;
//
//	while (true)
//	{
//		system("pause");
//		system("cls");
//		std::cout << "1.Push   ";
//		std::cout << "2.Pop   ";
//		std::cout << "3.Peek   ";
//		std::cout << "4.IsEmpty?   ";
//		std::cout << "5.Number of Data   ";
//		std::cout << "0. Exit   ";
//		std::cout << ">>";
//		std::cin >> iMenu;
//
//		switch (iMenu)
//		{
//			//push
//		case 1:
//			std::cout << "please Input a Data >>";
//			std::cin >> iData;
//			if (pStack->Push(iData))
//			{
//				std::cout << "Push Complete" << std::endl;
//			}
//			else
//			{
//				std::cout << "Fail to Push" << std::endl;
//			}
//			continue;
//			//pop
//		case 2:
//			iTmp = pStack->Pop();
//			if (-1 != iTmp)
//				std::cout << iTmp << " Data Node Pop!" << std::endl;
//			continue;
//			//peek
//		case 3:
//			iDst = pStack->Peek();
//			if (iDst != -1)
//				std::cout << "Data on the Top is " << iDst << std::endl;
//			continue;
//			//IsEmpty
//		case 4:
//			if (pStack->IsEmpty())
//			{
//				std::cout << "Stack is Empty!" << std::endl;
//			}
//			else
//			{
//				std::cout << "Stack is Not Empty!" << std::endl;
//			}
//			continue;
//		case 5:
//			pStack->Lenth();
//			continue;
//		case 0:
//			delete pStack;
//			pStack = nullptr;
//			return 0;
//			break;
//		default:
//			std::cout << "Pleese Input 0~5" << std::endl;
//			break;
//		}
//	}
//}
#pragma endregion

#pragma region Check Bracket Balance
#include"CheckBracket.h"
#include<string>std::getline
int main()
{
	std::string Src;
	std::cout << "Please Input String >>";
	getline(std::cin, Src);

	CheckBracket CheckB(Src);
	if (CheckB.Check())
	{
		std::cout << "Balanced!" << std::endl;
	}
	else
	{
		std::cout << "Not Balanced!" << std::endl;
	}
	return 0;
}
#pragma endregion