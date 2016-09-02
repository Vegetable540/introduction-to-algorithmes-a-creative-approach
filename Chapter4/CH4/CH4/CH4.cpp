// CH4.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Heap.h"
#include "unitTest_BST.h"

void deleteArray(int array[])
{
	delete []array;
}

int _tmain(int argc, _TCHAR* argv[])
{
	unitTest_BST::test_ALL();

	return 0;
}

