#include <iostream>
using namespace std;

void reverse(int& n)
{
    // Assume that it consists of 3 digits
    int mul = 100, temp = 0;
    while (n > 0)
    {
        temp += (n % 10) * mul;
        mul /= 10;
        n /= 10;
    }
    n = temp;
}

int main()
{
    int first, second;
    cin >> first;
    cin >> second;

    reverse(first);
    reverse(second);

    if (first > second)
    {
        cout << first;
    }
    else
    {
        cout << second;
    }

    return 0;
}