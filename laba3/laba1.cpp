// laba1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <bitset>
#include <stack>
#include <algorithm>
#include <iterator>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include "laba2_3_4.h"
 
int isoperator(char c) {
    switch (c) {
    case '!': case '&': case '|': return 1;
    }
    return 0;
}

int isbinaryoperator(char c) {
    return c != '!' && isoperator(c);
}

int isinvalidchar(char c) {
    if (c == '(' || c == ')') return 0;
    else if (isupper(c) || isoperator(c)) return 0;
    return 1;
}

int isupperalpha(char c) { return isupper(c); }

 

int priority(char opr) {
    switch (opr) {
    case '!': return 3;
    case '&': return 2;
    case '|': return 1;
    default:  return 0;
    }
}

 

std::set<char> get_expinfo(const std::string& exp_2, const std::string&exp_1) {
    std::set<char> exp_elem;
    
    for (std::string::size_type i = 0; i != exp_1.size(); ++i) {
        if (isupper(exp_1[i])) {
            exp_elem.insert(exp_1[i]);
        }
    }
    for (std::string::size_type i = 0; i != exp_2.size(); ++i) {
        if (isupper(exp_2[i])) {
            exp_elem.insert(exp_2[i]);
        }
    }
    return exp_elem;
}

std::string infix_to_suffix(const std::string& exp) {
    char top;
    std::stack<char> s;
    std::string suffix;
    for (std::string::size_type i = 0; i != exp.size(); ++i) {
        if (isupper(exp[i])||exp[i]=='0'||exp[i]=='1') suffix += exp[i];
        else if (exp[i] == '(') s.push(exp[i]);
        else if (isoperator(exp[i])) {
            while (1) {
                if (s.empty() || s.top() == '(') {
                    s.push(exp[i]); break;
                }
                else {
                    top = s.top();
                    if (priority(exp[i]) > priority(top) || (exp[i] == '!' && top == '!')) {
                        s.push(exp[i]); break;
                    }
                    else {
                        suffix += s.top(); s.pop();
                    }
                }
            }
        }
        else if (exp[i] == ')') {
            while (!s.empty() && (top = s.top()) != '(') {
                suffix += top; s.pop();
            }
            s.pop();
        }
    }
    while (!s.empty()) {
        suffix += s.top(); s.pop();
    }
    return suffix;
}

int eval(const std::string& row, const std::string& suffix, const std::set<char>& exp_elem) {
    char temp = 0;
    int p, q, ret;
    std::stack<char> s;
    std::map<char, int> m;
    std::string::size_type i;
    std::set<char>::const_iterator pos;
    for (pos = exp_elem.begin(), i = 0; pos != exp_elem.end(); ++pos, ++i) {
        m.insert(std::pair<char, int>(*pos, row[i] - '0'));
    }
    m.insert(std::pair<char, int>('1', 1));
    m.insert(std::pair<char, int>('0', 0));
    p = q = 0;
    for (i = 0; i != suffix.size(); ++i) {
        if (isupper(suffix[i]) || suffix[i] == '0' || suffix[i] == '1') { 
            s.push(m[suffix[i]]); 
        }
        else if (isoperator(suffix[i])) {
            q = s.top(); s.pop();
            (q == '1') ? (q = 1) : (q == '0') ? (q = 0) : (q = q);
            if (suffix[i] != '!' && !s.empty()) {
                p = s.top(); s.pop();
            }
            switch (suffix[i]) {
            case '!':
                temp = !q;
                break;
            case '&':
                temp = p && q;
                break;
            case '|':
                temp = p || q;
                break;
            }
            s.push(temp);
        }
    }
    ret = s.top();
    s.pop();
    return ret;
}

bool print_table(const std::string& exp1, const std::string& exp2, const std::set<char>&exp_elem) {
    int cols, rows, temp1, temp2;
    std::string row, suffix1, suffix2;
    bool flag = 1;
    for (std::set<char>::iterator pos = exp_elem.begin(); pos != exp_elem.end(); ++pos) {
        std::cout << '\t' << *pos;
    }
    std::cout << '\t' << exp1 << '\t' << exp2<< "\n";
    suffix1 = infix_to_suffix(exp1);
    suffix2 = infix_to_suffix(exp2);
    cols = exp_elem.size();
    rows = static_cast<int>(pow(2.0, cols));
    std::bitset <26> bs;
    std::vector <char> result;
    for (int i = 0; i < rows; ++i) {
        bs = i;
        row = bs.to_string<char, std::char_traits<char>, std::allocator<char> >();
        row.erase(0, 26 - cols);
        for (int j = 0; j < cols; ++j) {
           std::cout << '\t' << row[j];
        }
        temp1 = eval(row, suffix1, exp_elem);
        temp2 = eval(row, suffix2, exp_elem);
        if (temp1 != temp2) {
            flag = 0;
        }
        std::cout << '\t' << temp1 << '\t' << temp2<< "\n";
    }
    if (flag) {
        std::cout << exp1 << "==" << exp2 << "\n";
    }
    else {
        std::cout << exp1 << "!=" << exp2 << "\n";
    }
    return flag;
}

int is_tautology(const std::vector<char>& result) {
    return result.end() == find(result.begin(), result.end(), 0);
}

int is_contradiction(const std::vector<char>& result) {
    return result.end() == find(result.begin(), result.end(), 1);
}

 

 

int main() {
    std::string exp1, exp2;
    std::set<char> exp_elem;
    std::vector<char> result;
   /*while (1) {
         
        std::cout << "1:";
        std::cin >> exp1;
        std::cout << "2:";
        std::cin >> exp2;
        exp_elem = get_expinfo(exp1, exp2);
        print_table(exp1,exp2, exp_elem);
         
    }*/
   
    bool inc = 1;
    //std::cout << ALU::alu(0, 0, 1, 0, inc) << " " << inc;
    ALU::alu8(8);
    //latch::simulator();
    return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
