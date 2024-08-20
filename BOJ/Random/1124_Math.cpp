#include <bits/stdc++.h>
using namespace std;

int A, B, underPrime;
vector<bool> sieve(100001, true);
vector<int> primes;

inline bool CheckUnderPrime(int n);

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> A >> B;
    sieve[0] = sieve[1] = false;
    for (int i = 2; i <= 100000; i++)
        if (sieve[i]) {
            primes.push_back(i);
            for (int mult = i * 2; mult <= 100000; mult += i)
                sieve[mult] = false;
        }

    for (int i = A; i <= B; i++)
        underPrime += CheckUnderPrime(i);
    
    cout << underPrime;

    return 0;
}

inline bool CheckUnderPrime(int n) {
    int dividor = 0;
    for (int i = 0; i < primes.size() && n != 1; i++) {
        while (n % primes[i] == 0) {
            dividor++;
            n /= primes[i];
        }
    }
    return (sieve[dividor]);
}