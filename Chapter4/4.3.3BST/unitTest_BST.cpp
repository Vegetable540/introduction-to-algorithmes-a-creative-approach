#include "stdafx.h"

#include <vector>
#include <set>
#include <random>

#include "BST.h"
#include "unitTest_BST.h"

namespace unitTest_BST {
void test_ALL() {
	test_EmptyT();
	test_OrderT();
	test_RandT();
	test_Search();
	test_Remove();
}

void constructBST(std::vector<int> &oSrcKeys, BST<int> &oBST)
{
	if (oSrcKeys.size() == 0) {
		for (int i = 0; i < 100; ++i) {
			int newKey = std::rand();

			bool bFind = false;
			for (auto key : oSrcKeys) {
				if (key == newKey) {
					bFind = true;
					break;
				}
			}

			if (!bFind) {
				oSrcKeys.push_back(newKey);
			}
		}
	}

	for (int key : oSrcKeys) {
		oBST.insert(key);
	}

	std::sort(oSrcKeys.begin(), oSrcKeys.end(),
		[&](const int &t1, const int &t2)->bool {
		return t1 < t2;
	}
	);
}

void test_EmptyT() {
	BST<int> oBST;
	_ASSERT(oBST.print().size() == 0);
}

void test_OrderT(){
	std::vector<int> oSrcKeys;
	BST<int> oBST;
	for (int i = 0; i < 100; ++i)
	{
		oBST.insert(i);
		oSrcKeys.push_back(i);
	}
	std::vector<int> keys = oBST.print();

	_ASSERT(keys == oSrcKeys);
}

void test_RandT() {
	std::vector<int> oSrcKeys;
	BST<int> oBST;
	constructBST(oSrcKeys, oBST);

	_ASSERT(oBST.length() == oSrcKeys.size());
	_ASSERT(oBST.print() == oSrcKeys);
}

void test_Search()
{
	std::vector<int> oSrcKeys;
	BST<int> oBST;
	constructBST(oSrcKeys, oBST);
	
	int nRandomN = 0;
	bool noInVector = false;
	while (!noInVector)
	{
		nRandomN = std::rand();
		noInVector = true;
		for (int key : oSrcKeys)
		{
			if (key == nRandomN)
			{
				noInVector = false;
				break;
			}
		}
	}

	_ASSERT(oSrcKeys[0] == oBST.search(oSrcKeys[0])->key());
	_ASSERT(oBST.search(nRandomN) == nullptr);
}
void test_Remove()
{
	BST<int> oOneElementBST;
	std::vector<int> oVector{0};

	constructBST(oVector, oOneElementBST);
	oOneElementBST.remove(0);
	_ASSERT(oOneElementBST.length() == 0);

	BST<int> oRemoveNodeNoChild;
	oVector = std::vector<int>{10, 8, 6, 9, 12};
	
	constructBST(oVector, oRemoveNodeNoChild);
	oRemoveNodeNoChild.remove(9);
	oVector.erase(oVector.begin() + 2); // delete 9
	_ASSERT(oRemoveNodeNoChild.print() == oVector);

	BST<int> oRemoveNodeLeftChild;
	oVector = std::vector<int>{ 10, 8, 6, 9, 12, 5 };

	constructBST(oVector, oRemoveNodeLeftChild);
	oRemoveNodeLeftChild.remove(6);
	oVector.erase(oVector.begin() + 1); // delete 6
	_ASSERT(oRemoveNodeLeftChild.print() == oVector);

	BST<int> oRemoveNodeRightChild;
	oVector = std::vector<int>{ 10, 8, 6, 9, 12, 7 };

	constructBST(oVector, oRemoveNodeRightChild);
	oRemoveNodeRightChild.remove(6);
	oVector.erase(oVector.begin()); // delete 6
	_ASSERT(oRemoveNodeRightChild.print() == oVector);

	BST<int> oRemoveNodeTwoChild;
	oVector = std::vector<int>{ 10, 8, 6, 9, 12, 7, 5 };

	constructBST(oVector, oRemoveNodeTwoChild);
	oRemoveNodeTwoChild.remove(6);
	oVector.erase(oVector.begin() + 1); // delete 6
	_ASSERT(oRemoveNodeTwoChild.print() == oVector);

	BST<int> oRemoveNodeTwoChild2;
	oVector = std::vector<int>{ 10, 8, 6, 9, 12, 7, 5 };

	constructBST(oVector, oRemoveNodeTwoChild2);
	oRemoveNodeTwoChild2.remove(8);
	oVector.erase(oVector.begin() + 3); // delete 8
	_ASSERT(oRemoveNodeTwoChild2.print() == oVector);
}
}