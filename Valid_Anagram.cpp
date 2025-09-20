#include <iostream>
#include <string>

using namespace std;

bool isAnagram(string s, string t)
{
    if (s.length() != t.length())
    {
        return false;
    }

    int count[26] = {0};

    for (char c : s)
    {
        count[c - 'a']++;
    }

    for (char c : t)
    {
        count[c - 'a']--;
        if (count[c - 'a'] < 0)
        {
            return false;
        }
    }

    return true;
}

int main()
{
    string s = "cars";
    string t = "rcas";

    if (isAnagram(s, t))
    {
        cout << s << " and " << t << " are anagrams." << endl;
    }
    else
    {
        cout << s << " and " << t << " are not anagrams." << endl;
    }

    return 0;
}
