/*Given an array A[ ] of positive integers of size N,
where each value represents the number of chocolates in a packet.
Each packet can have a variable number of chocolates.
There are M students, the task is to distribute chocolate packets among M students such that :
1. Each student gets exactly one packet.
2. The difference between maximum number of chocolates given to a student
and minimum number of chocolates given to a student is minimum.*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>

using namespace std;
int main()
{
    vector<long long> a = {8, 11, 3, 12, 2};
    long long n = a.size();
    long long m = 3;

    sort(a.begin(), a.end());

    long long min_from_here = 0;
    long long min_so_far = INT_MAX;
    for (int i = 0; i <= n - m; i++)
    {
        min_from_here = a[i + m - 1] - a[i];

        if (min_so_far > min_from_here)
            min_so_far = min_from_here;
    }
    cout << min_so_far;
}