#include "stack.hpp"
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#define INF 1e9

using namespace std;

double calc(char op, double a, double b, string &opn) {
    opn = opn + op + " ";
    if (op == '*') return a * b;
    if (op == '+') return a + b;
    if (op == '-') return a - b;
    if (op == '/' && b != 0) return a / b;
    std::cout << "division by 0!\n";
    return INF;
}

int main() {

    stack<double> x;
    stack<char> y;

    char tmp;
    char tmp_s;
    char tmp_last = 's';//start
    string opn = "";


    string stream;
    ifstream f("input.txt");
    getline(f, stream);
    f.close();
    
    //getline(cin, stream);
    
    stringstream fin(stream);

    cout << stream << endl;
	
    while (!fin.eof()) {
        fin >> tmp;
        string num = "";
        while (((tmp >= '0' && tmp <= '9') || ((tmp_last == '(' || tmp_last == 's') && tmp == '-') || (tmp == 'e' || tmp == ',' || (tmp_last == 'e' && (tmp == '-' || tmp == '+')))) && !fin.eof()) {
            num += (tmp == ',' ? '.' : tmp);
            tmp_last = tmp;
            fin >> tmp;
        }

        if (num != "") {
            x.push(stof(num));
            opn += num + " ";
            num = "";
        }

        if (tmp == '(' || tmp == '+' || tmp == '-' || tmp == '*' || tmp == '/') {
            tmp_s = tmp;
        
            while (!y.cmp(tmp_s)) {
                x.push(calc(y.pop(), x.pop(), x.pop(), opn));
                if (x.top() == INF) return 0;
            }
            y.push(tmp_s);
        }
        else if (tmp == ')') {
            tmp_s = y.pop();
            while (tmp_s != '(') {
                x.push(calc(tmp_s, x.pop(), x.pop(), opn));
                if (x.top() == INF) return 0;
                tmp_s = y.pop();
            }

        }
        else if (tmp == '=') {
            while (!y.is_empty()) {
                x.push(calc(y.pop(), x.pop(), x.pop(), opn));
                if (x.top() == INF) return 0;
            }
        }
        tmp_last = tmp;
    }
    opn += tmp;
    cout << x.pop() << endl;
    cout << opn << endl;
    
    return 0;
}

// "7+((6+2)/(1+1)-3)*(9+(2+5)*2)="
