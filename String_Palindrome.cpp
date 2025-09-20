#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
// Valid Palindrome
bool isPalindrome(string s)
{
    int n = s.size();
    int st = 0;
    int end = n - 1;

    while (st <= end)
    {
        if (!isalnum(s[st]))
        {
            st++;
            continue;
        }
        else if (!isalnum(s[end]))
        {
            end--;
        }
        else if (tolower(s[st]) != tolower(s[end]))
        {
            return false;
        }
        st++;
        end--;
    }
    return true;
}

int main()
{
    string str = "racecar";
  

    if (isPalindrome(str))
    {
        cout << str << " is Palindrome";
    }
    else
    {
        cout << str << " Not Palindrome";
    }
};
