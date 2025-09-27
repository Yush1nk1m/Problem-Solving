/**
 * @file 3474_Math.cpp
 * @brief 00:33:05
 * @date 2024-06-27
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <bits/stdc++.h>
using namespace std;

int T, N;

inline unsigned long long int FindZeros(unsigned long long int number);

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> T;
    for (int _ = 0; _ < T; _++) {
        unsigned long long int number;
        cin >> number;
        cout << FindZeros(number) << '\n';
    }
    
    return 0;
}

inline unsigned long long int FindZeros(unsigned long long int number) {
    unsigned long long int cnt = 0;

    for (unsigned long long int power = 5; power <= number; power *= 5)
        cnt += (number / power);
    
    return cnt;
}