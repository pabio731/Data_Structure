#include"L.ListStack.h"

template<typename T>
StackNode<T>::StackNode(const T& Data) : Data(Data)
{
	Next = nullptr;
}
template<typename T>
int StackNode<T>::GetData()
{
	return Data;
}

template<typename T>
LStack<T>::LStack() :iLength(0), Tail(nullptr), Head(nullptr) {}

template<typename T>
bool LStack<T>::Push(T Data)
{
	StackNode<T>* pNode = new(std::nothrow) StackNode<T>(Data);
	if (!pNode)
	{
		std::cout << "Fail to Memory Allocation" << std::endl;
		return false;
	}
	if (nullptr == Tail && nullptr == Head)
	{
		pNode->Next = nullptr;
		Head = pNode;
	}
	else
	{
		pNode->Next = Tail;
	}
	Tail = pNode;
	++iLength;
	return true;
}

template<typename T>
T LStack<T>::Pop()
{
	// Data를 임시 변수에 복사해준다.
	// 현재 Top의 주소를 임시 포인터에 넘겨주고
	// 다음 Top을 Tail로
	// 임시포인터 delete, null
	if (nullptr != Head)
	{
		T Tmp = this->Tail->GetData();
		StackNode<T>* pDst;
		pDst = this->Tail->Next;
		delete this->Tail;

		if (0 >= --iLength)
		{
			this->Tail = nullptr;
			this->Head = nullptr;
		}
		else
		{
			this->Tail = pDst;
		}

		return Tmp;
	}
	else
	{
		std::cout << "List in Stack is Null" << std::endl;
		return -1;
	}
}

template<typename T>
T LStack<T>::Peek()
{
	if (nullptr != Head)
	{
		return this->Tail->GetData();
	}
	else
	{
		std::cout << "List in Stack is Null" << std::endl;
		return -1;
	}
}

template<typename T>
bool LStack<T>::IsEmpty()
{
	if (nullptr != Head)
	{
		if (0 >= this->iLength)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		std::cout << "List in Stack is Null" << std::endl;
		return true;
	}
}

template<typename T>
void LStack<T>::Lenth()
{
	if (nullptr != Head)
	{
		std::cout << "There are " << iLength << "Datas in the STack." << std::endl;
		return;
	}
	else
	{
		std::cout << "List in Stack is Null" << std::endl;
		return;
	}
}