#include"LinkedList2.h"

Node::Node(int iData)
	: iData(iData), Prev(nullptr), Next(nullptr) {}

int Node::GetData()
{
	return iData;
}

List::List() : iLenth(0), Head(nullptr), Tail(nullptr) {}

//오류시 true반환하는 두 bool타입 함수
bool List::IsEmpty()
{	//자기 자신을 가리키고 있다면 비어있는 상태
	if (Head->Prev == Head && Head->Next == Head)
	{
		std::cout << "리스트가 비어 있습니다." << std::endl;
		return true;
	}
	else
	{
		return false;
	}
}
bool List::CheckPosition(int iPosition)
{
	if (iPosition < 0 || iPosition > GetLenth())
	{
		std::cout << "위치가 잘못됐습니다." << std::endl;
		return true;
	}
	else
	{
		return false;
	}
}

void List::InsertHead(int iData)
{
	Node* pNode = new Node(iData);
	if (IsEmpty())
	{
		Head = pNode;
		Tail = pNode;
	}
	else
	{
		Head->Prev = pNode;
		pNode->Next = Head->Next;
		Head = pNode;
	}
	++iLenth;
}
void List::Insert(int iPosition, int iData)
{
	if (IsEmpty || CheckPosition(iPosition))
		return;
	else
	{
		for (int)
	}
}

void List::InsertTail(int iData);
void List::DeleteNode(int iPosition);
int  List::GetData(int iPosition);
void List::GetAll();
void List::GetLenth()
void List::Clear()