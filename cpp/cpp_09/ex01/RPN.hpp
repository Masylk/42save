#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <string>
# include <stack>

class RPN
{
private:
    std::string expression;
    std::stack<int> members;
    int             expLen;
    std::stack<int> operands;
    bool isOperator(char ch);
    RPN(/* args */);
public:
    RPN(const char *expr);
    RPN(const RPN   &cpy);
    ~RPN();

    void    print_error(const std::string err) const;
    void    print_result();
    RPN &operator=(const RPN &rhs);
   
};


#endif