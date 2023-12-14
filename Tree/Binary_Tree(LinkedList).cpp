#include "Binary_Tree(LinkedList).h"
// 배열을 이용한 트리는 배열의 인덱스가 노드의 번호인 것이 핵심
// 노드 i의 부모 노드 인덱스 : ceil(i/2) 단 i > 1
// 노드 i의 왼쪽 자식 노드 인덱스 : i*2
// 노드 i의 오른쪽 자식 노드 인덱스  : (i*2)+1

// 빈 노드가 많아지면 메모리 낭비가 심해진다.
// 높이가 h인 노드는 배열의 원소로 2^h-1+1r개 필요

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
		cout << "부모 노드가 존재하지 않음." << endl;
		return;
	}
	else
	{
		NODE* newNode = new(nothrow) NODE;
		if (!newNode)
		{
			cout << "새로운 노드의 메모리 할당 실패." << endl;
			return;
		}
		else
		{
			newNode->iData = _iData;
			if (nullptr != _pParantNode)
			{
				_pParantNode->tLeftChild = newNode;
				cout << "노드 추가 완료." << endl;
			}
			else
			{
				cout << "이미 노드가 존재합니다." << endl;
			}
		}
		return;
	}
}

void CBinaryTreeLinkedList::InsertRight(NODE* _pParantNode, int _iData)
{
	if (nullptr == tRootNode)
	{
		cout << "부모 노드가 존재하지 않음." << endl;
		return;
	}
	else
	{
		NODE* newNode = new(nothrow) NODE;
		if (!newNode)
		{
			cout << "새로운 노드의 메모리 할당 실패." << endl;
		}
		else
		{
			newNode->iData = _iData;
			if (nullptr != _pParantNode)
			{
				_pParantNode->trightChild = newNode;
				cout << "노드 추가 완료." << endl;
			}
			else
			{
				cout << "이미 노드가 존재합니다." << endl;
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
		cout << "부모 노드가 존재하지 않음." << endl;
		return nullptr;
	}
	else
	{
		if (nullptr == _pParantNode->tLeftChild)
		{
			cout << "왼쪽 자식이 존재 하지 않음." << endl;
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
		cout << "부모 노드가 존재하지 않음." << endl;
		return nullptr;
	}
	else
	{
		if (nullptr == _pParantNode->trightChild)
		{
			cout << "오른쪽 자식이 존재 하지 않음." << endl;
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
		cout << "노드가 존재 하지 않습니다." << endl;
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
		cout << "노드가 존재하지 않습니다." << endl;
		return;
	}
	else
	{
		_tNode->iData = _iData;
	}
}

void CBinaryTreeLinkedList::Preorder(NODE* _pNode)
{
	//중앙->좌->우 순서 선회
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
	//좌 ->중간 -> 우 순서로 순회
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
	//좌 -> 우
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