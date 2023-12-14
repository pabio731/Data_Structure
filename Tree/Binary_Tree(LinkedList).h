#pragma once
#include<iostream>
using namespace std;
typedef struct  TreeNode
{
	int iData;

	TreeNode* tLeftChild;
	TreeNode* trightChild;

	TreeNode()
		: iData(0)
		, tLeftChild(nullptr)
		, trightChild(nullptr) {}
}NODE;

class CBinaryTreeLinkedList
{
private:
	NODE* tRootNode;
public:

	CBinaryTreeLinkedList();
	~CBinaryTreeLinkedList();

	void InitTree(int _iData);

	void InsertLeft(NODE* _pParantNode, int _iData);
	void InsertRight(NODE* _pParantNode, int _iData);
	void RemoveLeft(NODE* _pParantNode);
	void RemoveRight(NODE* _pParantNode);

	NODE* GetLeftChild(NODE* _pParantNode);
	NODE* GetRightChild(NODE* _pParantNode);
	NODE* GetRootNode() { return tRootNode; }

	int GetData(NODE* _pNode);
	void SetData(NODE* _pNode, int _iData);

	void Preorder(NODE* _pNode);
	void Inorder(NODE* _pNode);
	void Postorder(NODE* _pNode);

	void Clear(NODE* _pNode);
};