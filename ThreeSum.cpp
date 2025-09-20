#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <set>
using namespace std;

//
/* BruteForce Approach 😡TLE😡
vector<vector<int>> BruteForce(vector<int> &nums)
{
    vector<vector<int>> ans;
    set<vector<int>> s; // unique Triplets
    int n = nums.size();

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            for (int k = j + 1; k < n; k++)
            {
                if (nums[i] + nums[j] + nums[k] == 0)
                {
                    vector<int> trip = {nums[i],
                                        nums[j],
                                        nums[k]};
                    sort(trip.begin(), trip.end());

                    if (s.find(trip) == s.end())
                    {
                        s.insert(trip);
                        ans.push_back(trip);
                    }
                }
            }
        }
    }
    return ans;
}
int main()
{
    vector<int> arr = {-1, 0, 1, 2, -1, -4};
    vector<vector<int>> ans = BruteForce(arr);

    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << " , ";
    }
}

*/

//
/*Appriacg with Hashing 😡TLE😡
vector<vector<int>> threeSum(vector<int> &nums)
{
    int n = nums.size();

    set<vector<int>> unique; // set<usiqueTriplets>

    for (int i = 0; i < n; i++)
    {
        int tar = -nums[i];
        set<int> s;
        for (int j = i + 1; j < n; j++)
        {
            int third = tar - nums[j];
            if (s.find(third) != s.end())
            {
                vector<int> trip = {nums[i], nums[j], third};
                sort(trip.begin(), trip.end());
                unique.insert(trip);
            }
            s.insert(nums[j]);
        }
    }
    vector<vector<int>> ans(unique.begin(), unique.end());
    return ans;
}

int main()
{
    vector<int> arr = {-1, 0, 1, 2, -1, -4};
    vector<vector<int>> ans = threeSum(arr);

    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << ",";
    }
}
*/
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> threeSum(vector<int> &nums)
{
    int n = nums.size();
    vector<vector<int>> ans;

    sort(nums.begin(), nums.end());

    for (int i = 0; i < n; i++)
    {

        if (i > 0 && nums[i] == nums[i - 1])
            continue;

        int j = i + 1;
        int k = n - 1;

        while (j < k)
        {
            int sum = nums[i] + nums[j] + nums[k];
            if (sum < 0)
            {
                j++;
            }
            else if (sum > 0)
            {
                k--;
            }
            else
            {
                ans.push_back({nums[i], nums[j], nums[k]});
                j++;
                k--;

                while (j < k && nums[j] == nums[j - 1])
                    j++;
                while (j < k && nums[k] == nums[k + 1])
                    k--;
            }
        }
    }
    return ans;
}

int main()
{
    vector<int> arr = {-1, 0, 1, 2, -1, -4};
    vector<vector<int>> ans = threeSum(arr);

    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << "  -  ";
    }
}
