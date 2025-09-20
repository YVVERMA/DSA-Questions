#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <unordered_set>
// Find Duplicate Number
// leetcode = 287
using namespace std;

// using unordered_set;
int Duplicate(vector<int> &A)
{
    unordered_set<int> s;
    for (int val : A)
    {
        if (s.find(val) != s.end())
        {
            return val;
        }
        s.insert(val);
    }
    return -1;
}

// Slow-fast Pointers
int findDuplicate(vector<int> &A)
{  
    int slow = A[0];
    int fast = A[0];
    do
    {
        slow = A[slow];    // +1
        fast = A[A[fast]]; // +2
    } while (slow != fast);
    slow = A[0];

    while (slow != fast)
    {
        slow = A[slow]; // + 1;
        fast = A[fast]; //+ 1;
    }
    return slow;
}

int main()
{
    vector<int> A = {2, 4, 5, 3, 1, 3};

    // cout << "Duplicate Value is: " << Duplicate(A) << endl;
    cout << "Duplicate Value is: " << findDuplicate(A) << endl;
}

 
 