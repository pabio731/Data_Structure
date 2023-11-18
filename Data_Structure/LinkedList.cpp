#include"LinkedList.h"

//********** NodeŬ������ ��� �Լ� ���� **********
Node::Node(const int& iData) : iData(iData), NextNode(nullptr) {}

int Node::GetData() { return iData; }
//*************************************************


// ********** List Ŭ���� ��� �Լ��� ���� **********
List::List() : Head(nullptr), Tail(nullptr), Cur(nullptr),iLenth(0)
{}

List::~List()
{
	delete Head;
	Head = nullptr;
	Tail = nullptr;
	Cur = nullptr;
}

//bool List::AddDataFirst(Node NewNode, int iData)
// Head�� �����Ҵ� �� ���� �ְԵǸ�
// ��� ��带 �����Ҵ� �ϰ� ������.
bool List::AddData(Node* NewNode, int iPosition)
{
	bool ret = true;
	if (0 == iPosition && nullptr == Head)
	{
		Head = NewNode;
	}
	else
	{
		if (iPosition < 0 || iPosition > GetLenth())
		{
			std::cout << "����. ��ġ�� �߸� �ƽ��ϴ�." << std::endl;
			ret = false;
		}
		else
		{
			//Cur �����Ͱ� iPosition ��ġ ���� ��带 ����Ű��
			for (int i = 0; i < iPosition-1; ++i)
			{
				Cur = Head->NextNode;	
			}
			//���� �� ����� �����Ͱ� ���� ��带 ����Ű��
			NewNode->NextNode = Cur->NextNode;
			
			//������ ��尡 
		}
		
	}
}
//*******************************************************


// ********** ���� ��� �Լ��� ���� **********
List* Create::CreateList()
{
	return new List;
}

Node* Create::CreateNode(int iData)
{
	return new Node(iData);
}
//*********************************************