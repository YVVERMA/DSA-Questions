#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

vector<vector<int>> fourSum(vector<int> &nums, int target)
{
    sort(nums.begin(), nums.end());

    vector<vector<int>> ans;
    int n = nums.size();

    for (int i = 0; i < n; i++)
    {
        if (i > 0 && nums[i] == nums[i - 1])
               continue; // 1st Optimizations

         for (int j = i + 1; j < n;)
        {
            int p = j + 1;
            int q = n - 1;
  
            while (p < q)
            {
                long long sum = (long long)nums[i] + (long long)nums[j] + (long long)nums[p] + (long long)nums[q];
                if (sum < target)
                {
                    p++;
                }
                else if (sum > target)
                {
                    q--;
                }
                else // Sum == target
                {
                    ans.push_back({nums[i], nums[j], nums[p], nums[q]});
                    p++;
                    q--;

                    while (p < q && nums[p] == nums[p - 1])
                        p++; // 3rd Optimizations
                }
            }
            j++;
            while (j < n && nums[j] == nums[j - 1]) // 2nd Optimizations
                j++;
        }

        return ans;
    }
}

int main()
{
    vector<int> nums = {1,0,-1,0,-2,2};
    int target = 0;

    vector<vector<int>> res = fourSum(nums, target);

    for (int i = 0; i < res.size(); i++)
    {
        for (int j = 0; j < res[0].size(); j++)
        {
            cout << res[i][j] << " ";
        }
        cout << "  ";
    }
}

// Lab Template
