// Search in Rotated Sorted Array | Binary Search Leetcode 33
#include <iostream>
#include <vector>
using namespace std;
// ascending order: distinct values
int search(vector<int> &A, int target)
{
    int n = A.size();
    int st = 0;
    int end = n - 1;

    while (st <= end)
    {
        int mid = st + (end - st) / 2;
        if (A[mid] == target)
        {
            return mid;
        }

        if (A[st] <= A[mid])
        { // left side
            if (A[st] <= target && target <= A[mid])
            {
                end = mid - 1;
            }
            else
            {
                st = mid + 1;
            }
        }
        else
        {
            if (A[mid] <= target && target <= A[end])
            {
                st = mid + 1;
            }
            else
            {
                end = mid - 1;
            }
        }
    }
}

int main()
{
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    int target = 0;
    cout << search(nums, target) << endl;
}