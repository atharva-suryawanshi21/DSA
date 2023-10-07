/*There is an integer array nums sorted in ascending order (with distinct values).
Prior to being passed to your function, nums is possibly rotated at an unknown pivot index k (1 <= k < nums.length)
such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed).
For example, [0,1,2,4,5,6,7] might be rotated at pivot index 3 and become [4,5,6,7,0,1,2].
Given the array nums after the possible rotation and an integer target, return the index of target if it is in nums, or -1 if it is not in nums.
You must write an algorithm with O(log n) runtime complexity.
*/

#include <iostream>
#include <vector>
using namespace std;

int unsort(vector<int> nums, int target, int start, int end)
{
    int mid = (start + end) / 2;
    if (nums[mid] == target)
        return mid;
    if (nums[start] == target)
        return start;
    if (nums[end] == target)
        return end;

    if ((nums[mid] != target) && (start == mid))
        return -1;

    cout << start << "  " << mid << "  " << end << endl;
    if (nums[mid] < target)
    {
        if (nums[end] < target)
            return unsort(nums, target, mid + 1, end);
        else
            return unsort(nums, target, start, end);
    }
    else
    {
        if (nums[start] < target)
            return unsort(nums, target, start, mid);
        else
            return unsort(nums, target, mid + 1, end);
    }
}

int main()
{
    // vector<int> nums = {4, 5, 6, 7, 8, 1, 2, 3};
    // int target = 8;
    // vector<int> nums = {4, 5, 6, 7, 8, 1, 2, 3};
    // int target = 8;
    vector<int> nums = {1, 3, 5};
    int target = 4;

    int start = 0, end = nums.size() - 1;
    int index = unsort(nums, target, start, end);
    cout << index;
}
