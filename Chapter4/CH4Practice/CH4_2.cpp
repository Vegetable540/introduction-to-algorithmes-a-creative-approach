#include "CH4_2.h"
#include <cassert>

void LinkListReverse::reverse(LinkList * in)
{
	if (in == nullptr || in->head() == nullptr)
		return;

	if (in->head()->next() == nullptr)
		return;

	LinkNode *pCur = in->head();
	LinkNode *pNext = pCur->next();

	while (pNext != nullptr) {
		LinkNode *pTemp = pNext;
		pNext = pNext->next();

		pTemp->setNext(pCur);
		pCur = pTemp;
	}

	in->head()->setNext(nullptr);
	in->setHead(pCur);
}

Test_LinkListReverse::Test_LinkListReverse()
{
	test_EmptyListReverse();
	test_OneElementListReverse();
	test_TwoElementListReverse();
	test_100ElementListReverse();
}

void Test_LinkListReverse::test_EmptyListReverse()
{
	LinkList oEmptyList;
	LinkListReverse::reverse(&oEmptyList);

	assert(oEmptyList.head() == nullptr);
}

void Test_LinkListReverse::test_OneElementListReverse()
{
	LinkList oList;
	oList.addNum(1);

	LinkNode *head = oList.head();

	LinkListReverse::reverse(&oList);
	assert(oList.head() == head);
}

void Test_LinkListReverse::test_TwoElementListReverse()
{
	LinkList oList;
	oList.addNum(1);
	oList.addNum(2);

	LinkListReverse::reverse(&oList);

	LinkNode *head = oList.head();
	assert(oList.head()->num() == 1);
	assert(oList.head()->next()->num() == 2);
}

void Test_LinkListReverse::test_100ElementListReverse()
{
	LinkList oList;
	for (int i = 0; i < 100; ++i) {
		oList.addNum(i);
	}

	LinkListReverse::reverse(&oList);

	LinkNode *pNode = oList.head();
	for (int i = 0; i < 100; ++i) {
		assert(pNode->num() == i);
		pNode = pNode->next();
	}
}
