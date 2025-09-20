// Aggressive Cows Problem
/*question

Assign C cows to N stalls such that min distance between them is larget possible Return largest minimum distance
N = 5; arr=[1,2,8,4,9] C = 3
*/

#include <iostream> 
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

bool isAllowed(vector<int> &arr, int n, int c, int minVal) {
    int cows = 1;         
    int laststall = arr[0];

    for (int i = 1; i < n; i++) {
        if (arr[i] - laststall >= minVal) {
            cows++;
            laststall = arr[i];
        }
        if (cows == c) {
            return true;
        }
    }
    return false;
}

int aggressiveCows(vector<int> &arr, int n, int c) {
    sort(arr.begin(), arr.end());
    int st = 1;  
    int end = arr[n - 1] - arr[0];
    int ans = -1;   

    while (st <= end) {
        int mid = st + (end - st) / 2;
        if (isAllowed(arr, n, c, mid)) {
            ans = mid;
            st = mid + 1;
        } else {
            end = mid - 1;
        }
    }
    return ans;
}

int main() {
    vector<int> arr = {1, 2, 8, 4, 9};
    int n = arr.size();
    int cows = 3;
    cout << "Aggressive Cows: " << aggressiveCows(arr, n, cows) << endl;
    return 0;
}