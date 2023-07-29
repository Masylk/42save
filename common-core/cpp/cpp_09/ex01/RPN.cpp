#include "RPN.hpp"

RPN::RPN(/* args */)
{
}

RPN::RPN(const char *expr) : expression(expr)
{
    expLen = expression.size();
}

RPN::RPN(const RPN &cpy) : expression(cpy.expression), expLen(cpy.expLen)
{
    *this = cpy;
}

RPN::~RPN()
{
}

RPN &RPN::operator=(const RPN &rhs)
{
    if (this != &rhs)
    {
        expLen = rhs.expLen;
        expression = rhs.expression;
        operands = rhs.operands;
        members = rhs.members;
    }
    return *this;
}

bool    RPN::isOperator(char ch)
{
    return (ch == '+' || ch == '-' || ch == '/' || ch == '*');
}

void    RPN::print_error(const std::string err) const
{
    std::cerr << err << std::endl;
}

void    RPN::print_result()
{
    for(int i = 0; i < expLen; i++)
    {
        if (std::isdigit(expression[i]))
            operands.push(expression[i] - '0');
        else if (isOperator(expression[i]))
        {
            if (operands.size() < 2)
                return print_error("Error: operands missing");
            int op_b = operands.top();
            operands.pop();
            int op_a = operands.top();
            operands.pop();

            switch(expression[i]) {
                case '+':
                    operands.push(op_a + op_b);
                    break;
                case '-':
                    operands.push(op_a - op_b);
                    break;
                case '/':
                    if (op_b == 0) 
                        return print_error("Error:  zero division");
                    operands.push(op_a / op_b);
                    break;
                case '*':
                    operands.push(op_a * op_b);
                    break;
                
            }
        }
        else if (expression[i] == ' ')
            continue;
        else
        {
            std::string str = "Error: invalid char \'";
            str += expression[i];
            str += '\'';
            return print_error(str.c_str());
        }
    }
    if (operands.size() != 1)
        return print_error("Error: operands missing");
    std::cout << operands.top() << std::endl;
}