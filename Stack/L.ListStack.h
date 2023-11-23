#pragma once
#include<iostream>

//클래스 이용해서 구현해보기
/*
	노드 클래스, 링크드 리스트 클래스
	스택 클래스 3개.
	스택에서 멤버함수에서 링크드 리스트의 함수 호출
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
	int iLength;	//현재 길이
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
