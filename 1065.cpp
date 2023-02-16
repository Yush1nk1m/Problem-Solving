#include <iostream>
using namespace std;

bool isSequence(int n)
{
    if (n < 100) return true;
    else
    {
        int cur = n % 10;
        n /= 10;
        int diff = cur - (n % 10);
        
        while (n >= 10)
        {
            cur = n % 10;
            n /= 10;
            if (diff != cur - (n % 10)) return false;
        }
        return true;
    }
}

int main()
{
    int count = 0, N;
    cin >> N;

    for (int i = 1; i <= N; i++)
    {
        if (isSequence(i)) count++;
    }

    cout << count;

    return 0;
}