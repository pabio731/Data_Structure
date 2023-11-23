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

bool List::AddDataFirst(Node* NewNode, const int& iData)
{
	NewNode = new Node(iData);	
	
	//첫 번째 노드가 없는 상황
	if (Head == nullptr)
	{
		Head = NewNode;
		Tail = NewNode;
		Cur = NewNode;
	}
	else   //이미 첫 번째 노드가 있는 상황
	{
		NewNode->NextNode = Head;
		Head = NewNode;
	}
	++iLenth;
	return true;
}

bool List::AddDataMiddle(Node* NewNode, const int& iPosition, const int& iData)
{
	//추가 성공 true, 실패 false
	if (nullptr == Head)
	{
		std::cout << "오류. 리스트가 비어 있습니다. 처음부터 연결해 주세요" << std::endl;
		return false;
	}
	
	if (iPosition  < 0 || iPosition >= GetLenth())
	{
		std::cout << "오류, 위치가 잘못되었습니다." << std::endl;
		return false;
	}

	//예외 상황에 걸리지 않으면 노드 생성 후 넣는 작업
	NewNode = new Node(iData);
	Cur = Head;
	for (int i = 0; i < iPosition-1; ++i)
	{
		Cur = Cur->NextNode;	//새로운 노드가 들어갈 위치의 전 노드를 가리키기.
	}
	
	NewNode->NextNode = Cur->NextNode;	//새 노드의 포인터를 다음 노드에
	Cur->NextNode = NewNode;	//이전 노드의 포인터를 새 노드에
	++iLenth;
	return true;
	
}

//마지막 노드에 넣는 것은 Tail이용
bool List::AddDataLast(Node* NewNode, const int& iData)
{
	if (nullptr == Head)
	{
		std::cout << "오류. 리스트가 비어 있습니다. 처음부터 연결해 주세요" << std::endl;
		return false;
	}
	else
	{
		NewNode = new Node(iData);
		Tail->NextNode = NewNode;
		Tail = NewNode;
		++iLenth;
		return true;
	}
}

bool List::RemoveData(const int& iPosition)
{
	if (nullptr == Head)
	{
		std::cout << "오류. 리스트가 비어 있습니다." << std::endl;
		return false;
	}
	if (iPosition < 0 || iPosition > GetLenth())
	{
		std::cout << "오류, 위치가 잘못되었습니다." << std::endl;
		return false;
	}

	// 예외 상황에 걸리지 않은 경우
	
	Node* Tmp;
	Cur = Head;
	if (1 == GetLenth())
	{
		delete Cur;
		Cur = nullptr;
		Head = nullptr;
		return true;
	}
	for (int i = 0; i < iPosition-1; ++i)
	{
		Cur = Cur->NextNode;	//해당 노드 이전 노드 가리키게
	}
	Tmp = Cur->NextNode;	//삭제할 노드를 가리킴

	//이전 노드를 삭제하는 노드의 다음 노드를 가리키게 하고, 
	// 삭제할 노드는 연결을 끊음.

	if(nullptr != Tmp->NextNode)	//중간의 노드를 삭제하는 경우.
	{
		Cur->NextNode = Tmp->NextNode;
		Tmp->NextNode = nullptr;
	}
	else	//마지막 노드를 삭제하는 경우
	{
		Cur->NextNode = nullptr;
		Tmp->NextNode = nullptr;
		Tail = Cur;
	}
	--iLenth;
	delete Tmp;
	Tmp = nullptr;
	
	return true;
}

int List::GetLenth()
{
	return iLenth;
}

int List::GetData(const int& iPosition)
{
	if (nullptr == Head)
	{
		std::cout << "오류. 리스트가 비어 있습니다." << std::endl;
		return 0;
	}
	if (iPosition < 0 || iPosition >= GetLenth())
	{
		std::cout << "오류, 위치가 잘못되었습니다." << std::endl;
		return 0;
	}

	//예외 상황에 걸리지 않을 때.
	
	Cur = Head;
	for (int i = 0; i <= iPosition-1; ++i)
	{
		Cur = Cur->NextNode;
	}

	return Cur->GetData();
}

void List::DisplayAll()
{
	if (nullptr == Head)
	{
		std::cout << "오류. 리스트가 비어 있습니다." << std::endl;
		return;
	}
	else
	{
		for (Cur = Head; Cur != Tail; Cur=Cur->NextNode)
		{
			std::cout << Cur->GetData() << " ";
		}
		std::cout << Tail->GetData() << std::endl;
	}
}
//*******************************************************

// 삭제하고 하나 또는 아무것도 남지 않았을 때의 처리 
// 오류 상황 iPosition 관련 다시 체크
// 잘못된 값 들어가면 무한 프로그램 멈추는 것 체크.
