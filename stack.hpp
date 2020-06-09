#pragma once
#include <iostream>
#include <string>

using namespace std;

template<class T> class stack_elem {
public:
    T n;
    stack_elem* next;
};

template<class T> class stack {
public:

    stack_elem<T>* list;

    stack() {
        list = NULL;
    };

    void push(T x) {
        if (list == NULL) {
            list = new stack_elem<T>();
            list->n = x;
        }

        else {
            stack_elem<T>* tmp = new stack_elem<T>;
            tmp->n = x;
            tmp->next = list;
            list = tmp;
        }
    };

    T pop() {
        T x = list->n;
		stack_elem<T>* B = list;
		list = list->next;
		delete(B);
		return x;
    };

    T top() {
        return list->n;
    };

    void print() {
        stack_elem<T>* tmp = list;
        while (tmp != NULL) {
            cout << tmp->n << " ";
            tmp = tmp->next;
        }
        cout << endl;
    };
    
    bool cmp(const T& x) {
        if (list == NULL || list->n == '(' || x == '(')
            return true;
        int a = 0, b = 0;

        switch ((list->n)) {
            case '(': a++;
            case '*':
            case '/': a++;
            case '+':
            case '-': a++;
        }
        switch (x) {
            case '(': b++;
            case '*':
            case '/': b++;
            case '+':
            case '-': b++;
        }

        return a < b;
    }
    
    bool is_empty() {
        return list == NULL;
    }
};

