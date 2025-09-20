#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;
vector<int> twoSum(vector<int> &arr, int tar)
{
    unordered_map<int, int> m;
    int n = arr.size();
    vector<int> ans;

    for (int i = 0; i < n; i++)
    {
        int first = arr[i];
        int sec = tar - first;
                                          
        if (m.find(sec) != m.end())
        {
            ans.push_back(i);
            ans.push_back(m[sec]);
        }
        m[first] = i;
    }
    return ans;
    
}

int main()
{
    vector<int> arr = {2, 7, 11, 15};
    int target = 9;
    vector<int> result = twoSum(arr, target);

    for (int val : result)
    {
        cout << val << " ";
    }
}