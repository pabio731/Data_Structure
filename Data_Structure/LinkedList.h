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

 ���� ����Ʈ�� ����ִ���, ���� �ε����� ����
 �߸� �Ǿ����� Ȯ���ϴ� �κ��� �ڵ尡 �ߺ� �ȴ�.
 boolŸ�� ��� �Լ��� ���� �����ϴ°� �� ���ƺ���.
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
	bool AddDataFirst(Node* NewNode, const int& iData);		//������ �߰� ������ true, ���н� false
	bool AddDataMiddle (Node* NewNode, const int& iPosition, const int& iData);
	bool AddDataLast(Node* NewNode, const int& iData);
	bool RemoveData(const int& iPosition);
	int GetLenth();
	int GetData(const int& iPosition);
	void DisplayAll();
// ���� ������ ���� �Լ�, ����Ʈ�� ����ִ��� Ȯ�� ���� ����
};
//***************************************
