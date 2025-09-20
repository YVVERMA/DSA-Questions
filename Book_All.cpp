// Book Allocation Problem
/* question
There are N books each ith book has A[i] number of pages
You have to allocate to a student is minimum

* each book should be allocated to a student
* Each student has to be allocated at least one book
* Allotment should be in contiguos order
Calculate and return that mimimum possible number

Return -1 iuf a valid assignment is not possible.
*/
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

bool isAlloca(vector<int> &arr, int n, int m, int maxBook)
{
    int stu = 1;
    int pages = 0;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] > maxBook)
            return false;

        if (pages + arr[i] <= maxBook)
        {
            pages += arr[i];
        }
        else
        {
            stu++;
            pages = arr[i];
        }
    }

    return stu > m ? false : true;
    return stu <= m ? true : false;
}

int bookAllocation(vector<int> &arr, int n, int m)
{
    if (m > n)
        return false;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }

    int st = 0;
    int end = sum;
    int ans = -1;

    while (st <= end)
    {
        int mid = st + (end - st) / 2;

        if (isAlloca(arr, n, m, mid))
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
    vector<int> Pages = {2, 1, 3, 4};
    int n = Pages.size();
    int m = 2;

    cout << bookAllocation(Pages, n, m);
}