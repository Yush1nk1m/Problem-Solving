#include <bits/stdc++.h>
using namespace std;

#define LIMIT   246913

int n;
vector<bool> sieve(LIMIT, true);
vector<int> primes;

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for (int n = 2; n < LIMIT; n++)
        if (sieve[n]) {
            primes.push_back(n);
            for (int mult = n * 2; mult < LIMIT; mult += n)
                sieve[mult] = false;
        }

    while (cin >> n) {
        if (n == 0)
            break;
        cout << upper_bound(primes.begin(), primes.end(), n * 2) - lower_bound(primes.begin(), primes.end(), n + 1) << '\n';    
    }


    return 0;
}