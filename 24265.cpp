#include <iostream>
using namespace std;

int main()
{
    long long n;
    cin >> n;

    long long count = 0;
    for (long long i = 1; i <= n - 1; ++i)
    {
        for (long long j = i + 1; j <= n; ++j)
        {
            ++count;
        }
    }
    cout << count << endl;
    cout << 2;

    return 0;
}