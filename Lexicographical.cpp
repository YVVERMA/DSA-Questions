#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;
vector<int> LexicographicalNum(int n)
{
    vector<int> ans;
    for (int i = 1; i <= n; i++)
    {
        ans.push_back(i);
    }
    sort(ans.begin(), ans.end(), [](int a, int b) {
        return to_string(a) < to_string(b);
    });
    return ans;
}

int main()
{
    int n = 13;
    vector<int> ans = LexicographicalNum(n);
    for (int val : ans)
    {
        cout << val << " ";
    }
}