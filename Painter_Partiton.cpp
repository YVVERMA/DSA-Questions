// Painter's Partition Problem
/*question
Given are N boards of length of each given in the form of array and M painters, such that each painter takes 1 unit of time to paint 1 unit of the board.

 The task is to find the minimum time to paint all boards under the constraints that ansy painter will only paint continous section of boards
*/

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

bool isPossible(vector<int> &arr, int n, int m, int MaxPaint)
{
    int board = 1;
    int time = 0;

    for (int i = 0; i < n; i++)
    {

        if (time + arr[i] <= MaxPaint)
        {
            time += arr[i];
        }
        else
        {
            board++;
            time = arr[i];
        }
    }
    return board <= m;
}

int Painter_partition(vector<int> &arr, int n, int m)
{
    if (m > n)
        return -1;

    int Max = INT_MIN;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        Max = max(Max, arr[i]);
    }

    int st = Max;
    int end = sum;
    int ans = -1;

    while (st <= end)
    {
        int mid = st + (end - st) / 2;

        if (isPossible(arr, n, m, mid))
        {
            ans = mid;
            end = mid - 1;
        }
        else
        {
            st = mid + 1;
        }
    }
    return ans;
}

int main()
{
    vector<int> arr = {40, 30, 10, 20};
    int n = arr.size();
    int m = 2;
    cout << "Minimum time to paint: " << Painter_partition(arr, n, m);
}
