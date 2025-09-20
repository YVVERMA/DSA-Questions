#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// Next Permutation Return lexicographically next
// A = [ 1, 2, 3 ];

// optimal O(1)SC and o(n)TC
void nextPermutation(vector<int> &A)
{
    int n = A.size();
    int piv = -1;

    for (int i = n - 2; i >= 0; i--)
    {
        if (A[i] < A[i + 1])
        {
            piv = i;
            break;
        }
    }

    if (piv == -1)
    {
        reverse(A.begin(), A.end());
        return;
    }

    for (int i = n - 1; i > piv; i--)
    {
        if (A[i] > A[piv])
        {
            swap(A[i], A[piv]);
            break;
        }
    }

    int i = piv + 1;
    int j = n - 1;

    while (i <= j)
    {
        swap(A[i++], A[j--]);
    }
}

int main()
{
    vector<int> Next = {1, 2, 3};
    nextPermutation(Next);
    cout << "Next Permutation: ";
    for (int num : Next)
    {
        cout << num << " ";
    }
};