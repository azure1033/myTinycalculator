#include "mstack.h"
#include "symbols.h"

#include <string>


class Calculator {
public:
    Calculator() {}

    void InfixToPostfix(std::string str);

    void get_res();

    int get_operand();

private:
    mstack<char> m_stack;
    mstack<int> stk;
    std::string postfixExpression;
};

inline void Calculator::InfixToPostfix(std::string str)
{
    m_stack.clear();
    postfixExpression.clear();
    for (char c : str) {
        auto s = charToSymbol(c);
        switch (s) {
            case OPERAND:
                postfixExpression += c; continue;
            case PAREN_OPEN: 
                m_stack.push(c); 
                continue;
            case PAREN_CLOSE: 
                while (!m_stack.isEmpty() && m_stack.top() != '(') {
                    postfixExpression += m_stack.top(); m_stack.pop();
                }
                if (!m_stack.isEmpty() && m_stack.top() == '(') {
                    m_stack.pop(); // 弹出 '(' 但不输出
                }
                continue;
            case PLUS: case MINUS:
                while (!m_stack.isEmpty() && m_stack.top() != '(' && 
                       (m_stack.top() == '+' || m_stack.top() == '-' || m_stack.top() == '*' || m_stack.top() == '/')) {
                    postfixExpression += m_stack.top(); m_stack.pop();
                } 
                m_stack.push(c); 
                continue;
            case MULTIPLY: case DIVIDE:
                while (!m_stack.isEmpty() && m_stack.top() != '(' && 
                       (m_stack.top() == '*' || m_stack.top() == '/')) {
                    postfixExpression += m_stack.top(); m_stack.pop();
                } 
                m_stack.push(c);
                continue;
            default: continue;
        }
    }
    while (!m_stack.isEmpty()) {
        postfixExpression += m_stack.top(); m_stack.pop();
    }
}

inline void Calculator::get_res()
{
    stk.clear();
    int a, b;
    for (char c : postfixExpression) {
        switch (c) {
            case '1': case '2': case '3': case '4': case '5': case '6': case '7': case '8': case '9': case '0': 
                stk.push(c - '0');
                continue;
            case '+':
                a = get_operand();
                b = get_operand();
                stk.push(b + a);
                continue;
            case '-':
                a = get_operand();
                b = get_operand();
                stk.push(b - a);
                continue;
            case '*':
                a = get_operand();
                b = get_operand();
                stk.push(b * a);
                continue;
            case '/':
                a = get_operand();
                b = get_operand();
                stk.push(b / a);
        }
    }

    std::cout << "The expression equals to: " << stk.top() << "\n";
}

inline int Calculator::get_operand()
{
    int tmp = stk.top();
    stk.pop();
    return tmp;
}
