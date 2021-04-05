/*
    ---------------------------------------------------------------------------
    Replace pi (recursive)
    ---------------------------------------------------------------------------
    Send Feedback
    ---------------------------------------------------------------------------
    Given a string, compute recursively a new string where all appearances of "pi" have been replaced by "3.14".
    ---------------------------------------------------------------------------
    Sample Input 1 :
    xpix
    ---------------------------------------------------------------------------
    Sample Output :
    x3.14x
    ---------------------------------------------------------------------------
    Sample Input 2 :
    pipi
    ---------------------------------------------------------------------------
    Sample Output :
    3.143.14
    ---------------------------------------------------------------------------
    Sample Input 3 :
    pip
    ---------------------------------------------------------------------------
    Sample Output :
    3.14p
    ---------------------------------------------------------------------------
*/

#include <iostream>
using namespace std;

int findLength(char input[])
{
    int l = 0;
    while (input[l])
        l++;
    return l;
}

void replacePi(char input[])
{
    static int i = -1;

    i++;

    if (input[i + 1] == 0)
        return;

    if (input[i] == 'p' and input[i + 1] == 'i')
    {
        int length = findLength(input);

        for (int j = length; j >= i + 2; j--)
            input[j + 2] = input[j];

        input[i] = '3';
        input[i + 1] = '.';
        input[i + 2] = '1';
        input[i + 3] = '4';

        i += 3;
    }
    replacePi(input);
}

int main()
{
    char input[10000];
    cin.getline(input, 10000);
    replacePi(input);
    cout << input << endl;
}
