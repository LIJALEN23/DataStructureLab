#pragma once
#include "test_arraylist.hpp"

namespace test_arraylist
{
	void testConstructor()
	{
		std::cout << "\n\nTEST[testConstructor()]:\n\n";

		arraylist::ArrayList<u32> list1;
		for (u32 i = 5; i >= 1; i--)
		{
			list1.addFirst(i);
		}
		std::cout << list1 << std::endl;
	}

	void testCopyConstructor()
	{

		arraylist::ArrayList<u32> list1;
		for (u32 i = 5; i >= 1; i--)
		{
			list1.addFirst(i);
		}
		std::cout << "list1 : " << list1 << std::endl;

		arraylist::ArrayList<u32> list2 = list1;
		std::cout << "list2 : " << list2 << std::endl;
	}

	void testBasic()
	{
		using namespace arraylist;
		std::cout << "\n\nTEST[testBasic()]:\n\n";

		ArrayList<u32> list1(100);
		for (u32 i = 100; i >= 1; i--)
		{
			list1.addFirst(i);
		}
		std::cout << "list1(1 - 100) : " << list1 << std::endl;

		for (u32 i = 101; i <= 200; i++)
		{
			list1.addLast(i);
		}
		std::cout << std::endl << "list(1 - 200) : " << list1 << std::endl;

	

		std::cout << "The index of 150 : " << list1[150] << std::endl;
	}
}

