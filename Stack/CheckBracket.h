#pragma once
#include<iostream>
#include "L.ListStack.h"
#include "L.ListStack.cpp"
// ��ȣ�����ϴµ� �ʿ��� ��
/*
	�ϴ� ������ ���ڿ�.
	������ ���ڿ��� �ϳ��� Ȯ���ϸ鼭 ���� ��ȣ�� ������ ���ÿ� �ֱ�.

	�ݴ� ��ȣ�� ������ ���ÿ� ��ȣ�� �ִ��� Ȯ�� �� ������ ������ ���� ��ȣ�� ���ϸ� ¦�� �´��� üũ
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
