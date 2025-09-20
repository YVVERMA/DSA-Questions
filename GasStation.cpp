#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
{
    int Sum_Of_Gas = 0;
    int Sum_Of_Cost = 0;

    for (int val : gas)
    {
        Sum_Of_Gas += val;
    }

    for (int val : cost)
    {
        Sum_Of_Gas += val;
    }
    if (Sum_Of_Gas < Sum_Of_Cost)
    {
        return -1;
    }

    // unique solution always exists
    int start = 0, currGas = 0;

    for (int i = 0; i < gas.size(); i++)
    {
        currGas += (gas[i] - cost[i]);

        if (currGas < 0)
        {
            start = i + 1;
            currGas = 0;
        }
    }
    return start;
}

int main()
{
    vector<int> gas = {1, 2, 3, 4, 5};
    vector<int> cost = {3, 4, 5, 1, 2};

    int result = canCompleteCircuit(gas, cost);

    cout << "Gas Station: " << result;
}
