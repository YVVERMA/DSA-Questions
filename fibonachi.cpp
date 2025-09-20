#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int Fibonacchi(int n)
{
    if (n == 1 || n == 2)
    {
        return 1;
    }
    else
    {
        return Fibonacchi(n - 1) + Fibonacchi(n - 2);
    }
}

int main()
{
    int n;
    cout << "Enter the position of the Fibonacci number";
    cin >> n;
    int result = Fibonacchi(n);
    cout << "The " << n << "-th Fibonacci number is: " << result << endl;
    return 0;
}