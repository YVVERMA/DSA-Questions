#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

string reverseWords(string s)
{
    reverse(s.begin(), s.end());
    int n = s.size();
    string ans = "";

    for (int i = 0; i < n; i++)
    {
        string word = "";
        while (i < n && s[i] != ' ')
        {
            word += s[i];
            i++;
        }
        reverse(word.begin(), word.end());
        if (word.length() > 0)
        {
            ans += " " + word;
        }
    }
    return ans.substr(1);
}

int main()
{
    string s1 = "the sky is blue";
    string s2 = "hello world";
    string s3 = "a good   exampale";
    cout << "(1) " << s1 << endl;
    cout << reverseWords(s1) << endl;
    cout << "(2) " << s2 << endl;
    cout << reverseWords(s2) << endl;
    cout << "(3) " << s3 << endl;
    cout << reverseWords(s3) << endl;
}