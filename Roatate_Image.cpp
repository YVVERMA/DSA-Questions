#include <iostream>
#include <string>
#include <vector>
using namespace std;

void RotateImage(vector<vector<int>> &mat)
{-
    int n = mat.size();
    vector<vector<int>> ans(n, vector<int>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            ans[j][n - 1 - i] = mat[i][j];
        }
    }
    mat = ans;
}

void PrintMatrix(const vector<vector<int>> &mat)
{
    for (int i = 0; i < mat.size(); i++)
    {
        for (int j = 0; j < mat[i].size(); j++)
        {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    vector<vector<int>> mat = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int n = mat.size();
    cout << "Normal Matrix: \n";
    PrintMatrix(mat);

    cout << "Rotate Matrix: \n";
    RotateImage(mat);

    PrintMatrix(mat);
}
