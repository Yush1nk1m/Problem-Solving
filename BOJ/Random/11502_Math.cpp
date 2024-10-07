/**
 * @file 11502_Math.cpp
 * @brief 00:09:22
 * @date 2024-10-07
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <bits/stdc++.h>
using namespace std;

int T, K;
bool found;
vector<bool> sieve(1001, true);
vector<int> primes, result;

void dfs(int idx, int selected, int curr);

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for (int n = 2; n <= 1000; n++)
        if (sieve[n]) {
            primes.push_back(n);
            for (int multi = n * 2; multi <= 1000; multi += n)
                sieve[multi] = false;
        }

    cin >> T;
    while (T--) {
        cin >> K;
        found = false;
        dfs(0, 0, K);
    }

    return 0;
}

void dfs(int idx, int selected, int curr) {
    if (selected == 3) {
        if (curr == 0) {
            sort(result.begin(), result.end());
            for (int number : result)
                cout << number << ' ';
            cout << '\n';
            found = true;
        }
        return;
    } else if (idx == primes.size() || curr < 0 || found) {
        return;
    }

    for (int i = idx; i < primes.size(); i++) {
        int prime = primes[i];
        result.push_back(prime);
        dfs(i, selected + 1, curr - prime);
        result.pop_back();
    }
}