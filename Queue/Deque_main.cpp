#include"pch.h"
#include"DL_Deque.h"

int main()
{
	int iMenu(0), iData(0), iOutput(0);
	DLDQUE* pDeque = nullptr;
	cout << "Deque Test" << endl;

	while (true)
	{
		system("pause");
		system("cls");
		cout << "1.CreateDeque" << endl;
		cout << "2.InsertFront" << endl;
		cout << "3.InsertRear" << endl;
		cout << "4.DeleteFront" << endl;
		cout << "5.PeekFront" << endl;
		cout << "6.PeekRear" << endl;
		cout << "7.IsEmpty?" << endl;
		cout << "8.DisplayAll" << endl;
		cout << "9.DeleteDeque" << endl;
		cout << "0.Exit" << endl;
		cin >> iMenu;

		switch (iMenu)
		{
		case 1:
			if (nullptr != pDeque)
			{
				cout << "A Deque Already Exists" << endl;
			}
			else
			{
				pDeque = CreateArrQueue();
			}
			continue;

		case 2:
		{
			cout << "Please Input A Data>> ";
			cin >> iData;
			DLDNODE Node;
			Node.iData = iData;
			if (InsertFront(pDeque, Node))
			{
				cout << "Node Added Successfully" << endl;
			}
			continue;
		}
		case 3:
		{
			cout << "Please Input A Data>> ";
			cin >> iData;
			DLDNODE Node;
			Node.iData = iData;
			if (InsertRear(pDeque, Node))
			{
				cout << "Node Added Successfully" << endl;
			}
			continue;
		}

		case 4:
			iOutput = DeleteFront(pDeque);

			if (0 != iOutput)
			{
				cout << "Front Data '" << iOutput << "' Deleted!" << endl;
			}
			continue;
		case 5:
			iOutput = PeekPront(pDeque);
			if (0 != iOutput)
			{
				cout << "Front Data is '" << iOutput << "'" << endl;
			}
			continue;
		case 6:
			iOutput = PeekRear(pDeque);
			if (0 != iOutput)
			{
				cout << "Rear Data is '" << iOutput << "'" << endl;
			}
			continue;
		case 7:
			if (IsEmpty(pDeque))
			{
				cout << "Deque is Empty!" << endl;
			}
			else
			{
				cout << "Deque isn't Empty!" << endl;
			}
			continue;
		case 8:
			DisplayDeque(pDeque);
			continue;
		case 9:
			DeleteDeque(pDeque);
			continue;
		case 0:
			return 0;
			continue;
		default:
			break;
		}
	}
}