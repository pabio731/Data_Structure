#include<iostream>
#include"ArrayList.h"
//using namespace std;


// ����ؾ� �� ��.
// ���ڷ� ������ iSize�� 0 �̻�����.
// �����Ҵ��� ����� �Ǿ�����.
LIST* CreateList(int iSize)
{
	LIST* pTmp = nullptr;	//���� �Ҵ��� ���� ������
	
	//����� ����Ʈ ����ü �����Ҵ��ϰ�, �ʱ�ȭ. 
	if (iSize > 0)
	{
		pTmp = new(std::nothrow) LIST;

		if (pTmp != nullptr)
		{
			pTmp->iSizeOfList = iSize;
			pTmp->iNumOfElem = 0;
			pTmp->pElement = nullptr;
		}
		else
		{
			std::cout << "�޸� �Ҵ� ����. CreateList()" << std::endl;
			return nullptr;
		}
	}
	else       //���ڷ� ���� �迭 ����Ʈ�� �ִ� ������ 0����.
	{
		std::cout << "����, �ִ� ���� ������ 0�̻��̾�� �մϴ�." << std::endl;
		return nullptr;
	}

	pTmp->pElement = new(std::nothrow) CHARNODE[iSize];
	// ����ü�� �迭 ����Ʈ�� ����ų �����Ϳ� �����Ҵ��� �ȵ� ���
	if (pTmp->pElement == nullptr)
	{
		std::cout << "�޸� �Ҵ� ����. �迭 ����Ʈ ������ �����Ҵ� �Ұ�." << std::endl;
		delete pTmp;
		pTmp = nullptr;
		return nullptr;
	}
	
	//��� ��� 0���� �ʱ�ȭ
	memset(pTmp->pElement, 0, sizeof(CHARNODE) * iSize);

	return pTmp;
}

// ����ؾ��� ��
// ���ڷ� ������ ����Ʈ�� nullptr����
void  DeleteList(LIST* ArrayList)
{
	if (ArrayList != nullptr)
	{
		if (ArrayList->pElement != nullptr)
		{
			delete [] ArrayList->pElement;
			ArrayList->pElement = nullptr;
		}
		delete ArrayList;
		ArrayList = nullptr;
	}
}

// ����ؾ� �� ��
// ���ڷ� ������ ����Ʈ�� nullptr����
bool  IsFull(const LIST* ArrayList)
{
	if (ArrayList != nullptr)
	{
		if (ArrayList->iNumOfElem >= ArrayList->iSizeOfList)
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
		std::cout << "����Ʈ�� �ٽ� Ȯ�����ּ���" << std::endl;
		return true;
	}
}

// ����ؾ��� ��
// ���ڷ� ���� ����Ʈ�� nullptr����
// �迭�� full����
// ���ڷ� ���� iPosition�� 0�� ����Ʈ�� �ִ� ũ�� ��������.
bool  AddElement(LIST* ArrayList, int iPosition, CHARNODE Node)
{	
	//���� ��Ȳ�� ���� ó��
	// 1. ��������� ���� ����Ʈ �����Ͱ� ������ ��,
	if (ArrayList == nullptr)
	{
		std::cout << "���� �߻�. ����Ʈ�� �����ϴ�." << std::endl;
		return false;
	}
	
	// 2. �迭�� full����
	if (IsFull(ArrayList))
	{
		std::cout << "���� �߻�. ����Ʈ�� ���� á���ϴ�." << std::endl;
		return false;
	}

	// 3. ���ڷ� ���� iPositon�� 0�� ����Ʈ�� �ִ� ũ�� ��������.
	if (0 > iPosition || ArrayList->iSizeOfList <= iPosition)
	{
		std::cout << "���� �߻�. ��ġ�� �߸� �Ǿ����ϴ�." << std::endl;
		return false;
	}

	//�ش� ��ġ�� ���� ���� ���.
	if(ArrayList->pElement[iPosition].szEelm == 0)
	{
		ArrayList->pElement[iPosition].szEelm = Node.szEelm;
	}
	else		//�̹� �ش� ��ġ�� ���� �ִ� ���
	{
		int iStart = ArrayList->iNumOfElem - 1;
		for (int i = iStart; i >= iPosition; --i)
		{
			ArrayList->pElement[i].szEelm = ArrayList->pElement[i - 1].szEelm;
		}

		ArrayList->pElement[iPosition].szEelm = Node.szEelm;
	}
	ArrayList->iNumOfElem++;
	return true;

}

