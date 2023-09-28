/*Given an integer array nums, find the
subarray
 with the largest sum, and return its sum.*/

#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;
int main()
{
    vector<int> nums = {2, -3, -1, 5, -8, -1, 7, 9, -2, -9, 11, 1};

    int max_till_here = 0;
    int max_so_far = INT_MIN;
    int left_i, right_i;

    // max_till_here - will keep track on the max value of subarray that ends at that perticular index of array
    // max_so_far - will keep track on the max value throughout the transversed part of array

    for (int i = 0; i < nums.size(); i++)
    {
        max_till_here += nums[i]; // max value of subarray ending at nums[i]
        if (max_till_here < nums[i])
        {
            max_till_here = nums[i]; // if nums[i] is larger than max_till_here, we wont need previous values,
            left_i = i;              // as we can start our subarray from nums[i] itself
        }
        if (max_till_here > max_so_far)
        {
            max_so_far = max_till_here; // we need to update the maximum value in subarray
            right_i = i;
        }
    }
    cout << "maximum sub array :- " << max_so_far << endl;
    cout << endl
         << "The sub array is :- " << endl;
    cout << "[ ";
    for (int j = left_i; j <= right_i; j++)
    {
        cout << nums[j];
        if (j != right_i)
            cout << " ,";
    }
    cout << " ]";
}