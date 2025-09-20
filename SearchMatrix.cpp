#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*Q
target = 34;
* Each row is sorted in non-decreasing order
* The first integer of each row is grater than the
  last integer of the previous row.
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool SearchInRow(vector<vector<int>> &mat, int target, int row)
{
    int n = mat[0].size();
    int st = 0;
    int end = n - 1;

    while (st <= end)
    {
        int mid = st + (end - st) / 2;

        if (target == mat[row][mid])
        {
            return true;
        }
        else if (target >= mat[row][mid])
        {
            st = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }
    return false;
}

bool searchMatrix(vector<vector<int>> &mat, int target)
{
    int m = mat.size();
    int n = mat[0].size();

    int st = 0;
    int end = m - 1;

    while (st <= end)
    {
        int mid = st + (end - st) / 2;

        if (target >= mat[mid][0] && target <= mat[mid][n - 1])
        {
            return SearchInRow(mat, target, mid);
        }
        else if (target >= mat[mid][n - 1])
        {
            st = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }
    return false;
}

int main()
{
    vector<vector<int>> mat = {{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}};
    int target = 13;

    if (searchMatrix(mat, target))
    {
        cout << target << " Found";
    }
    else
    {
        cout << target << " Not Found";
    }

    return 0;
}
