#include "CH4_3.h"

#include <random>
#include <stack>
#include <cassert>
#include <algorithm>

BST::~BST()
{
	delete _root;
}

bool BST::insert(int num)
{
	auto returnDefer = [&](bool result)->bool {
		if (result) {
			_nodeCount++;
		}

		return result;
	};

	if (_root == nullptr) {
		_root = new BSTNode(num);
	}
	else {
		BSTNode *parent = _root;
		BSTNode *child = parent;

		while (true)
		{
			if (num > child->num()) {
				parent = child;
				child = child->right();

				if (child == nullptr) {
					parent->setRight(new BSTNode(num));
					return returnDefer(true);
				}
			}
			else if (num < child->num()) {
				parent = child;
				child = child->left();

				if (child == nullptr) {
					parent->setLeft(new BSTNode(num));
					return returnDefer(true);
				}
			}
			else {
				return returnDefer(true);
			}
		}
	}
}

std::vector<int> BST::visitBST_NoRecursion()
{
	if (_root == nullptr) {
		return std::vector<int>();
	}

	std::vector<int> oResult;
	std::stack<BSTNode*> oStack;

	BSTNode *cur = _root;
	while (cur != nullptr || !oStack.empty()) {

		while (cur != nullptr) {
			oStack.push(cur);
			cur = cur->left();
		}

		if (!oStack.empty()) {
			cur = oStack.top();
			oStack.pop();
			oResult.push_back(cur->num());
			cur = cur->right();
		}
	}

	return oResult;
}

std::vector<int> BST::visitBST_Recursion()
{
	if (_root == nullptr) {
		return std::vector<int>();
	}

	std::vector<int> oResult;
	visitNode(oResult, _root);

	return oResult;
}

int BST::nodeCount()
{
	return _nodeCount;
}

void BST::visitNode(std::vector<int>& result, BSTNode * node)
{
	if (node->left() != nullptr) {
		visitNode(result, node->left());
	}

	result.push_back(node->num());

	if (node->right() != nullptr) {
		visitNode(result, node->right());
	}
}

BSTNode::BSTNode(int num)
	: _Num(num)
{
}

BSTNode::~BSTNode()
{
	delete _left;
	delete _right;
}

Test_BST::Test_BST()
{
	testInsert();
	testVisitBST_Recursion();
	testVisitBST_NoRecursion();
}

void Test_BST::testInsert()
{
	BST oBST;
	oBST.insert(50);

	for (int i = 0; i < 100; ++i) 
	{
		oBST.insert(i);
	}

	assert(oBST.nodeCount() == 100);
}

void Test_BST::testVisitBST_Recursion()
{
	BST oBST;
	std::vector<int> oData;

	makeData(oBST, oData);

	std::vector<int> oVisitedResult = oBST.visitBST_Recursion();
	assert(oVisitedResult == oData);
}

void Test_BST::testVisitBST_NoRecursion()
{
	BST oBST;
	std::vector<int> oData;
	makeData(oBST, oData);

	std::vector<int> oVisitedResult = oBST.visitBST_NoRecursion();
	assert(oVisitedResult == oData);
}

void Test_BST::makeData(BST & oBST, std::vector<int>& orderData)
{
	for (int i = 0; i < 100; ++i) {
		bool bIsRepeat = false;
		int nRandom = rand();
		for (auto num : orderData) {
			if (num == nRandom) {
				bIsRepeat = true;
			}
		}

		if (!bIsRepeat) {
			orderData.push_back(nRandom);
		}
	}

	for (auto num : orderData) {
		oBST.insert(num);
	}

	std::sort(orderData.begin(), orderData.end(), [](int n1, int n2) {
		return n1 < n2;
	});
}
