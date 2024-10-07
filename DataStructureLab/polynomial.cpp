#include "polynomial.hpp"
#include "hashmap.hpp"
#include "sort.hpp"
#include <string>
#include <regex>
#include <iostream>


namespace lab01
{
	using std::string;
	using hashmap::HashMap;
	using hashmap::Pair;

	Polynomial::Polynomial()
	{
		formula_ = LinkedList<Term>();
	}

	Polynomial::Polynomial(const string& formula_str)
	{
		u32 term_size = 0;
		Term* terms = parseStr(formula_str, term_size);
		sort::bubbleSort(terms, term_size);
		for (u32 i = term_size; i > 0; i--)
		{
			formula_.addLast(terms[i - 1]);
		}
		delete[] terms;
	}

	Polynomial Polynomial::operator+(const Polynomial& other) const
	{
		LinkedList<Term>* result_polynomial = new LinkedList<Term>();

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
				result_polynomial->addLast(Term(term1 + term2));
				current_first = current_first->next_;
				current_second = current_second->next_;
			}
			else if (term1 > term2)
			{
				result_polynomial->addLast(term1);
				current_first = current_first->next_;
			}
			else
			{
				result_polynomial->addLast(term2);
				current_second = current_second->next_;
			}
		}

		while (current_first != nullptr)
		{
			result_polynomial->addLast(Term(current_first->data_));
			current_first = current_first->next_;
		}

		while (current_second != nullptr)
		{
			result_polynomial->addLast(Term(current_second->data_));
			current_second = current_second->next_;
		}

		return Polynomial(*result_polynomial);
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

	Term* Polynomial::parseStr(const string& formula_str, u32& term_size)
	{
		HashMap<u32, double> term_map;

		// 预处理阶段
		string formula = formula_str;
		// 1去除多余的空格
		formula.erase(remove(formula.begin(), formula.end(), ' '), formula.end());
		// 2替换不带系数的 x 为 1x
		string updated_formula;
		for (size_t i = 0; i < formula.size(); ++i) {
			if (formula[i] == 'x') {
				if (i == 0 || formula[i - 1] == '+' || formula[i - 1] == '-' || formula[i - 1] == '(') {
					updated_formula += "1"; // 在 x 前添加 1
				}
				updated_formula += 'x'; // 添加 x
			}
			else {
				updated_formula += formula[i]; // 其他字符直接添加
			}
		}
		formula = updated_formula;

		// 定义正则表达式来匹配多项式的每一项
		std::regex term_pattern("([+-]?\\d*\\.?\\d*)x(\\^(-?\\d+))?|([+-]?\\d+\\.?\\d*)");
		std::smatch match;

		auto it = std::sregex_iterator(formula.begin(), formula.end(), term_pattern);
		auto end = std::sregex_iterator();

		while (it != end) {
			double coefficient = 0.0;
			int exponent = 0;

			if ((*it)[1].matched) { // 匹配形如 7x^-2 的项
				coefficient = (*it)[1].str().empty() || (*it)[1].str() == "+" ? 1.0 :
					((*it)[1].str() == "-" ? -1.0 : std::stod((*it)[1].str()));
				exponent = (*it)[3].matched ? std::stoi((*it)[3].str()) : 1;
			}
			else if ((*it)[4].matched) { // 匹配常数项
				coefficient = std::stod((*it)[4].str());
				exponent = 0;
			}

			//合并同类项
			if (!term_map.containsKey(exponent) && coefficient != 0)
			{
				term_map.put(exponent, coefficient);
			}
			else
			{
				double& term_coefficient = term_map.get(exponent);
				term_coefficient += coefficient;
			}

			++it;
		}

		term_size = term_map.size();
		Pair<u32, double>* term_map_arr = term_map.toArray();
		Term* terms = new Term[term_size];
		for (u32 i = 0; i < term_size; i++)
		{
			terms[i].coefficient_ = term_map_arr[i].val_;
			terms[i].exponent_ = term_map_arr[i].key_;
		}

		return terms;
	}
}