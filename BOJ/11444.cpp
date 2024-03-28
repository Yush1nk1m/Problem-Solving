#include <iostream>
#include <unordered_map>
using namespace std;

#define MOD 1000000007ULL

static unordered_map<unsigned long long int, unsigned long long int> fibonacciMap;

unsigned long long int dOcagne(unsigned long long int);

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    fibonacciMap[0] = 0;
    fibonacciMap[1] = fibonacciMap[2] = 1;

    unsigned long long int n;
    cin >> n;

    cout << dOcagne(n);

    return 0;
}

unsigned long long int dOcagne(unsigned long long int n) {
    if (fibonacciMap.find(n) != fibonacciMap.end())
        return fibonacciMap[n];

    if (n % 2 == 0) {
        fibonacciMap[n] = ((dOcagne(n / 2) % MOD) * (dOcagne(n / 2 - 1) % MOD + dOcagne(n / 2 + 1) % MOD)) % MOD;
    }
    else {
        fibonacciMap[n] = (((dOcagne(n / 2) % MOD) * (dOcagne(n / 2) % MOD) % MOD) + ((dOcagne(n / 2 + 1) % MOD) * (dOcagne(n / 2 + 1) % MOD) % MOD)) % MOD;
    }

    return fibonacciMap[n];
}