#include <bits/stdc++.h>
using namespace std;

// Function to check if a character is an operator
bool isOperator(char c)
{
    return (!isalpha(c) && !isdigit(c));
}

// Function to convert infix expression to postfix
string infixToPostfix(string infix)
{
    stack<char> operators;
    string postfix = "";
    for (char &c : infix)
    {
        if (isalpha(c) || isdigit(c))
        {
            postfix += c;
        }
        else if (c == '(')
        {
            operators.push(c);
        }
        else if (c == ')')
        {
            while (!operators.empty() && operators.top() != '(')
            {
                postfix += operators.top();
                operators.pop();
            }
            operators.pop();
        }
        else
        {
            while (!operators.empty() && isOperator(operators.top()))
            {
                postfix += operators.top();
                operators.pop();
            }
            operators.push(c);
        }
    }

    // Pop remaining operators from the stack
    while (!operators.empty())
    {
        postfix += operators.top();
        operators.pop();
    }

    return postfix;
}

int main()
{
    string infix = "a+b*(c^d-e)^(f+g*h)-i";
    cout << "Infix: " << infix << "\n";
    cout << "Postfix: " << infixToPostfix(infix);
    return 0;
}
