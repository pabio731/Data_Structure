#include"pch.h"

// 재귀 호출을 이용한 팩토리얼
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

// 반복을 이용한 팩토리얼
int Factorial_Iter(int iNumber)
{
	int iRet(1);

	for (int i = iNumber; i > 1; --i)
	{
		iRet = iRet * i;
	}

	return iRet;
}

/* 팩토리얼 함수가 꼬리 재귀 호출 방식으로 구현되었기 때문에 비교적 쉽게
   반복 호출로 변환됨. 꼬리 재귀 호출이란 재귀 호출이 함수의 끝 부분에 있는 것*/

int main()
{
	int iInput(0), iResult(0);

	cout << "Input A Number" << endl;
	cin >> iInput;

	iResult = Factorial(iInput);

	cout << iResult << endl;
}