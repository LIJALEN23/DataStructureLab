#include <iostream>
#include <string>
#include <regex>
#include <cstdlib>
#include "arraylist.hpp"
#include "polynomial.hpp"  

using namespace std;

arraylist::ArrayList<lab01::Polynomial> in() {
    arraylist::ArrayList<lab01::Polynomial> polynomials;
    string regex_str = "([+-]?\\d*\\.?\\d*)x(\\^(-?\\d+))?|([+-]?\\d+\\.?\\d*)";
    regex pattern("^" + regex_str + "(?:" + regex_str + ")*$");

    while (true) {
        for (int i = 0; i < 2; ++i) {
            system("cls");
            cout << "输入0退出程序" << endl;
            cout << "请输入符合格式(如 3x^2 - 2x + 1)的多项式" << (i + 1) << "：";
            string input;
            getline(cin, input);

            if (input == "0") {
                return {};
            }

            while (true) {
                string processed_input = regex_replace(input, regex(" "), "");
                if (regex_match(processed_input, pattern)) {
                    break;
                }
                else {
                    cout << "输入不符合要求，请重新输入：";
                    getline(cin, input);

                    if (input == "0") {
                        return {};
                    }
                }
            }

            polynomials.addLast(lab01::Polynomial(input));
        }
        return polynomials;
    }
}

void out(const arraylist::ArrayList<lab01::Polynomial>& polynomials) {
    cout << "\n\n\n===================================================================================" << endl;
    cout << "p1化简后的标准形式： " << polynomials.get(0) << endl;
    cout << "p2化简后的标准形式：" << polynomials.get(1) << endl;
    cout << "===================================================================================" << endl;
    cout << "p1 + p2 = " << (polynomials.get(0) + polynomials.get(1)) << endl;
    cout << "p1 * p2 = " << (polynomials.get(0) * polynomials.get(1)) << endl;
    cout << "===================================================================================\n\n\n\n\n\n" << endl;
}

int main() {
    while (true) {
        arraylist::ArrayList<lab01::Polynomial> polynomials = in();
        if (!polynomials.size() == 0) {
            out(polynomials);
        }
        else {
            cout << "Goodbye!" << endl;
            return 0;
        }
    }
}
