#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
using namespace std;

int BruteForce(vector<int> &nums, int k)
{ // Brute Force Approach  TC = O(n2), SC = O(1)
    int n = nums.size();
    int count = 0;

    for (int i = 0; i < n; i++) 
    {
        int sum = 0;
        for (int j = i; j < n; j++)
        {
            sum += nums[j];

            if (sum == k)
            {
                count++;
            }
        }
    }
    return count;
}

// Optimal
#include <vector>
#include <unordered_map>
using namespace std;

int Optimal(vector<int> &nums, int k) {
    int count = 0;
    int n = nums.size();
    vector<int> prefixSum(n, 0);
    prefixSum[0] = nums[0];
    for (int i = 1; i < n; i++) {
        prefixSum[i] = prefixSum[i - 1] + nums[i];                    
    }

    unordered_map<int, int> m;

    for (int j = 0; j < n; j++) {
        if (prefixSum[j] == k)
            count++;

         int val = prefixSum[j] - k;
        if (m.find(val) != m.end()) {
            count += m[val];
        }

        m[prefixSum[j]]++;
    }
    return count;
}

int main()
{
    vector<int> arr = {9, 4, 20, 3, 10, 5};
    int k = 33;

    cout << BruteForce(arr, k) << endl;
    cout << Optimal(arr, k);
}