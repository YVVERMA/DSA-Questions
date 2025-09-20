#include <iostream>
#include <cstring> // Include this header for strlen
#include <vector>
#include <string>
using namespace std;

// String
/*// Character Arrays -> C String
int main()
{
    char str[] = {'a', 'b', 'c', '\0'}; // (\n) Null Character
    cout << str << endl;
    cout << "String length: " << strlen(str) << endl;
    return 0;
}


*/

/*
int main()
{
    char str[] = "Hello"; // String literals
    // /*char array in memory => ['H','e','l','l','o']

    cout << "String length: " << strlen(str) << endl;
    cout << str[2] << endl; // l;
    cout << str[5] << endl; // Nothing Value;
}*/

// Character Arrays -> Input & Output

// int main()
// {
//     char str[12];
//     cout << "Input: ";
//     // cin >> str;        /-->/
//     cin.getline(str, 12, '.'); // Delemeter stop the input

//     for (auto ch : str)
//         cout << ch << " ";
// }

// int main()
// {
//     char str[] = "Coding Hero";//
//     int len = 0;

//     for (int i = 0; i < str[i] != '\0'; i++)
//     {
//         len++;
//     }

//     cout << "Length of string: " << len << endl;
// }

// String
// #include <string>
// int main()
// {
//     string str = "Program"; // dynamic => runtime resize
//     string str2 = "Code";

//     string str3 = str + str2;// Concatenation
//     cout << str3 << endl;
// }

// string input
// int main()
// {
//     string str;
//     // cin >>  str;
//     getline(cin, str, '.');
//     cout << str << endl;
// }

// loops in String
// int main()
// {
//     string str = "String";
//     int n = str.size();

//     for (int i = 0; i < n; i++)//  for loops
//     {
//         cout << str[i] << " ";
//     }
//     cout << endl;

//     for(char c : str){ // forEach loop
//         cout << c << " ";
//     }

// }

// Reverse String

int main()
{
    string str = "Reverse";
    int st = 0;
    int end = str.size() - 1;

    while (st <= end)
    {
        swap(str[st++], str[end--]);
    }

    for (char ch : str)
    {
        cout << ch << " ";
    }
}