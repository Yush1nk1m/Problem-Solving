#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int M, N;
    cin >> M;
    cin >> N;

    vector<bool> primeNumbers(N + 1, true);
    primeNumbers[1] = false;

    int next = 2;
    for (int current = next; current <= N; current = next)
    {
        int multiple = current * 2;
        while (multiple <= N)
        {
            primeNumbers[multiple] = false;
            multiple += current;
        }
        next = current + 1;
        while (primeNumbers[next] != true && next <= N) ++next;
    }

    int minPrimeNumber = M;
    while (!primeNumbers[minPrimeNumber]) ++minPrimeNumber;

    int result = 0;
    for (int i = M; i <= N; i++)
    {
        if (primeNumbers[i]) result += i;
    }
    
    if (!result)
    {
        cout << -1;
    }
    else
    {
        cout << result << endl;
        cout << minPrimeNumber;
    }

    return 0;
}