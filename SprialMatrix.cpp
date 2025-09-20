#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> spiralOrder(vector<vector<int>> &mat)
{
    int m = mat.size();
    int n = mat[0].size();
    int srow = 0, scol = 0, erow = m - 1, ecol = n - 1;
    vector<int> ans;
    while (srow <= erow && scol <= ecol)
    {
        // Top
        for (int j = scol; j <= ecol; j++)
        {
            ans.push_back(mat[srow][j]);
        }

        // Right
        for (int i = srow + 1; i <= erow; i++)
        {
            ans.push_back(mat[i][ecol]);
        }

        // bottom
        for (int i = ecol - 1; i >= scol; i--) 
        {
            if(srow == erow)break;
            ans.push_back(mat[erow][i]);
        }

        // left
        for (int i = erow - 1; i >= srow; i--)
        {
            if (scol == ecol)
                break;
            ans.push_back(mat[i][scol]);
        }
        srow++;
        erow--;
        scol++;
        ecol--;
    }
    return ans;
}

int main()
{
    vector<vector<int>> mat = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};

    vector<int> vec = spiralOrder(mat);
    for (int i = 0; i < vec.size(); i++)
    {
        cout << vec[i] << " ";
        if (i == 4 || i == 8)
        {
            cout << endl;
        }
    }
}