#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int N;
    cin >> N;

    vector<bool> sieve(N + 1, true);
    sieve[1] = false;

    int next = 2;
    for (int current = next; current <= N; current = next)
    {
        int multiple = current * 2;
        while (multiple <= N)
        {
            sieve[multiple] = false;
            multiple += current;
        }
        next = current + 1;
        while (sieve[next] != true && next <= N) ++next;
    }

    vector<int> primeNumbers;
    for (int i = 2; i <= N; i++)
    {
        if (sieve[i]) primeNumbers.push_back(i);
    }

    while (N > 1)
    {
        for (int i = 2; i <= N; i++)
        {
            if (N % i == 0)
            {
                cout << i << endl;
                N /= i;
                break;
            }
        }
    }

    return 0;
}