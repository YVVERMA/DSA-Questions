// Sort Array with 0s,1s,&2s
// Leetcode = 75
#include <iostream>
#include <climits>
#include <vector>
#include <algorithm>
using namespace std;

// Brute Force Approch
void BruteForce(vector<int> &arr)
{
    sort(arr.begin(), arr.end());
}
// Optimal Approach
void Optimal(vector<int> &arr)
{
    int count0 = 0, count1 = 0, count2 = 0;
    int n = arr.size();

    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 0)
            count0++;
        else if (arr[i] == 1)
            count1++;
        else
            count2++;
    }
    int idx = 0;
    // count0
    for (int i = 0; i < count0; i++)
    {
        arr[idx++] = 0;
    }
    // count1
    for (int i = 0; i < count1; i++)
    {
        arr[idx++] = 1;
    }
    // count2
    for (int i = 0; i < count2; i++)
    {
        arr[idx++] = 2;
    }
}

// DNF Algorithm (Approach);
// Dutch National Flag Algorithm
void DNF(vector<int> &arr)
{
    int n = arr.size();
    int mid = 0, high = n - 1, low = 0;

    while (mid <= high)
    {
        if (arr[mid] == 0)
        {
            swap(arr[low], arr[mid]);
            mid++;
            low++;
        }
        else if (arr[mid] == 1)
        {
            mid++;
        }
        else
        {
            swap(arr[high], arr[mid]);
            high--;
        }
    }
}
int main()
{
    vector<int> arr = {2, 0, 2, 1, 1, 0};
    // BruteForce(arr);
    // Optimal(arr);
    DNF(arr);

    for (int val : arr)
    {
        cout << val << " ";
    }
}