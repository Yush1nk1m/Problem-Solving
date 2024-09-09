/**
 * @file 6588_Math.cpp
 * @brief 00:13:42
 * @date 2024-09-09
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> oddPrimes;
vector<bool> sieve(1000000, true);

inline void generateOddPrimes();
inline void validate(int number);

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    generateOddPrimes();

    while (1) {
        cin >> n;
        if (n == 0) break;
        validate(n);
    }

    return 0;
}

inline void generateOddPrimes() {    
    for (int n = 2; n < 1000000; n++)
        if (sieve[n]) {
            oddPrimes.push_back(n);
            for (int mult = n * 2; mult < 1000000; mult += n)
                sieve[mult] = false;
        }
}

inline void validate(int number) {
    for (int prime : oddPrimes)
        if (sieve[number - prime]) {
            cout << number << " = " << prime << " + " << number - prime << '\n';
            return;
        }
}