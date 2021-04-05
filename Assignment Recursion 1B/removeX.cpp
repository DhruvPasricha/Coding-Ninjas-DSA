/*
    ---------------------------------------------------------------------------
    Remove X
    ---------------------------------------------------------------------------
    Send Feedback
    ---------------------------------------------------------------------------
    Given a string, compute recursively a new string where all 'x' chars have been removed.
    ---------------------------------------------------------------------------
    Input format :
    String S
    ---------------------------------------------------------------------------
    Output format :
    Modified String
    ---------------------------------------------------------------------------
    Constraints :
    1 <= |S| <= 10^3
    where |S| represents the length of string S. 
    ---------------------------------------------------------------------------
    Sample Input 1 :
    xaxb
    ---------------------------------------------------------------------------
    Sample Output 1:
    ab
    ---------------------------------------------------------------------------
    Sample Input 2 :
    abc
    ---------------------------------------------------------------------------
    Sample Output 2:
    abc
    ---------------------------------------------------------------------------
    Sample Input 3 :
    xx
    ---------------------------------------------------------------------------
    Sample Output 3:
    
    ---------------------------------------------------------------------------
*/

#include <iostream>
using namespace std;

void shiftByOne(char input[], int i)
{
    for (int j = i; input[j]; j++)
        input[j] = input[j + 1];
    return;
}

void removeX(char input[])
{
    static int i = -1;
    ++i;

    if (input[i] == '\0')
        return;

    if (input[i] == 'x')
    {
        shiftByOne(input, i);
        i--;
    }
    removeX(input);
}

int main()
{
    char input[100];
    cin.getline(input, 100);
    removeX(input);
    cout << input << endl;
}
