#pragma once
#include <vector>

class BSTNode
{
public:
	BSTNode(int num);
	virtual ~BSTNode();

public:
	void setLeft(BSTNode *left) { _left = left; }
	BSTNode* left() { return _left; }

	void setRight(BSTNode *right) { _right = right; }
	BSTNode* right() { return _right; }

	void setNum(int num) { _Num = num; }
	int num() { return _Num; }

private:
	BSTNode *_left = nullptr;
	BSTNode *_right = nullptr;
	int _Num = 0;
};

class BST
{
public:
	virtual ~BST();

public:
	bool insert(int num);
	std::vector<int> visitBST_NoRecursion();
	std::vector<int> visitBST_Recursion();

	int nodeCount();

private:
	void visitNode(std::vector<int> &result, BSTNode *node);

private:
	BSTNode *_root = nullptr;
	int _nodeCount = 0;
};

class Test_BST
{
public:
	Test_BST();

public:
	void testInsert();
	void testVisitBST_Recursion();
	void testVisitBST_NoRecursion();

private:
	void makeData(BST &oBST, std::vector<int> &orderData);
};