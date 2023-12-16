#include <iostream>
#include <regex>
/* Hard: Given an array filled with letters and numbers,
 * find the longest subarray with an equal number of letters and numbers.
 * */
using namespace std;

string recursiveRegEx(const string queriedString,
                      string regExAl,
                      string regExNum,
                      smatch stringMatches)
{
    regex find(("(" +regExAl + regExNum + ")"));
    regex find2(( "(" + regExNum + regExAl + ")"));

    if(regex_search(queriedString, stringMatches, find)||regex_search(queriedString, stringMatches, find2))
    {
        return stringMatches[0];
    }
    else if (regExAl.length() > 0)
    {
        regExAl.erase(regExAl.find_first_of('['),(regExAl.find_first_of(']')+1));
        regExNum.erase(regExNum.find_first_of('['),(regExNum.find_first_of(']')+1));

        return recursiveRegEx(queriedString,regExAl,regExNum,stringMatches);

    }
    else
    {
        return "\nNo substring of an equal number of digits and alphabets.\n";
    }
}

int main() {
    string myString;// Longest substring with equally many chars will be 5 letters and 5 numbers {78899aAyIP}
    cout << "Enter a string of letters and numbers";
    cin >> myString;
    cout << "\nFinding longest substring matching criteria.\n";
    int length = myString.length();
    int maxSubLength = length/2;

    string partAlphaBase = "[A-Za-z]";
    string partNumBase = "[0-9]";
    string partAlpha,partNum;
    for (int i = 0; i <= maxSubLength; ++i)
    {
        partAlpha += partAlphaBase;
        partNum += partNumBase;
    }
    smatch sm;
    cout<<"The Longest substring with an equal number of letters and numbers EX:(aa11) from the string is: "<< recursiveRegEx(myString,partAlpha,partNum,sm);
}
// May contain errors, very nearly ran out of time.

