#include "linkedlist.hpp"
#include "term.hpp"
#include "polynomial.hpp"
#include "myint.hpp"
#include <iostream>

namespace test
{

	void testLinkedList() {
		using linkedlist::LinkedList;
		using std::cout;
		using std::endl;

		LinkedList<int> list1;
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

	void testPolynomial()
	{
		using std::cout;
		using std::endl;
		using lab01::Polynomial;


	}
}
