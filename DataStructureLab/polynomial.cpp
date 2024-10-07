#include "polynomial.hpp"
#include "hashmap.hpp"
#include "sort.hpp"
#include <string>
#include <regex>
#include <iostream>
#include <sstream>

namespace lab01
{
	using std::string;
	using hashmap::HashMap;
	using hashmap::Pair;

	Polynomial::Polynomial()
	{
		formula_ = LinkedList<Term>();
	}

	Polynomial::Polynomial(Term* terms, u32 terms_size)
	{
		sort::bubbleSort(terms, terms_size);
		formula_ = LinkedList<Term>();
		for (u32 i = terms_size; i >= 0; i--)
		{
			formula_.addLast(terms[i]);
		}
	}

	Polynomial::Polynomial(const string& formula_str)
	{
		std::regex termRegex(R"(([-+]?\d*)x\^?(\d*)|([-+]?\d+)"); // 匹配多项式中的项
		std::smatch match;
		hashmap::HashMap<u32, double> term_map;

		std::string::const_iterator searchStart(formula_str.cbegin());
		while (std::regex_search(searchStart, formula_str.cend(), match, termRegex)) {
			Term term;

			// 处理 x^n 的形式
			if (!match[1].str().empty()) {
				term.coefficient_ = match[1].str() == "+" || match[1].str() == "" ? 1 : -1; // 处理符号
				if (!match[2].str().empty()) {
					term.exponent_ = std::stoi(match[2].str());
				}
				else {
					term.exponent_ = 1; // x 的情况
				}
			}
			// 处理常数项
			else if (!match[3].str().empty()) {
				term.coefficient_ = std::stoi(match[3].str());
				term.exponent_ = 0; // 常数项
			}

			//合并同类项
			if (!term_map.containsKey(term.exponent_) && term.coefficient_ != 0)
			{
				term_map.put(term.exponent_, term.coefficient_);
			}
			else
			{
				double& term_coefficient = term_map.get(term.exponent_);
				term_coefficient += term.coefficient_;
			}

			searchStart = match.suffix().first; // 移动搜索位置
		}

		u32 term_size = term_map.size();
		Pair<u32, double>* term_map_arr = term_map.toArray();
		Term* terms = new Term[term_size];
		for (u32 i = 0; i < term_size; i++)
		{
			terms[i].coefficient_ = term_map_arr[i].val_;
			terms[i].exponent_ = term_map_arr[i].key_;
		}
		sort::bubbleSort(terms, term_size);
		delete[] term_map_arr;

		Polynomial(terms, term_size);
		delete[] terms;
	}

	Polynomial Polynomial::operator+(const Polynomial& other) const
	{
		LinkedList<Term> result_polynomial = LinkedList<Term>();

		u32 i = 0;
		u32 j = 0;
		Node<Term>* current_first = formula_.getHead();
		Node<Term>* current_second = other.formula_.getHead();

		while (current_first != nullptr && current_second != nullptr)
		{
			Term term1 = current_first->data_;
			Term term2 = current_second->data_;

			if (term1 == term2)
			{
				result_polynomial.addLast(Term(term1 + term2));
				current_first = current_first->next_;
				current_second = current_second->next_;
			}
			else if (term1 > term2)
			{
				result_polynomial.addLast(term1);
				current_first = current_first->next_;
			}
			else
			{
				result_polynomial.addLast(term2);
				current_second = current_second->next_;
			}
		}

		while (current_first != nullptr)
		{
			result_polynomial.addLast(Term(current_first->data_));
			current_first = current_first->next_;
		}

		while (current_second != nullptr)
		{
			result_polynomial.addLast(Term(current_second->data_));
			current_second = current_second->next_;
		}

		return Polynomial(result_polynomial);
	}

	Polynomial Polynomial::operator*(const Polynomial& other) const
	{
		Polynomial result_polynomial;

		for (auto other_current = other.formula_.getHead(); other_current != nullptr; other_current = other_current->next_) {
			Polynomial temp_polynomial;

			for (auto current = formula_.getHead(); current != nullptr; current = current->next_) {
				Term product = other_current->data_ * current->data_;
				temp_polynomial.formula_.addLast(product);
			}

			result_polynomial = result_polynomial + temp_polynomial;
		}

		return result_polynomial;
	}

	//std::ostream& operator<<(std::ostream& os, const Polynomial& polynomial)
	//{

	//}

	void Polynomial::clear()
	{
		formula_.clear();
	}
}