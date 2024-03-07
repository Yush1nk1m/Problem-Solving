#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long int A, B;
    cin >> A >> B;

    long long int upperbound = sqrtl(B);
    long long int lowerbound = sqrtl(A);

    vector<bool> sieve(upperbound + 1, true);
    vector<long long int> primes;

    for (long long int n = 2; n <= upperbound; n++) {
        if (sieve[n]) {
            for (long long int multiple = n * 2; multiple <= upperbound; multiple += n)
                sieve[multiple] = false;
            primes.push_back(n);
        }
    }

    long long int count = 0;
    for (long long int prime : primes) {
        long long int power = prime;
        
        while (power < (A / static_cast<long double>(prime)))
            power *= prime;
        
        while (power <= (B / static_cast<long double>(prime))) {
            count++;
            power *= prime;
        }
    }

    cout << count;

    return 0;
}