#include"pch.h"

int Fib(int iNumber)
{
	int iRet = 0;

	if (0 == iNumber)
	{
		iRet = 0;
	}
	else if (iNumber == 1)
	{
		iRet = 1;
	}
	else
	{
		iRet = Fib(iNumber - 1) + Fib(iNumber - 2);
	}

	return iRet;
}

// �Ǻ���ġ ������ ��� ȣ�� ������� ���� ������ �ſ� ��ȿ������ �����
// ���� ���ڿ� ���� �Ǻ���ġ ���� ����� �ߺ����� �ݺ��ϱ� ������

int Fib_iter(int iNumber)
{
	int iRet(0);

	if (2 >= iNumber)
	{
		iRet = iNumber;
	}
	else
	{
		int iTmp(0), iCurrent(1), iLast(0);

		for (int i = 2; i <= iNumber; ++i)
		{
			iTmp = iCurrent;	// ��������� ���� ����
			iCurrent += iLast;	// ������ ���� ������
			iLast = iTmp;		//
		}

		iRet = iCurrent;
	}

	return iRet;
}