#pragma region ArrayQueue
//#include "ArrayQueue.h"

//int main()
//{
//	int iMenu(0), iSize(0);
//	char szData(0), szRetData(0);
//	ARRQUE* ArrQue = nullptr;
//
//	cout << "ArrQueue Test..." << endl;
//	while (true)
//	{
//		system("pause");
//		system("cls");
//		cout << "1. Create Queue" << endl;
//		cout << "2. Enqueue" << endl;
//		cout << "3. Dequeue" << endl;
//		cout << "4. Peek" << endl;
//		cout << "5. Is Full?" << endl;
//		cout << "6. Is Empty?" << endl;
//		cout << "7. Delete Queue" << endl;
//		cout << "8. Exit" << endl;
//		cin >> iMenu;
//
//		switch (iMenu)
//		{
//		case 1:
//			cout << "Please Input A Size Of Queue >>";
//			cin >> iSize;
//			ArrQue = CreateArrQueue(iSize);
//			continue;
//
//		case 2:
//			cout << "Please Input A Data >>";
//			cin >> szData;
//			QNODE Node;
//			Node.Element = szData;
//			if (Enqueue(ArrQue, Node))
//			{
//				cout << "Put The Node Successfully." << endl;
//			}
//			continue;
//
//		case 3:
//			szRetData = Dequeue(ArrQue);
//			if (0 == szRetData) {}
//			else
//			{
//				cout << "Data '" << szRetData << "' Deleted" << endl;
//			}
//			continue;
//		case 4:
//			szRetData = Peek(ArrQue);
//			if (0 == szRetData) {}
//			else
//			{
//				cout << "Front Data is '" << szRetData << "'" << endl;
//			}
//			continue;
//		case 5:
//			if (IsFull(ArrQue))
//			{
//				cout << "Queue is Full" << endl;
//			}
//			else
//			{
//				cout << "Queue isn't Full" << endl;
//			}
//			continue;
//		case 6:
//			if (IsEmpty(ArrQue))
//			{
//				cout << "Queue is Empty" << endl;
//			}
//			else
//			{
//				cout << "Queue isn't Empty" << endl;
//			}
//			continue;
//		case 7:
//			DeleteArrQueue(ArrQue);
//			cout << "Queue is Deleted Successfully" << endl;
//			ArrQue = nullptr;
//			continue;
//		case 8:
//			exit(0);
//			continue;
//		default:
//			cout << "Please Input Number Rightly" << endl;
//			break;
//		}
//	}
//}
#pragma endregion

#pragma region Queue With LinkedList
#include"LLQueue.h"
int main()
{
	int iMenu(0), iSize(0);
	char szData(0), szRetData(0);
	LLQUE* pQueue = nullptr;

	cout << "Queue With Linked List Test..." << endl;
	while (true)
	{
		system("pause");
		system("cls");
		cout << "1. Create Queue" << endl;
		cout << "2. Enqueue" << endl;
		cout << "3. Dequeue" << endl;
		cout << "4. Peek" << endl;
		cout << "5. Is Empty?" << endl;
		cout << "6. Delete Queue" << endl;
		cout << "7. Exit" << endl;
		cin >> iMenu;

		switch (iMenu)
		{
		case 1:
			pQueue = CreateArrQueue();
			if (pQueue == nullptr)
			{
				return 0;
			}
			continue;
		case 2:
			cout << "Please Input A Data >>";
			cin >> szData;
			LQNODE Node;
			Node.szElem = szData;
			if (Enqueue(pQueue, Node));
			{
				cout << "Put The Node Successfully." << endl;
			}
			continue;

		case 3:
			szRetData = Dequeue(pQueue);
			if (0 == szRetData) {}
			else
			{
				cout << "Data '" << szRetData << "' Deleted" << endl;
			}
			continue;

		case 4:
			szRetData = Peek(pQueue);
			if (0 == szRetData) {}
			else
			{
				cout << "Front Data is '" << szRetData << "'" << endl;
			}
			continue;

		case 5:
			if (IsEmpty(pQueue))
			{
				cout << "Queue is Empty" << endl;
			}
			else
			{
				cout << "Queue isn't Empty" << endl;
			}
			continue;

		case 6:
			DeleteLLQueue(pQueue);
			cout << "Queue is Deleted Successfully" << endl;
			pQueue = nullptr;
			continue;
		case 7:
			exit(0);
		default:
			cout << "Please Input Number Rightly" << endl;
			continue;
		}
	}
}
#pragma endregion