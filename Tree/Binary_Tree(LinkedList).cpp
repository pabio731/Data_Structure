#include "Binary_Tree(LinkedList).h"
// �迭�� �̿��� Ʈ���� �迭�� �ε����� ����� ��ȣ�� ���� �ٽ�
// ��� i�� �θ� ��� �ε��� : ceil(i/2) �� i > 1
// ��� i�� ���� �ڽ� ��� �ε��� : i*2
// ��� i�� ������ �ڽ� ��� �ε���  : (i*2)+1

// �� ��尡 �������� �޸� ���� ��������.
// ���̰� h�� ���� �迭�� ���ҷ� 2^h-1+1r�� �ʿ�

CBinaryTreeLinkedList::CBinaryTreeLinkedList()
	:tRootNode(nullptr)
{
}

CBinaryTreeLinkedList::~CBinaryTreeLinkedList()
{
	Clear(tRootNode);
}

void CBinaryTreeLinkedList::InitTree(int _iData)
{
	tRootNode = new NODE;
	tRootNode->iData = _iData;
}

void CBinaryTreeLinkedList::InsertLeft(NODE* _pParantNode, int _iData)
{
	if (nullptr == _pParantNode)
	{
		cout << "�θ� ��尡 �������� ����." << endl;
		return;
	}
	else
	{
		NODE* newNode = new(nothrow) NODE;
		if (!newNode)
		{
			cout << "���ο� ����� �޸� �Ҵ� ����." << endl;
			return;
		}
		else
		{
			newNode->iData = _iData;
			if (nullptr != _pParantNode)
			{
				_pParantNode->tLeftChild = newNode;
				cout << "��� �߰� �Ϸ�." << endl;
			}
			else
			{
				cout << "�̹� ��尡 �����մϴ�." << endl;
			}
		}
		return;
	}
}

void CBinaryTreeLinkedList::InsertRight(NODE* _pParantNode, int _iData)
{
	if (nullptr == tRootNode)
	{
		cout << "�θ� ��尡 �������� ����." << endl;
		return;
	}
	else
	{
		NODE* newNode = new(nothrow) NODE;
		if (!newNode)
		{
			cout << "���ο� ����� �޸� �Ҵ� ����." << endl;
		}
		else
		{
			newNode->iData = _iData;
			if (nullptr != _pParantNode)
			{
				_pParantNode->trightChild = newNode;
				cout << "��� �߰� �Ϸ�." << endl;
			}
			else
			{
				cout << "�̹� ��尡 �����մϴ�." << endl;
			}
		}
		system("pause");
		return;
	}
}

void CBinaryTreeLinkedList::RemoveLeft(NODE* _pParantNode)
{
	if (nullptr == _pParantNode)
	{
		return;
	}
	else
	{
		delete _pParantNode->tLeftChild;
		_pParantNode->tLeftChild = nullptr;
	}
}

void CBinaryTreeLinkedList::RemoveRight(NODE* _pParantNode)
{
	if (nullptr == _pParantNode)
	{
		return;
	}
	else
	{
		delete _pParantNode->trightChild;
		_pParantNode->trightChild = nullptr;
	}
}

NODE* CBinaryTreeLinkedList::GetLeftChild(NODE* _pParantNode)
{
	if (nullptr == tRootNode)
	{
		cout << "�θ� ��尡 �������� ����." << endl;
		return nullptr;
	}
	else
	{
		if (nullptr == _pParantNode->tLeftChild)
		{
			cout << "���� �ڽ��� ���� ���� ����." << endl;
			return nullptr;
		}
		else
		{
			return _pParantNode->tLeftChild;
		}
	}
}

NODE* CBinaryTreeLinkedList::GetRightChild(NODE* _pParantNode)
{
	if (nullptr == tRootNode)
	{
		cout << "�θ� ��尡 �������� ����." << endl;
		return nullptr;
	}
	else
	{
		if (nullptr == _pParantNode->trightChild)
		{
			cout << "������ �ڽ��� ���� ���� ����." << endl;
			return nullptr;
		}
		else
		{
			return _pParantNode->tLeftChild;
		}
	}
}

int CBinaryTreeLinkedList::GetData(NODE* _pNode)
{
	if (_tNode == nullptr)
	{
		cout << "��尡 ���� ���� �ʽ��ϴ�." << endl;
		return 0;
	}
	else
	{
		return _tNode->iData;
	}
}

void CBinaryTreeLinkedList::SetData(NODE* _pNode, int _iData)
{
	if (nullptr == _tNode)
	{
		cout << "��尡 �������� �ʽ��ϴ�." << endl;
		return;
	}
	else
	{
		_tNode->iData = _iData;
	}
}

void CBinaryTreeLinkedList::Preorder(NODE* _pNode)
{
	//�߾�->��->�� ���� ��ȸ
	if (nullptr == _tNode)
	{
		return;
	}
	else
	{
		cout << _tNode->iData << " ";
		Preorder(_tNode->tLeftChild);
		Preorder(_tNode->trightChild);
	}
}

void CBinaryTreeLinkedList::Inorder(NODE* _pNode)
{
	//�� ->�߰� -> �� ������ ��ȸ
	if (_tNode)
	{
		return;
	}
	else
	{
		Inorder(_tNode->tLeftChild);
		cout << _tNode->iData << " ";
		Inorder(_tNode->trightChild);
	}
}

void CBinaryTreeLinkedList::Postorder(NODE* _pNode)
{
	//�� -> ��
	if (nullptr == _tNode)
	{
		return;
	}
	else
	{
		Postorder(_tNode->tLeftChild);
		Postorder(_tNode->trightChild);
		cout << _tNode->iData << " ";
	}
}

void CBinaryTreeLinkedList::Clear(NODE* _pNode)
{
	if (nullptr == _pNode)
	{
		return;
	}
	else
	{
		Clear(_pNode->tLeftChild);
		Clear(_pNode->trightChild);
		if (_pNode)
		{
			delete _pNode;
			_pNode = nullptr;
		}
	}
}