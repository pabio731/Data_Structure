#pragma once
#include<iostream>

//Ŭ���� �̿��ؼ� �����غ���
/*
	��� Ŭ����, ��ũ�� ����Ʈ Ŭ����
	���� Ŭ���� 3��.
	���ÿ��� ����Լ����� ��ũ�� ����Ʈ�� �Լ� ȣ��
*/
template<typename T>
class StackNode
{
private:
	T Data;
public:
	StackNode(const T& iData);
	int GetData();
	StackNode<T>* Next;
};

template<typename T>
class LStack
{
private:
	int iLength;	//���� ����
	StackNode<T>* Tail;
	StackNode<T>* Head;

public:
	LStack();
	bool Push(T Data);
	T Pop();
	T Peek();
	bool IsEmpty();
	void Lenth();
};
