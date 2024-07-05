/**
 * @file 1644_TwoPointer.cpp
 * @brief 00:15:00
 * @date 2024-07-05
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll sum, cnt;
int N, l, r;
vector<int> primes;
vector<bool> sieve;

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    sieve.resize(N + 1, false);
    for (int n = 2; n <= N; n++)
        if (!sieve[n]) {
            primes.push_back(n);
            sieve[n] = true;
            for (int m = n * 2; m <= N; m += n)
                sieve[m] = true;
        }
    
    while (l <= r && r < primes.size()) {
        if (sum < N) {
            sum += primes[r++];
        } else if (sum > N) {
            sum -= primes[l++];
        } else {
            cnt++;
            sum -= primes[l++];
        }
    }
    cnt += (primes.size() && N == primes[primes.size() - 1]);

    cout << cnt;

    return 0;
}