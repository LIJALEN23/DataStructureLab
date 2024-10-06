#include "linkedlist.hpp"
#include "term.hpp"
#include "polynomial.hpp"
#include "myint.hpp"
#include "arraylist.hpp"
#include "pair.hpp"
#include "hashmap.hpp"
#include <iostream>

namespace test
{

	//void testLinkedList() {
	//	using linkedlist::LinkedList;
	//	using std::cout;
	//	using std::endl;

	//	LinkedList<int> list1;
	//	for (u32 i = 1; i <= 5; i++)
	//	{
	//		list1.addLast(i);
	//	}

	//	for (u32 i = 10; i >= 6; i--)
	//	{
	//		list1.addFirst(i);
	//	}


	//	cout << "Size : " << list1.getSize() << endl;

	//	int remove = list1.removeFirst();
	//	cout << remove << " has been removed" << endl;
	//	remove = list1.removeLast();
	//	cout << remove << " has been removed" << endl;
	//	remove = list1.removeFirst();
	//	cout << remove << " has been removed" << endl;
	//	remove = list1.removeLast();
	//	cout << remove << " has been removed" << endl;
	//	remove = list1.removeFirst();
	//	cout << remove << " has been removed" << endl;
	//	remove = list1.removeLast();
	//	cout << remove << " has been removed" << endl;

	//	cout << "Now the size should be 4, the actual size is " << list1.getSize() << endl;

	//	list1.clear();

	//}

	//void testArrayList() 
	//{
	//	arraylist::ArrayList<u32> arr1;
	//	arr1.addFirst(3);
	//	arr1.addFirst(2);
	//	arr1.addFirst(1);
	//	arr1.addLast(4);
	//	//arr1.printArr();

	//	std::cout << "arr[1] = " << arr1.get(1) << std::endl;

	//	u32 num1 = arr1.removeFirst();
	//	u32 num2 = arr1.removeLast();
	//	u32& num3 = arr1.get(1);
	//	num3 = 12;
	//	const u32& num4 = arr1.get(1);
	//	std::cout << "1 , Actual val :" << num1 << std::endl;
	//	std::cout << "4 , Actual val : " << num2 << std::endl;

	//	arraylist::ArrayList<u32> arr2;
	//	for (u32 i = 0; i < 100; i++)
	//	{
	//		arr2.addLast(i);
	//	}
	//	//arr2.printArr();
	//}

	void testHashMap()
	{
		hashmap::HashMap<u32, u32> map1;
		//for (u32 i = 0; i < 10; i++)
		//{
		//	map1.put(i, i);
		//}
		map1.put(0, 0);
		map1.put(1, 1);
		map1.put(2, 2);
		map1.put(3, 3);
		map1.put(4, 4);
		map1.put(5, 5);
		map1.put(6, 6);
		map1.put(7, 7);
		map1.put(8, 8);
	}

	//void testTerm()
	//{
	//	using lab01::Term;
	//	using std::cout;
	//	using std::endl;

	//	Term term1 = Term(2.0, 2);
	//	Term term2 = Term(3.0, 3);
	//	Term term3 = Term(4.0, 4);

	//	Term term4 = term1 + term2;
	//	Term term5 = term2 + term3;
	//	Term term6 = term1 * term2;
	//	Term term7 = term2 * term3;

	//	cout << term1 << endl;
	//	cout << term2 << endl;
	//	cout << term3 << endl;
	//	cout << term4 << endl;
	//	cout << term5 << endl;
	//	cout << term6 << endl;
	//	cout << term7<< endl;
	//}

	//void testPolynomial()
	//{
	//	using std::cout;
	//	using std::endl;
	//	using lab01::Polynomial;


	//}
}
