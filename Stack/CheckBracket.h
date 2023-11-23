#pragma once
#include<iostream>
#include "L.ListStack.h"
#include "L.ListStack.cpp"
// 괄호점검하는데 필요한 것
/*
	일단 점검할 문자열.
	점검할 문자열을 하나씩 확인하면서 여는 괄호를 만나면 스택에 넣기.

	닫는 괄호를 만나면 스택에 괄호가 있는지 확인 후 있으면 스택의 여는 괄호를 팝하며 짝이 맞는지 체크
*/
class CheckBracket
{
private:
	std::string Src;
	LStack<char>* Stack;
	int iStrSize;
public:
	CheckBracket(std::string Src);
	~CheckBracket();
	bool Check();
};
