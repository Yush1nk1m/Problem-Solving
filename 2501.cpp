#include <iostream>
using namespace std;

int main()
{
    int N, K, count = 0, divisor = 1;
    cin >> N; cin >> K;

    while (divisor <= N)
    {
        if (N % divisor == 0)
        {
            ++count;
        }
        if (count == K)
        {
            cout << divisor;
            return 0;
        }
        ++divisor;
    }
    cout << 0;
    return 0;
}