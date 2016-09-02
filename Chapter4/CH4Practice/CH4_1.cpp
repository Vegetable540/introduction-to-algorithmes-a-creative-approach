#include <cassert>

#include "CH4_1.h"

LinkNode::LinkNode(int num)
	: _num(num)
{
}

LinkNode* LinkNode::next()
{
	return _next;
}

void LinkNode::setNext(LinkNode * next)
{
	_next = next;
}

int LinkNode::num()
{
	return _num;
}

LinkList::LinkList()
{
}

LinkList::~LinkList()
{
	if (_head == nullptr)
		return;

	LinkNode *pNext = _head->next();
	while (pNext != nullptr)
	{
		LinkNode *pTemp = pNext->next();
		delete pNext;
		pNext = pTemp;
	}
	delete _head;
}

void LinkList::addNum(int n)
{
	if (_head == nullptr) {
		_head = new LinkNode(n);
	} 
	else {
		LinkNode *newNode = new LinkNode(n);
		newNode->setNext(_head);
		_head = newNode;
	}
}

void LinkList::rmNum(int n)
{
	if (_head == nullptr)
		return;

	LinkNode *pCur = _head;
	LinkNode *pNext = _head;

	if (pCur->num() == n) {
		delete _head;
		_head = nullptr;
		return;
	}

	while (pCur->next() != nullptr) {
		pNext = pCur->next();

		if (pNext->num() == n) {
			pCur->setNext(pNext->next());
			delete pNext;
		}
		else {
			pCur = pNext;
		}
	}
}

bool LinkList::findNum(int n)
{
	if (_head == nullptr)
		return false;

	if (_head->num() == n)
		return _head;

	LinkNode *pNext = _head->next();
	while (pNext != nullptr) {
		if (pNext->num() == n) {
			return true;
		}
		else {
			pNext = pNext->next();
		}
	}

	return false;
}

LinkNode * LinkList::head()
{
	return _head;
}

void LinkList::setHead(LinkNode * node)
{
	_head = node;
}

Test_LinkList::Test_LinkList()
{
	test_EmptLinkListRemove();
	test_EmptLinkListInsert();
	test_LinkListFind();

	test_OneElementLinkListRemove();
	test_100ElementLinkListRemove();
}

void Test_LinkList::test_EmptLinkListRemove()
{
	LinkList oEmptyList;
	oEmptyList.rmNum(0);

	assert(oEmptyList.head() == nullptr);
}

void Test_LinkList::test_EmptLinkListInsert()
{
	LinkList oEmptyLinkList;
	oEmptyLinkList.addNum(1);

	assert(oEmptyLinkList.head() != nullptr);
}

void Test_LinkList::test_LinkListFind()
{
	LinkList oEmptyLinkList;
	assert(!oEmptyLinkList.findNum(0));

	for (int i = 0; i < 100; ++i) {
		assert(!oEmptyLinkList.findNum(i));
		oEmptyLinkList.addNum(i);
		assert(oEmptyLinkList.findNum(i));
	}
}

void Test_LinkList::test_OneElementLinkListRemove()
{
	LinkList oOneElement;
	oOneElement.addNum(1);

	oOneElement.rmNum(0);
	assert(oOneElement.head() != nullptr);

	oOneElement.rmNum(1);
	assert(oOneElement.head() == nullptr);
}

void Test_LinkList::test_100ElementLinkListRemove()
{
	LinkList oEmptyList;
	for (int i = 0; i < 100; ++i) {
		oEmptyList.addNum(i);
	}

	for (int i = 0; i < 100; ++i) {
		oEmptyList.rmNum(i);
		assert(!oEmptyList.findNum(i));
	}
}

