/*Given a String S, reverse the string without reversing its individual words. Words are separated by dots.*/
#include <iostream>
#include <queue>
#include <stack>
using namespace std;

int main()
{
    string S = "i.like.this.program.very.much";

    stack<string> Stack;
    string str = "";

    int i = 0;
    while (i < S.length())
    {
        if (S[i] == '.')
        {
            Stack.push(str);
            str.clear();
        }
        else
        {
            str += S[i];
        }
        i++;
        if (i == S.length())
        {
            Stack.push(str);
            str.clear();
        }
    }

    while (Stack.empty() == 0)
    {
        str += Stack.top();
        Stack.pop();
        if (Stack.empty() == 0)
            str += ".";
    }
    cout << str;
}
