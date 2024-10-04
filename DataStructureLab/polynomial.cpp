#include "polynomial.hpp"
#include <string>
#include <regex>
#include <map>
#include <ostream>

namespace lab01
{
	using std::string;

	Polynomial::Polynomial()
	{
		formula_ = LinkedList<Term>();
	}

	//Polynomial::Polynomial(string formulaStr)
	//{
	//	formula_ = LinkedList<Term>();

	//	// 预处理阶段
	//	formulaStr.erase(std::remove_if(formulaStr.begin(), formulaStr.end(), ::isspace), formulaStr.end());
	//	std::regex replaceXRegex("(?!<x)(?<=[^0-9])x");
	//	formulaStr = std::regex_replace(formulaStr, replaceXRegex, "1x");

	//	// 定义正则表达式来匹配多项式的每一项
	//	std::regex pattern(R"(([+-]?\d*\.?\d*)x(\^(-?\d+))?)|([+-]?\d+\.?\d*)");
	//	std::smatch match;
	//	std::map<int, double> termMap;

	//	// 使用正则表达式匹配每一项
	//	while (std::regex_search(formulaStr, match, pattern)) {
	//		double coefficient = 0.0;
	//		int exponent = 0;

	//		if (!match[1].str().empty()) { // 表示匹配了形如 7x^-2 这种项
	//			coefficient = match[1].str().empty() || match[1].str() == "+" ? 1.0 : (match[1].str() == "-" ? -1.0 : std::stod(match[1].str()));
	//			exponent = match[3].str().empty() ? 1 : std::stoi(match[3].str());
	//		}
	//		else if (!match[4].str().empty()) { // 匹配了常数项
	//			coefficient = std::stod(match[4].str());
	//			exponent = 0;
	//		}

	//		// 合并同类项
	//		termMap[exponent] += coefficient;
	//		formulaStr = match.suffix().str();
	//	}

	//	// 添加合并后的项到多项式中
	//	for (const auto& entry : termMap) {
	//		addLast({ entry.second, entry.first });
	//	}

	//	// 排序
	//	std::sort(formula.begin(), formula.end(), [](const FormulaNode& a, const FormulaNode& b) {
	//		return a.exponent > b.exponent;
	//		});
	//}

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