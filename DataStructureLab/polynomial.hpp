#pragma once
#include "linkedlist.hpp"
#include "term.hpp"
#include <ostream>
#include <string>

namespace lab01
{
	using std::string;
	using linkedlist::LinkedList;
	using linkedlist::Node;

	class Polynomial
	{
	public:
		Polynomial();
		Polynomial(Term* terms, u32 terms_size);
		Polynomial(LinkedList<Term> a_formula) { formula_ = a_formula; }
		Polynomial(const string& formula_str);

		~Polynomial()
		{ 
			if (!formula_.isEmpty())
			{
				clear();
			}
		}

		Polynomial operator+(const Polynomial& other) const;
		Polynomial operator*(const Polynomial& other) const;
		friend std::ostream& operator<<(std::ostream& os, const Polynomial& polynomial);
		bool is_empty() { return formula_.isEmpty(); }
		void clear();

	private:
		LinkedList<Term> formula_;
	};
}