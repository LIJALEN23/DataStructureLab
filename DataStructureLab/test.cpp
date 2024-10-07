#include "linkedlist.hpp"
#include "term.hpp"
#include "polynomial.hpp"
#include "myint.hpp"
#include "arraylist.hpp"
#include "pair.hpp"
#include "hashmap.hpp"
#include "sort.hpp"
#include <iostream>
#include <string>

namespace test
{

	void testLinkedList() {
		using linkedlist::LinkedList;
		using std::cout;
		using std::endl;

		LinkedList<u32> list1;
		for (u32 i = 1; i <= 5; i++)
		{
			list1.addLast(i);
		}

		for (u32 i = 10; i >= 6; i--)
		{
			list1.addFirst(i);
		}


		cout << "Size : " << list1.getSize() << endl;

		int remove = list1.removeFirst();
		cout << remove << " has been removed" << endl;
		remove = list1.removeLast();
		cout << remove << " has been removed" << endl;
		remove = list1.removeFirst();
		cout << remove << " has been removed" << endl;
		remove = list1.removeLast();
		cout << remove << " has been removed" << endl;
		remove = list1.removeFirst();
		cout << remove << " has been removed" << endl;
		remove = list1.removeLast();
		cout << remove << " has been removed" << endl;

		cout << "Now the size should be 4, the actual size is " << list1.getSize() << endl;

		list1.clear();

	}

	void testArrayList() 
	{
		arraylist::ArrayList<u32> arr1;
		arr1.addFirst(3);
		arr1.addFirst(2);
		arr1.addFirst(1);
		arr1.addLast(4);
		//arr1.printArr();

		std::cout << "arr[1] = " << arr1.get(1) << std::endl;

		u32 num1 = arr1.removeFirst();
		u32 num2 = arr1.removeLast();
		u32& num3 = arr1.get(1);
		num3 = 12;
		const u32& num4 = arr1.get(1);
		std::cout << "1 , Actual val :" << num1 << std::endl;
		std::cout << "4 , Actual val : " << num2 << std::endl;

		arraylist::ArrayList<u32> arr2;
		for (u32 i = 0; i < 100; i++)
		{
			arr2.addLast(i);
		}
		//arr2.printArr();
	}

	void testHashMap()
	{
		using std::cout;
		using std::endl;

		hashmap::HashMap<u32, u32> map1;

		for (u32 i = 0; i < 1000; i++)
		{
			map1.put(i, i);
		}
		cout << "size : " << map1.size() << endl;
		for (u32 i = 0; i < 1000; i++)
		{
			if (!map1.containsKey(i))
			{
				cout << "ERROR : map1.containsKey(i)!" << endl;
			}

			if (!map1.containsVal(i))
			{
				cout << "ERROR : map1.containsVal(i)" << endl;
			}
		}

		u32 num1 = map1.remove(5);
		cout << "num1 should be 5. " << " The actual is " << num1 << endl;


		hashmap::HashMap<u32, u32> map2;

		for (u32 j = 0; j < 10; j++)
		{
			map2.put(j, j + 1);
		}


		u32 num3 = map2.get(8);
		cout << "The value of key 8 is " << num3 << endl;
		
		hashmap::Pair<u32, u32>* arr = map2.toArray();
		for (u32 i = 0; i < 10; i++)
		{
			cout << arr[i] << endl;
		}
		delete[] arr;
	}

	void testTerm()
	{
		using lab01::Term;
		using std::cout;
		using std::endl;

		Term term1 = Term(2.0, 2);
		Term term2 = Term(3.0, 3);
		Term term3 = Term(4.0, 4);

		Term term4 = term1 + term2;
		Term term5 = term2 + term3;
		Term term6 = term1 * term2;
		Term term7 = term2 * term3;

		cout << term1 << endl;
		cout << term2 << endl;
		cout << term3 << endl;
		cout << term4 << endl;
		cout << term5 << endl;
		cout << term6 << endl;
		cout << term7<< endl;
	}

	void testSort()
	{
		using std::cout;
		using std::endl;
		using sort::bubbleSort;
		using sort::swap;

		u32 arr[] = { 1, 2, 3, 4, 56, 5, 7, 8, 9 };
		bubbleSort(arr, 9);
		for (u32 i = 0; i < 9; i++)
		{
			cout << arr[i] << endl;
		}
	}

	void testPolynomial()
	{
		using std::cout;
		using std::endl;
		using std::string;
		using lab01::Polynomial;

		string p_input_str1 = "7x^-2 + 8x^2 + 9x^-2 - 8x^3 - 10x^-3 + 4 - 6";
		string p_input_str2 = "-8x^-2 - 7x^-5 + 8x^-9 + 12x^-2 + 12 - 10";

		Polynomial p1(p_input_str1);
		Polynomial p2(p_input_str2);

		Polynomial p3 = p1 + p2;
	}
}
