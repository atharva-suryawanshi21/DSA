#include <iostream>
using namespace std;

class StackClass
{
    char stack[20];
    int top = -1;

public:
    void push(char c)
    {
        top++;
        stack[top] = c;
    }
    char pop()
    {
        return stack[top--];
    }
    char GetTop()
    {
        if (top != -1)
            return stack[top];
        else
            return '0';
    }
};
int value(char op, char priority)
{
    if (priority == 's')
    {
        if (op == '^')
            return 3;
        if (op == '*' || op == '/')
            return 2;
        if (op == '+' || op == '-')
            return 1;
        if (op == '(')
            return 0;
        if (op == '0')
            return -1;
        return 0;
    }
    else
    {
        if (op == '^')
            return 4;
        if (op == '*' || op == '/')
            return 2;
        if (op == '+' || op == '-')
            return 1;
        if (op == '(')
            return 4;
        if (op == '0')
            return -1;
        return 0;
    }
}
string InfixToProfix(string infix)
{
    string postfix = infix;
    char waste;
    char ICP, ISP;
    StackClass s1;
    int i, j = 0;

    for (i = 0; i < infix.length(); i++)
    {
        if (infix[i] >= 65 && infix[i] <= 90)
            postfix[j++] = infix[i];
        else
        {
            if (infix[i] == ')')
            {
                while (s1.GetTop() != '(')
                    postfix[j++] = s1.pop();
                waste = s1.pop();
            }
            else
            {
                if (s1.GetTop() == '0' || infix[i] == '(')
                    s1.push(infix[i]);
                else
                {
                    ICP = infix[i];
                    ISP = s1.GetTop();
                    if (value(ICP, 'c') > value(ISP, 's'))
                        s1.push(ICP);
                    else
                    {
                        while (value(s1.GetTop(), 's') >= value(ICP, 'c'))
                            postfix[j++] = s1.pop();
                        s1.push(ICP);
                    }
                }
            }
        }
    }

    while (s1.GetTop() != '0')
        postfix[j++] = s1.pop();

    postfix.erase(j);
    return postfix;
}
int main()
{
    string infix;
    cout << "Enter the infix expression -  " << endl;
    cin >> infix;
    cout << InfixToProfix(infix);
    return 0;
}
