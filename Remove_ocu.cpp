#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

string Remove_Occurerences(string s, string part)
{
    while (s.length() > 0 && s.find(part) < s.length())
    {
        s.erase(s.find(part),part.length());
    }
    return s;
    
}
int calculateDigitSum(int num)
{
    int sum = 0;
    while (num > 0)
    {
        int dig = num % 10;
        sum += dig;
        num /= 10;
    }
    return sum;
}

int main()
{
    string s = "daabcdaabcbc";
    string part = "abc";
    cout << Remove_Occurerences(s, part) << endl;
    // cout << calculateDigitSum(53);
}
