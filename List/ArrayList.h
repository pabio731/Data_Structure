#pragma once


//�� ����ü �ϳ��� ��尡 �� ����. 
// ���Ҹ� ���� ����ü�� �����ϴ� ������ �迭 ����Ʈ�� ���뼺�� ���ؼ�. + �߻� �ڷ����� ���Ǹ� ������ ����
typedef struct Node
{
	char szEelm;
}CHARNODE;

typedef struct ArrayList
{
	CHARNODE* pElement;
	int iSizeOfList;
	int iNumOfElem;
	
}LIST;


LIST* CreateList(int iSize);			//�迭 ����Ʈ�� �������ִ� �Լ�. ����Ʈ�� ������ Ÿ���� char��
void  DeleteList(LIST* ArrayList);		//�迭 ����Ʈ�� ���� �ϴ� �Լ�. 
bool  IsFull(const LIST* ArrayList);	//�迭 ����Ʈ�� ������ �߰� ���ɼ� ���θ� Ȯ���ϴ� �Լ�
bool  AddElement(LIST* ArrayList, int iPosition, CHARNODE Node); // ���Ҹ� �߰��ϴ� �Լ�. �����ϸ� true �����ϸ� false ��ȯ,
bool  RemoveElement(LIST* ArrayList, int iPosition);  //���Ҹ� �����ϴ� �Լ�. �����ϸ� true, �����ϸ� false ��ȯ.
CHARNODE* GetElement(LIST* ArrayList, int iPosition); // iPosition ��ġ�� ��� �����͸� ��ȯ�ϴ� �Լ�.
void  DisplayList(LIST* ArrayList); //����Ʈ�� ��� ��� �����͸� �����ִ� �Լ�.
void ClearList(LIST* ArrayList); // ����Ʈ�� �ʱ�ȭ �ϴ� �Լ�.
//int GetListLenth(LIST* ArrayList); //����Ʈ�� ���̸� ��ȯ�ϴ� �Լ�




