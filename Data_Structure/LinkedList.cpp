#include"LinkedList.h"

//********** Node클래스의 멤버 함수 정의 **********
Node::Node(const int& iData) : iData(iData), NextNode(nullptr) {}

int Node::GetData() { return iData; }
//*************************************************


// ********** List 클래스 멤버 함수의 정의 **********
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
// Head를 동적할당 한 이후 주게되면
// 모든 노드를 동적할당 하게 만들자.
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
			std::cout << "오류. 위치가 잘못 됐습니다." << std::endl;
			ret = false;
		}
		else
		{
			//Cur 포인터가 iPosition 위치 전의 노드를 가리키게
			for (int i = 0; i < iPosition-1; ++i)
			{
				Cur = Head->NextNode;	
			}
			//새로 들어갈 노드의 포인터가 다음 노드를 가리키게
			NewNode->NextNode = Cur->NextNode;
			
			//이전의 노드가 
		}
		
	}
}
//*******************************************************


// ********** 정적 멤버 함수들 정의 **********
List* Create::CreateList()
{
	return new List;
}

Node* Create::CreateNode(int iData)
{
	return new Node(iData);
}
//*********************************************