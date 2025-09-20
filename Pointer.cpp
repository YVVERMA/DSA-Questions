// Learn Pointers
#include <iostream>
using namespace std;

// 1) Memory Addresses
// 2) Pointers
/*
int main()
{
    int a = 10;
    // a => 10  Address (hexadecimal) => Ox36a6;
    // Address of Oprator => &
    cout << &a << endl; // memory Address
    return 0;
}
*/

// Pointers -> Special variables that store address of other variables
// int main()
// {
//     // int a = 10;
//     // int *ptr = &a; // Pointer *
//     float price = 10.12;
//     float* ptrr = &price;

//     cout << ptrr << endl;
//     cout << &price << endl;
//     cout << &ptrr << endl;// Address of ptr
// }

// Pointer to pointer
// int main() {
//     int a = 10;
//     int* ptr = &a;
//     int** ptr2 = &ptr;

//     cout << &ptr << endl;
//     cout << ptr2 << endl;
// }

// Derefrenceing optartor * Value at address
int main()
{
    int a = 10;
    int *ptr = &a;

    cout << *(&a) << endl;// Derefrens
    cout << *(ptr) << endl;// Derefrens
}
