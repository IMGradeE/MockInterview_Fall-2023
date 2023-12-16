#include <iostream>
#include <string>
using namespace std;
/*Write a recursive function to multiply two positive integers without using the * operator.
 * You can use addition, subtraction, and bit shifting,
 * but you should minimize the number of those operations */

int Multiply(int term1, int count){
 if(count <= 1)
 {
     return term1;
 }
 else
 {
     term1 += Multiply(term1, --count);
 }
    return term1;
}

// definition of even integer products where k is an integer and j is an even integer
// 2k = j
// odd (l is an odd integer)
// 2k+1 = l

int main() {
    for (int i = 1; i <= 4; ++i)
    {
        for (int j = 1; j <= 12; j += 3)
        {
            cout << to_string(Multiply(i, j)) << endl;
        }
    }
    cout << Multiply(1,1)<< endl;
    cout << Multiply(2,6)<< endl;
    cout << Multiply(1,5)<< endl;
    cout << Multiply(11,5)<< endl;
}
