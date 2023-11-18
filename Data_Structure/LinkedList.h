#pragma once
#include <iostream>
//List With Pointer -> Linked list
// Ŭ������ ��ũ�帮��Ʈ ������
// �ܹ��� �ܼ� ���� ��ũ�帮��Ʈ.

//�ʿ��ϴ� �����Ǵ� �κе� �����ϱ�
/* ���� private�� �����ϰ�, ��嵵 Ŭ������.
 ������ ������ ��ũ�� ����Ʈ�� ũ��, Head��嵵 private��
 �����͸� �����ϴ� ��� Ŭ������ �����
 ������ ��ü�� ���� ���� ������ ����
 �ش� ��� Ÿ�� ������.

 public���� ��ũ�� ����Ʈ�� ��ɵ�
 ��� �߰�, ũ�� ���� �Լ�. ������ ���,
 ������ �� ����, ��� ����, ����� ��尡 ������ Ȯ��.
*/

//********** Node Ŭ������ ���� **********
class Node
{
private:
	int iData;
public:
	Node(const int& iData);
	Node* NextNode;
	int GetData();
};
//****************************************

//********** List Ŭ������ ���� **********
class List
{
private:
	
	int iLenth;
	Node* Head;
	Node* Tail;
	Node* Cur;

public:
	List();
	~List();
	//bool AddDataFirst(Node NewNode, int iData);		//������ �߰� ������ true, ���н� false
	bool AddData(Node* NewNode, int iPosition);
	bool AddDataLast(Node* NewNode, int iData);
	bool RemoveData(int iPosition);
	int GetLenth();
	int GetData(int iPosition);
	void DisplayAll();
// ���� ������ ���� �Լ�, ����Ʈ�� ����ִ��� Ȯ�� ���� ����
};
//***************************************


//********** ����Ʈ�� ��� ��ü�� ����� ���� ��� �Լ�
class Create
{
public:
	static List* CreateList();
	static Node* CreateNode(int iData);
};
//*********************************************