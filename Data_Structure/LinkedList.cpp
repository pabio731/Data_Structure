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

bool List::AddDataFirst(Node* NewNode, const int& iData)
{
	NewNode = new Node(iData);	
	
	//ù ��° ��尡 ���� ��Ȳ
	if (Head == nullptr)
	{
		Head = NewNode;
		Tail = NewNode;
		Cur = NewNode;
	}
	else   //�̹� ù ��° ��尡 �ִ� ��Ȳ
	{
		NewNode->NextNode = Head;
		Head = NewNode;
	}
	++iLenth;
	return true;
}

bool List::AddDataMiddle(Node* NewNode, const int& iPosition, const int& iData)
{
	//�߰� ���� true, ���� false
	if (nullptr == Head)
	{
		std::cout << "����. ����Ʈ�� ��� �ֽ��ϴ�. ó������ ������ �ּ���" << std::endl;
		return false;
	}
	
	if (iPosition  < 0 || iPosition >= GetLenth())
	{
		std::cout << "����, ��ġ�� �߸��Ǿ����ϴ�." << std::endl;
		return false;
	}

	//���� ��Ȳ�� �ɸ��� ������ ��� ���� �� �ִ� �۾�
	NewNode = new Node(iData);
	Cur = Head;
	for (int i = 0; i < iPosition-1; ++i)
	{
		Cur = Cur->NextNode;	//���ο� ��尡 �� ��ġ�� �� ��带 ����Ű��.
	}
	
	NewNode->NextNode = Cur->NextNode;	//�� ����� �����͸� ���� ��忡
	Cur->NextNode = NewNode;	//���� ����� �����͸� �� ��忡
	++iLenth;
	return true;
	
}

//������ ��忡 �ִ� ���� Tail�̿�
bool List::AddDataLast(Node* NewNode, const int& iData)
{
	if (nullptr == Head)
	{
		std::cout << "����. ����Ʈ�� ��� �ֽ��ϴ�. ó������ ������ �ּ���" << std::endl;
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
		std::cout << "����. ����Ʈ�� ��� �ֽ��ϴ�." << std::endl;
		return false;
	}
	if (iPosition < 0 || iPosition > GetLenth())
	{
		std::cout << "����, ��ġ�� �߸��Ǿ����ϴ�." << std::endl;
		return false;
	}

	// ���� ��Ȳ�� �ɸ��� ���� ���
	
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
		Cur = Cur->NextNode;	//�ش� ��� ���� ��� ����Ű��
	}
	Tmp = Cur->NextNode;	//������ ��带 ����Ŵ

	//���� ��带 �����ϴ� ����� ���� ��带 ����Ű�� �ϰ�, 
	// ������ ���� ������ ����.

	if(nullptr != Tmp->NextNode)	//�߰��� ��带 �����ϴ� ���.
	{
		Cur->NextNode = Tmp->NextNode;
		Tmp->NextNode = nullptr;
	}
	else	//������ ��带 �����ϴ� ���
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
		std::cout << "����. ����Ʈ�� ��� �ֽ��ϴ�." << std::endl;
		return 0;
	}
	if (iPosition < 0 || iPosition >= GetLenth())
	{
		std::cout << "����, ��ġ�� �߸��Ǿ����ϴ�." << std::endl;
		return 0;
	}

	//���� ��Ȳ�� �ɸ��� ���� ��.
	
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
		std::cout << "����. ����Ʈ�� ��� �ֽ��ϴ�." << std::endl;
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

// �����ϰ� �ϳ� �Ǵ� �ƹ��͵� ���� �ʾ��� ���� ó�� 
// ���� ��Ȳ iPosition ���� �ٽ� üũ
// �߸��� �� ���� ���� ���α׷� ���ߴ� �� üũ.
