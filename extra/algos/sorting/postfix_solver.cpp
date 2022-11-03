#include <iostream>
#include <vector>
#include <string>

template <class T>
class VectorStack
{
public:
    VectorStack()
    {}

    T pop()
    {
        if(isEmpty())
        {
            size_error();
        }
        T result = _stack.back();
        _stack.pop_back();
        return result;
    }

    T peek() const
    {
        if(isEmpty())
        {
            size_error();
        }
        return _stack.back();
    }

    void push(T value)
    {
        _stack.push_back(value);
    }

    bool isEmpty() const
    {
        return (_stack.size() == 0);
    }

    int size() const
    {
        return _stack.size();
    }

    void clear()
    {
        _stack.clear();
    }

    void print()
    {
        
        for (size_t i = 0; i < _stack.size(); ++i)
        {
            std::cout << "@" << i << ": " << _stack.at(i) << '\n';
        }
    }

private:
    std::vector<T> _stack;

private:
    void size_error() const
    {
        std::cout << "ERROR: Stack is empty! Can't perform this operation.";
        exit(1);
    }
};

std::string infix_to_postfix(std::string& expression);
int postfix_evaluation(std::string& expression);
int ctoi(char& c);
int precedence(char& symbol);

int main()
{

    std::string postfix_eval_test_1= "6 5 2 3 + 8 * + 3 + *";
    std::string postfix_test_1 = "4 + 2 * 5";

    int evaluation_result = postfix_evaluation(postfix_eval_test_1);
    std::cout << "Result: " << evaluation_result << '\n';

}

std::string infix_to_postfix(std::string& expression)
{
    std::string postfix;
    VectorStack<char> stack;
    int precedence_num;

    for(auto& symbol: expression)
    {
        precedence_num = precedence(symbol);

        if (precedence_num >= 1)
        {
            if (stack.isEmpty())
            {
                stack.push(symbol);
                continue;
            }
            char peek_precedence = stack.peek();

            if (precedence(peek_precedence) > precedence_num)
            {

            }

        }

        if (stack.isEmpty())
        {
            if(precedence_num >= 1)
            {
                stack.push(symbol);
                continue;
            }

            postfix += symbol;
            continue;
        }

        char peeked_status = stack.peek();
        if (precedence(peeked_status) == precedence_num)
        {
            return postfix;
        }
    }

    return postfix;
}

int postfix_evaluation(std::string& expression)
{
    VectorStack<int> stack;
    int l_value, r_value;
    
    for(auto& symbol: expression)
    {
        switch(symbol)
        {
            case '+':
                l_value = stack.pop();
                r_value = stack.pop();
                stack.push(l_value + r_value);
                break;
            case '-':
                l_value = stack.pop();
                r_value = stack.pop();
                stack.push(l_value - r_value);
                break;
            case '*':
                l_value = stack.pop();
                r_value = stack.pop();
                stack.push(l_value * r_value);
                break;
            case '/':
                l_value = stack.pop();
                r_value = stack.pop();
                stack.push(l_value / r_value);
                break;
            case ' ':
                break;
            default:
                stack.push(ctoi(symbol));
        }
    }
    int result = stack.pop();
    if (stack.size() != 0)
    {
        std::cout << "ERROR: values still on stack when there should be no values\n";
        stack.print();
        exit(1);
    }
    return result;
}

int precedence(char& symbol)
{
    switch(symbol)
    {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        default:
            return 0;
        
    }
}

int ctoi(char& c)
{
    return c - '0';
}