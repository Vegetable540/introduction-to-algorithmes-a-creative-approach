#pragma once

class LinkNode
{
public:
	LinkNode(int num);

public:
	LinkNode* next();
	void setNext(LinkNode* next);
	
	int num();

private:
	int _num = 0;
	LinkNode *_next = nullptr;
};

class LinkList
{
public:
	LinkList();
	virtual ~LinkList();

public:
	void addNum(int n);
	void rmNum(int n);

	bool findNum(int n);

	LinkNode* head();
	void setHead(LinkNode *node);

private:
	LinkNode *_head = nullptr;
};

class Test_LinkList
{
public:
	Test_LinkList();
	
public:
	void test_EmptLinkListRemove();
	void test_EmptLinkListInsert();

	void test_LinkListFind();

	void test_OneElementLinkListRemove();
	void test_100ElementLinkListRemove();
};