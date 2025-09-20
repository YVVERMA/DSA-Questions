#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

/*
Constraints:
1 <= s1.length, s2.length <= 104
s1 and s2 consist of lowercase English letters.
*/
// window base Approach

bool isFreqSame(int freq1[], int freq2[]) {
    for (int i = 0; i < 26; i++) {
        if (freq1[i] != freq2[i]) { // Compare freq1[i] with freq2[i]
            return false;
        }
    }
    return true;
}

bool checkInclusion(string s1, string s2) {
    int freq[26] = {0}, windFreq[26] = {0};
    
    // Build frequency array for s1
    for (char c : s1) {
        freq[c - 'a']++;
    }

    int windSize = s1.length();
    int s2Len = s2.length();

    // Traverse s2 with a sliding window
    for (int i = 0; i < s2Len; i++) {
        // Add current character to the window
        windFreq[s2[i] - 'a']++;

        // Remove the character that is out of the window
        if (i >= windSize) {
            windFreq[s2[i - windSize] - 'a']--; 
        }

        // Compare the frequency arrays
        if (isFreqSame(freq, windFreq)) {
            return true;
        }
    }

    return false;
}


int main()
{
    string s1 = "ab";
    string s2 = "eidbaooo";

    if (checkInclusion(s1, s2))
    {
        cout << "Permutation String";
    }
    else
    {
        cout << "Not Permutation";
    }
};
