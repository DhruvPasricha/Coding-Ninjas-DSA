/*
    ---------------------------------------------------------------------------
    Check Palindrome (recursive)
    ---------------------------------------------------------------------------
    Send Feedback
    ---------------------------------------------------------------------------
    Check whether a given String S is a palindrome using recursion. Return true or false.
    ---------------------------------------------------------------------------
    Input Format :
    String S
    ---------------------------------------------------------------------------
    Output Format :
    'true' or 'false'
    ---------------------------------------------------------------------------
    Constraints :
    0 <= |S| <= 1000
    where |S| represents length of string S.
    ---------------------------------------------------------------------------
    Sample Input 1 :
    racecar
    ---------------------------------------------------------------------------
    Sample Output 1:
    true
    ---------------------------------------------------------------------------
    Sample Input 2 :
    ninja
    ---------------------------------------------------------------------------
    Sample Output 2:
    false
    ---------------------------------------------------------------------------
*/

#include <iostream>
using namespace std;

bool isPalindrome(char input[], int size)
{
    if (size <= 1)
        return true;
    return (input[0] == input[size - 1]) ? isPalindrome(input + 1, size - 2) : false;
}

bool checkPalindrome(char input[])
{
    int l;
    for (l = 0; input[l]; l++)
    {
    }
    return isPalindrome(input, l);
}

int main()
{
    char input[50];
    cin >> input;

    if (checkPalindrome(input))
    {
        cout << "true" << endl;
    }
    else
    {
        cout << "false" << endl;
    }
}