// ����ؾ��� ��
// ���ڷ� ���� ����Ʈ�� nullptr����,
// ���ڷ� ���� iPosition�� 0�� ����Ʈ�� �ִ� ũ�� ��������.
bool RemoveElement(LIST* ArrayList, int iPosition)
{
	//����ó�� 1. ���ڷ� ���� ����Ʈ Ȯ��
	if (ArrayList == nullptr)
	{
		std::cout << "�����߻�. ����Ʈ�� �����ϴ�." << std::endl;
		return false;
	}
	//����ó�� 2. ���ڷ� ���� iPosition�� Ȯ��
	if (0 > iPosition || ArrayList->iSizeOfList <= iPosition)
	{
		std::cout << "���� �߻�. ��ġ�� �߸� �Ǿ����ϴ�." << std::endl;
		return false;
	}
	
	//�����͵��� ��ĭ�� ������.
	for (int i = iPosition; i < ArrayList->iNumOfElem; ++i)
	{
		ArrayList->pElement[i].szEelm = ArrayList->pElement[i + 1].szEelm;
	}
	ArrayList->iNumOfElem--;
	return true;
}

// ����ؾ��� ��
// ���ڷ� ���� ����Ʈ�� nullptr����,
// ���ڷ� ���� iposition�� 0�� ����Ʈ�� �ִ� ũ�� ��������.
CHARNODE* GetElement(LIST* ArrayList, int iPosition)
{
	//����ó�� 1. ���ڷ� ���� ����Ʈ Ȯ��
		if (ArrayList == nullptr)
		{
			std::cout << "�����߻�. ����Ʈ�� �����ϴ�." << std::endl;
			return nullptr;
		}
	//����ó�� 2. ���ڷ� ���� iPosition�� Ȯ��
	if (0 > iPosition || ArrayList->iSizeOfList <= iPosition)
	{
		std::cout << "���� �߻�. ��ġ�� �߸� �Ǿ����ϴ�." << std::endl;
		return nullptr;
	}
	CHARNODE* pTmp;
	pTmp = &(ArrayList->pElement[iPosition]);

	return pTmp;
}

// ����ؾ��� ��
// ���ڷ� ���� ����Ʈ�� nullptr����,
void  DisplayList(LIST* ArrayList)
{
	//����ó�� 1. ���ڷ� ���� ����Ʈ Ȯ��
	if (ArrayList == nullptr)
	{
		std::cout << "�����߻�. ����Ʈ�� �����ϴ�." << std::endl;
		return;
	}

	std::cout << "�ִ� ���� ���� : " << ArrayList->iSizeOfList << std::endl;
	std::cout << "���� ���� ���� : " << ArrayList->iNumOfElem << std::endl;
	for (int i = 0; i < ArrayList->iNumOfElem; ++i)
	{
		std::cout << GetElement(ArrayList, i)->szEelm << " ";
	}
	for (int i = ArrayList->iNumOfElem; i < ArrayList->iSizeOfList; ++i)
	{
		std::cout << "Empty" << " ";
	}
	std::cout << std::endl;
}

// ����ؾ��� ��
// ���ڷ� ���� ����Ʈ�� nullptr����,
void ClearList(LIST* ArrayList)
{
	//����ó�� 1. ���ڷ� ���� ����Ʈ Ȯ��
	if (ArrayList == nullptr)
	{
		std::cout << "�����߻�. ����Ʈ�� �����ϴ�." << std::endl;
		return;
	}

	// ��� �迭 0�ʱ�ȭ
	memset(ArrayList->pElement, 0, sizeof(CHARNODE) * ArrayList->iSizeOfList);
	ArrayList->iNumOfElem = 0;
	
}

