#pragma once
#include<iostream>
// �瓇�� ��ũ�� ����ũ �����ϱ�.
// �ܹ��� ��ũ�� ����Ʈ �ڵ尡 ���� �߱� ������ ���� ������ �� ����ϰ�.
// Head�� Prev�� ������ ��带 ����ų �����̸�,
// ��尡 ���� ���� Next,Prev�� nullptr.
/*
	�Ű������� ������ ��ġ���� ���� ����Ʈ�� ��� �ִ���
	Ȯ�� �ϴ� �ڵ� ��� �Լ��� ���� ������.
	��� ����� �ִ� �۾� ��� �Լ� �ȿ���.
	���� �� ��
	���� ���� Ž�� ���Ȯ��
	����Ȯ�� �ʱ�ȭ
*/

//********** Node Ŭ���� ************
class Node
{
private:
	friend class List;
	int iData;
	Node* Prev;	//���� ��带 ����Ŵ
	Node* Next;	//���� ��带 ����Ŵ
public:
	Node(int iData);
	int GetData();
};
//**********************************

//���� ���Ϸ� �� �� �ִ� ��..
//ó���̶� �������� ���� �� ���°�.
//************ List Ŭ���� ************
class List
{
private:
	int iLenth;
	Node* Head;
	Node* Tail;
public:	// ������ �޼����� ���� ������ �޼����� ���ֱ�
	List();
	bool IsEmpty();
	bool CheckPosition(int iPosition);
	void InsertHead(int iData);					//�տ��� ����
	void Insert(int iPosition, int iData);		//�߰� ����
	void InsertTail(int iData);					//�� ����
	void DeleteNode(int iPosition);				//��� ����
	int GetData(int iPosition);					//Ž��
	void GetAll();								//��� ���̱�
	int GetLenth();								//���� Ȯ��
	void Clear();								//�ʱ�ȭ
};	// �޸� ���� Ȯ�� �ʼ�
