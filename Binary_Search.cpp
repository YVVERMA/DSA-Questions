// Binary Search LeetCode = 704
/*
Binary search is an efficient algorithm used to find a specific target element within a sorted array. It works by repeatedly dividing the search interval in half, eliminating half of the remaining elements with each comparison. This process continues until the target element is found or the search interval becomes empty.
*/
#include <iostream>
#include <vector>
using namespace std;
/* Question
Given an array of integers nums which is sorted in ascending order, and an integer target, write a function to search target in nums. If target exists, then return its index. Otherwise, return -1.

You must write an algorithm with O(log n) runtime complexity
*/

// liner Search O(n)
int liner_search(vector<int> &nums, int target)
{
    int n = nums.size();

    for (int i = 0; i < n; i++)
    {
        if (nums[i] == target)
        {
            return i;
        }
    }
    return -1;
}

// Binary Search O(log n)
// int BinarySearch(vector<int> &nums, int target)
// {
//     int n = nums.size();
//     ;
//     int st = 0;
//     int end = n - 1;

//     while (st <= end)
//     {
//         int mid = st + (end - st) / 2;
//         if (nums[mid] == target)
//         {
//             return mid;
//         }
//         if (nums[mid] < target)
//         {
//             st = mid + 1;
//         }
//         else
//         {
//             end = mid - 1;
//         }
//     }
//     return -1;
// }

// Recursion Binary Search
int BinarySearch(vector<int> &nums, int st, int end, int target)
{
    if (st <= end)
    {
        int mid = st + (end - st) / 2;

        if (target > nums[mid])
        {
            return BinarySearch(nums, mid + 1, end, target);
        }
        else if (target < nums[mid])
        {
            return BinarySearch(nums, st, mid - 1, target);
        }
        else
        {
            return mid;
        }
    }
    return -1;
}

int search(vector<int> &nums, int target)
{
    return BinarySearch(nums, 0, nums.size() - 1, target);
}
int main()
{
    vector<int> nums = {-1, 0, 3, 5, 9, 12};
    int target = 9;
    // cout << liner_search(nums, target);
    // cout << BinarySearch(nums, target);

    /// Recurision Binary Search
    cout << "Recurision Search: " << search(nums, target);
}