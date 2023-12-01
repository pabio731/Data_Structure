#include"pch.h"

// ��� ȣ���� �̿��� ���丮��
int Factorial(int iNumber)
{
	int iRet = 0;

	if (1 >= iNumber)
	{
		iRet = 1;
	}
	else
	{
		iRet = iNumber * Factorial(iNumber - 1);
	}

	return iRet;
}

// �ݺ��� �̿��� ���丮��
int Factorial_Iter(int iNumber)
{
	int iRet(1);

	for (int i = iNumber; i > 1; --i)
	{
		iRet = iRet * i;
	}

	return iRet;
}

/* ���丮�� �Լ��� ���� ��� ȣ�� ������� �����Ǿ��� ������ ���� ����
   �ݺ� ȣ��� ��ȯ��. ���� ��� ȣ���̶� ��� ȣ���� �Լ��� �� �κп� �ִ� ��*/

int main()
{
	int iInput(0), iResult(0);

	cout << "Input A Number" << endl;
	cin >> iInput;

	iResult = Factorial(iInput);

	cout << iResult << endl;
}