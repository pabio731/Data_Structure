#include"LinkedList2.h"

// ��� Ŭ���� �����ڿ� ��� �Լ�.
Node::Node(int iData)
	: iData(iData), Prev(nullptr), Next(nullptr) {}
int Node::GetData()
{
	return iData;
}

List::List() : iLenth(0), Head(nullptr), Tail(nullptr) {}

//������ true��ȯ�ϴ� �� boolŸ�� �Լ�.
bool List::IsEmpty()
{	//�ڱ� �ڽ��� ����Ű�� �ִٸ� ����ִ� ����
	if (Head->Prev == Head && Head->Next == Head)
	{
		std::cout << "����Ʈ�� ��� �ֽ��ϴ�." << std::endl;
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
		std::cout << "��ġ�� �߸��ƽ��ϴ�." << std::endl;
		return true;
	}
	else
	{
		return false;
	}
}

// 0�� �ε����� ��带 �־��ִ� ����Լ�.
void List::InsertHead(int iData)
{
	Node* pNode = new Node(iData);
	if (IsEmpty())		// ù ��° ����� ���.
	{
		Head = pNode;
		Tail = pNode;
		pNode->Next = pNode;
		pNode->Prev = pNode;
	}
	else				//ù ��° ��尡 �ƴ� ���.
	{
		Head->Prev = pNode;		//�ڷ� ���� ����� Prev ����
		pNode->Next = Head;		//�� ����� Next ����
		pNode->Prev = Tail;		//�� ����� Prev ����
		Head = pNode;			// Head ������
	}
	++iLenth;
}

// �߰� �ڸ��� ��带 �־��ִ� ����Լ�.
void List::Insert(int iPosition, int iData)
{
	if (IsEmpty || CheckPosition(iPosition))	// ����Ʈ�� �ε��� ���� Ȯ��
		return;
	else
	{
		Node* pNode = new Node(iData);
		Node* pTmp = Head;
		for (int i = 0; i < iPosition-1; ++i)
		{
			pTmp = pTmp->Next;
		}
		//���� pTmp�� �ٲ� ��ġ�� �ִ� ��� ���� ���� ����Ű�� �ִ� ����
		
		pTmp->Next->Prev = pNode;	//�ش� �ε����� �ִ� ����� Prev����
		pNode->Next = pTmp->Next;	//���� ���� ����� Next ����
		pTmp->Next = pNode;			//�ش� �ε��� ������ ��� Next����
		pNode->Prev = pTmp;			//���� ���� ����� Prev ���� 
		++iLenth;
	}
}

// ������ �ڸ��� ��带 �־��ִ� ����Լ�.
void List::InsertTail(int iData)
{
	if (IsEmpty)
		return;
	else
	{
		Node* pNode = new Ndoe(iData);
		Tail->Next = pNode;			//������ ���� ����� Next ����
		pNode->Next = Head;			//�� ����� Next ����
		pNode->Prev = Tail;			//�� ����� Prev ����
		Tail = pNode;				//�� ��带 �������� ����
		++iLenth;
	}
}

// ���ϴ� �ڸ��� ��带 �����ϴ� ����Լ�.
void List::DeleteNode(int iPosition)
{
	if (IsEmpty || iPosition)
		return;

	//���� ����� ����� �ڸ��� 0�� �ε������
	else if (0 == iPosition)
	{
		Head->Next->Prev = Tail;	// 1�� �ε����� Prev ����
		Tail->Next = Head->Next;	// Tail ����� Next ����
		
		delete Head;
		Head = nullptr;				// �����ϴ� ����� ���޸� ���� ��ȯ
		
		Head = Tail->Prev;			// Head �����͸� 0�� �ε��� ��� ����Ű���� �ٽ� ����
	}

	//���� ����� �ڸ��� ��尡 ������ �ڸ�(GetLenth()-1 �ε���)���
	else if (GetLenth() - 1 == iPosition)
	{
		Tail->Prev->Next = Head;	// Tail��尡 �� ����� Next ����
		Head->Prev = Tail->Prev;	// Head����� Prev ����

		delete Tail;				// �����ϴ� ����� ���޸� ���� ��ȯ
		Tail = nullptr;

		Tail = Head->Prev;			// Tail �����͸� �ٽ� ������ ��� ����Ű���� �ٽ� ����
	}

	//���� ����� ����� �ڸ��� �߰��̶��
	else
	{
		Node* pTmp;
		
		for (int i = 0; i < iPosition - 1; ++i)
		{
			pTmp = pTmp->Next;		//pTmp�� ������ ��� �ڸ��� �� ��带 ����Ű����
		}

		
	}
}


int  List::GetData(int iPosition);
void List::GetAll();
void List::GetLenth()
void List::Clear()