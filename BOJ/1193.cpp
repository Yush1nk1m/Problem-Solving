#include <iostream>
using namespace std;

int main()
{
    int X;
    cin >> X;

    int numer = 1, denom = 1;
    bool upperDirection = true;
    for (int count = 1; count < X; count++)
    {
        if (upperDirection == true)
        {
            numer--;
            denom++;
        }
        else
        {
            numer++;
            denom--;
        }

        if (numer == 0)
        {
            upperDirection = !upperDirection;
            numer++;
        }
        else if (denom == 0)
        {
            upperDirection = !upperDirection;
            denom++;
        }
    }

    cout << numer << "/" << denom;

    return 0;
}