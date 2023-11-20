#include"LinkedList2.h"

// 노드 클래스 생성자와 멤버 함수.
Node::Node(int iData)
	: iData(iData), Prev(nullptr), Next(nullptr) {}
int Node::GetData()
{
	return iData;
}

List::List() : iLenth(0), Head(nullptr), Tail(nullptr) {}

//오류시 true반환하는 두 bool타입 함수.
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

// 0번 인덱스에 노드를 넣어주는 멤버함수.
void List::InsertHead(int iData)
{
	Node* pNode = new Node(iData);
	if (IsEmpty())		// 첫 번째 노드일 경우.
	{
		Head = pNode;
		Tail = pNode;
		pNode->Next = pNode;
		pNode->Prev = pNode;
	}
	else				//첫 번째 노드가 아닌 경우.
	{
		Head->Prev = pNode;		//뒤로 가는 노드의 Prev 설정
		pNode->Next = Head;		//새 노드의 Next 설정
		pNode->Prev = Tail;		//새 노드의 Prev 설정
		Head = pNode;			// Head 재지정
	}
	++iLenth;
}

// 중간 자리에 노드를 넣어주는 멤버함수.
void List::Insert(int iPosition, int iData)
{
	if (IsEmpty || CheckPosition(iPosition))	// 리스트와 인덱스 오류 확인
		return;
	else
	{
		Node* pNode = new Node(iData);
		Node* pTmp = Head;
		for (int i = 0; i < iPosition-1; ++i)
		{
			pTmp = pTmp->Next;
		}
		//현재 pTmp가 바꿀 위치에 있는 노드 이전 것을 가리키고 있는 상태
		
		pTmp->Next->Prev = pNode;	//해당 인덱스에 있던 노드의 Prev설정
		pNode->Next = pTmp->Next;	//새로 넣을 노드의 Next 설정
		pTmp->Next = pNode;			//해당 인덱스 이전의 노드 Next설정
		pNode->Prev = pTmp;			//새로 넣을 노드의 Prev 설정 
		++iLenth;
	}
}

// 마지막 자리에 노드를 넣어주는 멤버함수.
void List::InsertTail(int iData)
{
	if (IsEmpty)
		return;
	else
	{
		Node* pNode = new Ndoe(iData);
		Tail->Next = pNode;			//원래의 꼬리 노드의 Next 설정
		pNode->Next = Head;			//새 노드의 Next 설정
		pNode->Prev = Tail;			//새 노드의 Prev 설정
		Tail = pNode;				//새 노드를 꼬리노드로 설정
		++iLenth;
	}
}

// 원하는 자리의 노드를 삭제하는 멤버함수.
void List::DeleteNode(int iPosition)
{
	if (IsEmpty || iPosition)
		return;

	//만약 지우는 노드의 자리가 0번 인덱스라면
	else if (0 == iPosition)
	{
		Head->Next->Prev = Tail;	// 1번 인덱스의 Prev 설정
		Tail->Next = Head->Next;	// Tail 노드의 Next 설정
		
		delete Head;
		Head = nullptr;				// 삭제하는 노드의 힙메모리 권한 반환
		
		Head = Tail->Prev;			// Head 포인터를 0번 인덱스 노드 가리키도록 다시 설정
	}

	//만약 지우는 자리의 노드가 마지막 자리(GetLenth()-1 인덱스)라면
	else if (GetLenth() - 1 == iPosition)
	{
		Tail->Prev->Next = Head;	// Tail노드가 될 노드의 Next 설정
		Head->Prev = Tail->Prev;	// Head노드의 Prev 설정

		delete Tail;				// 삭제하는 노드의 힙메모리 권한 반환
		Tail = nullptr;

		Tail = Head->Prev;			// Tail 포인터를 다시 마지막 노드 가리키도록 다시 설정
	}

	//만약 지우는 노드의 자리가 중간이라면
	else
	{
		Node* pTmp;
		
		for (int i = 0; i < iPosition - 1; ++i)
		{
			pTmp = pTmp->Next;		//pTmp가 삭제할 노드 자리의 전 노드를 가리키도록
		}

		
	}
}


int  List::GetData(int iPosition);
void List::GetAll();
void List::GetLenth()
void List::Clear()