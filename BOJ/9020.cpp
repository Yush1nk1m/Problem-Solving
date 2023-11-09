#include <iostream>
#include <vector>
#include <limits>
using namespace std;

int main()
{
    vector<bool> sieve(10000 + 1, true);
    sieve[1] = false;

    int next = 2;
    for (int current = next; current <= 10000; current = next)
    {
        int multiple = current * 2;
        while (multiple <= 10000)
        {
            sieve[multiple] = false;
            multiple += current;
        }
        next = current + 1;
        while (sieve[next] != true && next <= 10000) ++next;
    }

    int T;
    cin >> T;

    for (int _ = 0; _ < T; _++)
    {
        int n;
        cin >> n;
        int minFirst, minSecond, minDifference;
        minFirst = minSecond = minDifference = numeric_limits<int>::max();
        
        for (int i = 2; i <= n / 2; i++)
        {
            if (sieve[i] && sieve[n - i] && (n - 2 * i) < minDifference)
            {
                minFirst = i;
                minSecond = n - i;
            }
        }
        
        cout << minFirst << " " << minSecond << endl;
    }

    return 0;
}