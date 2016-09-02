#pragma once
#include "CH4_1.h"

class LinkListReverse
{
public:
	static void reverse(LinkList *in);
};

class Test_LinkListReverse
{
public:
	Test_LinkListReverse();

public:
	void test_EmptyListReverse();
	void test_OneElementListReverse();

	void test_TwoElementListReverse();
	void test_100ElementListReverse();
};
