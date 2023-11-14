#include <iostream>
using namespace std;

int main()
{
    long long N = 42;
    long long num = 1;
    for (int i = 0; i <= N; i++)
    {
        num = num + num * i;
        cout << i << endl;
    }

    cout << num << endl;
    int digits = 0;
    while (num)
    {
        cout << digits;
        num = num / 10;
        digits++;
    }
    // cout << digits;
}