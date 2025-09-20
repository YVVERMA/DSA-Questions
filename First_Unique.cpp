#include <iostream>
#include <unordered_map>
#include <queue>

using namespace std;

// Function to find the first unique character in a string
int firstUniqChar(string s)
{
    unordered_map<char, int> m;
    queue<int> q;

    for (int i = 0; i < s.size(); i++)
    {
        if (m.find(s[i]) == m.end())
        {
            q.push(i);
        }
        m[s[i]]++;
        while (q.size() > 0 && m[s[q.front()]] > 1)
        {
            q.pop();
        }
    }
    return q.empty() ? -1 : q.front();
}

int main()
{
    string s = "loveleetcode";
    // Call the function and store the result
    int result = firstUniqChar(s);

    // Output the result based on whether a unique character is found
    if (result == -1)
    {
        cout << "No unique character found." << endl;
    }
    else 
    {
        cout << "The first unique character is: " << s[result] << endl;
    }
}