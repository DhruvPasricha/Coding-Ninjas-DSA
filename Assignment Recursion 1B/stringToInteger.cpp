/*
    ---------------------------------------------------------------------------
    String to Integer
    ---------------------------------------------------------------------------
    Send Feedback
    ---------------------------------------------------------------------------
    Write a recursive function to convert a given string into the number it represents. That is input will be a numeric string that contains only numbers, you need to convert the string into corresponding integer and return the answer.
    ---------------------------------------------------------------------------
    Input format :
    Numeric string S (string, Eg. "1234")
    ---------------------------------------------------------------------------
    Output format :
    Corresponding integer N (int, Eg. 1234)
    ---------------------------------------------------------------------------
    Constraints :
    0 <= |S| <= 9
    where |S| represents length of string S.
    ---------------------------------------------------------------------------
    Sample Input 1 :
    00001231
    ---------------------------------------------------------------------------
    Sample Output 1 :
    1231
    ---------------------------------------------------------------------------
    Sample Input 2 :
    12567
    ---------------------------------------------------------------------------
    Sample Output 2 :
    12567
    ---------------------------------------------------------------------------
*/

#include <iostream>
using namespace std;

int strlen(char input[])
{
    int l = 0;
    while (input[l])
        l++;
    return l;
}

int pow(int x, int n)
{
    if (n == 0)
        return 1;
    int halfPower = pow(x, n / 2);
    return (n & 1) ? (halfPower * halfPower * x) : (halfPower * halfPower);
}

int stringToNumber(char input[])
{
    if (input[0] == '\0')
        return 0;
    return stringToNumber(input + 1) + (input[0] - 48) * (pow(10, strlen(input + 1)));
}

int main()
{
    char input[50];
    cin >> input;
    cout << stringToNumber(input) << endl;
}
