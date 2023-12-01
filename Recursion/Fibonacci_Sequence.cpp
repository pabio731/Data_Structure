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

// 피보나치 수열을 재귀 호출 방식으로 구현 했으나 매우 비효율적인 방법임
// 같은 숫자에 대한 피보나치 수열 계산이 중복으로 반복하기 때문에

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
			iTmp = iCurrent;	// 현재까지의 값을 저장
			iCurrent += iLast;	// 이전의 값을 더해줌
			iLast = iTmp;		//
		}

		iRet = iCurrent;
	}

	return iRet;
}