#include <iostream>

using namespace std;

/*Moderate: Given two arrays of integers, compute the pair of values (one value in each array)
 * with the smallest (non-negative) difference. Return the difference.
Example:
Input: {1,3,15,11,2}; {23,127,235,19,8}
Output: 3. That is, the pair (11,8)
(page 181, 16.6)*/
int main() {
    int pair[2] = {};
    int currmin = INT_MAX;
    int arr1[5] = {1,3,15,11,2};
    int arr2[5] = {23,127,235,19,8};
    for (int i : arr1)
    {
        for(int j: arr2)
        {
            if (((i - j) >= 0) && (i - j) < currmin)
            {
                pair[0] = i;
                pair[1] = j;
                currmin = (i-j);
            }
            else
            {
                continue;
            }
        }
    }
    cout <<"The lowest difference between numbers in the two arrays is " << currmin << "; From the pair ("<< pair[0] << ", " << pair[1]<< ")\n";
}
// This may contain an error, as I was pressed for time in the interview.
