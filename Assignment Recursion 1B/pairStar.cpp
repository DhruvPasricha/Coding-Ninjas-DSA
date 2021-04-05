/*
    ---------------------------------------------------------------------------
    Pair Star
    ---------------------------------------------------------------------------
    Send Feedback
    ---------------------------------------------------------------------------
    Given a string S, compute recursively a new string where identical chars that are adjacent in the original string are separated from each other by a "*".
    ---------------------------------------------------------------------------
    Input format :
    String S
    ---------------------------------------------------------------------------
    Output format :
    Modified string
    ---------------------------------------------------------------------------
    Constraints :
    0 <= |S| <= 1000
    where |S| represents length of string S.
    ---------------------------------------------------------------------------
    Sample Input 1 :
    hello
    ---------------------------------------------------------------------------
    Sample Output 1:
    hel*lo
    ---------------------------------------------------------------------------
    Sample Input 2 :
    aaaa
    ---------------------------------------------------------------------------
    Sample Output 2 :
    a*a*a*a
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

void shiftByOne(char input[], int i)
{

    for (int j = strlen(input); j >= i + 1; j--)
        input[j + 1] = input[j];
}

void pairStar(char input[])
{

    static int i = -1;
    ++i;
    if (input[i + 1] == '\0')
        return;

    if (input[i] == input[i + 1])
    {

        shiftByOne(input, i);
        input[i + 1] = '*';
        i++;
    }
    pairStar(input);
}

int main()
{
    char input[100];
    cin.getline(input, 100);
    pairStar(input);
    cout << input << endl;
}
