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

		string p_input_str1 = "7.0x^-2 + 8x^2 + 9x^-2 - 8x^3 - 10x^-3 + 4 - 6";
		string p_input_str2 = "-8x^-2 - 7x^-5 + 8x^-9 + 12x^-2 + 12 - 10";
		string p_input_str3 = "10 + x^-1 + 11 + 9x^2 - x^-1 + 10x^-1";
		string p_out_str1 = "-8.0x^3 + 8.0x^2 + 20.0x^-2 - 10.0x^-3 - 7.0x^-5 + 8.0x^-9";
		string p_out_str2 = "-16.0x^3 + 16.0x^2 - 32.0x + 28.0 + 80.0x^-2 - 76.0x^-3 + 64.0x^-4 - 26.0x^-5 - 64.0x^-6 - 48.0x^-7 + 70.0x^-8 - 16.0x^-9 + 128.0x^-11 - 80.0x^-12";
		string p_out_str3 = "9.0x^2 + 23.0 + 10.0x^-1 + 4.0x^-2 - 7.0x^-5 + 8.0x^-9";
		string p_out_str4 = "18.0x^2 + 78.0 + 20.0x^-1 + 84.0x^-2 - 23.0x^-3 - 147.0x^-5 -70.0x^-6 + 72.0x^-7 + 168.0x^-9 + 80.0x^-10";

		Polynomial p1_input(p_input_str1);
		Polynomial p2_input(p_input_str2);
		Polynomial p3_input(p_input_str3);

		//Polynomial p1_output = p1_input + p2_input;
		//Polynomial p2_output = p1_input * p2_input;

		//Polynomial p3_output = p2_input + p3_input;
		//Polynomial p4_output = p2_input * p3_input;

		cout << "p1 expected : -8.0x^3 + 8.0x^2 - 2.0 + 16.0x^-2 - 10.0x^-3" << endl;
		cout << "p1 actual   : " << p1_input << endl << endl << endl;

		cout << "p2 expected : 2 + 4.0x^-2 - 7.0x^-5 + 8.0x^-9" << endl;
		cout << "p2 actual   : " << p2_input << endl << endl << endl;

		cout << "p3 expected : 9.0x^2 + 21.0 + 10.0x^-1" << endl;
		cout << "p3 actual   : " << p3_input << endl << endl << endl;

		//cout << "output1 expected : -8.0x^3 + 8.0x^2 + 20.0x^-2 - 10.0x^-3 - 7.0x^-5 + 8.0x^-9" << endl;
		//cout << "output1 actual   : " << p1_output << endl << endl << endl;

		//cout << "output2 expected : -16.0x^3 + 16.0x^2 - 32.0x + 28.0 + 80.0x^-2 - 76.0x^-3 + 64.0x^-4 - 26.0x^-5 - 64.0x^-6 - 48.0x^-7 + 70.0x^-8 - 16.0x^-9 + 128.0x^-11 - 80.0x^-12" << endl;
		//cout << "output2 actual   : " << p2_output << endl << endl << endl;

		//cout << "output3 expected : 9.0x^2 + 23.0 + 10.0x^-1 + 4.0x^-2 - 7.0x^-5 + 8.0x^-9" << endl;
		//cout << "output3 actual   : " << p3_output << endl << endl << endl;

		//cout << "output4 expected : 18.0x^2 + 78.0 + 20.0x^-1 + 84.0x^-2 - 23.0x^-3 - 147.0x^-5 -70.0x^-6 + 72.0x^-7 + 168.0x^-9 + 80.0x^-10" << endl;
		//cout << "output4 actual   : " << p4_output << endl << endl << endl;
	}
}
