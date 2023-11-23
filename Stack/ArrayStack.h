#pragma once

typedef struct ArrNode
{
	char szData;
}ARRNODE;

typedef struct ArrStack
{
	int iMaxElem;
	int iCurElem;
	ARRNODE* pElem;
}ARRSTACK;

ARRSTACK* CreateStack(const int& iMaxElem);
void DeleteStack(ARRSTACK* pStack);
bool Push(ARRSTACK* pStack, const char& dzData);
char Pop(ARRSTACK* pStack);
char Peek(ARRSTACK* pStack);
bool IsFull(ARRSTACK* pStack);
bool IsEmpty(ARRSTACK* pStack);
