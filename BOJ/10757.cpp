#include <iostream>
#include <string>
using namespace std;

int main()
{
    string A, B;
    string result("");
    cin >> A;
    cin >> B;

    int cursorA = A.length() - 1;
    int cursorB = B.length() - 1;
    char carry = 0;

    while (cursorA >= 0 && cursorB >= 0)
    {
        char temp = A[cursorA] + B[cursorB] + carry - 48;
        if (temp > 57)
        {
            temp -= 10;
            carry = 1;
        }
        else
        {
            carry = 0;
        }
        result = temp + result;
        --cursorA;
        --cursorB;
    }
    
    while (cursorA >= 0)
    {
        char temp = A[cursorA] + carry;
        if (temp <= 57)
        {
            carry = 0;
        }
        else
        {
            carry = 1;
            temp -= 10;
        }
        result = temp + result;
        --cursorA;
    }
    while (cursorB >= 0)
    {
        char temp = B[cursorB] + carry;
        if (temp <= 57)
        {
            carry = 0;
        }
        else
        {
            carry = 1;
            temp -= 10;
        }
        result = temp + result;
        --cursorB;
    }
    if (carry == 1)
    {
        result = "1" + result;
    }

    cout << result;

    return 0;
}