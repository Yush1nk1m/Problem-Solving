/**
 * @file 2670_DP.cpp
 * @brief 00:12:25
 * @date 2024-07-14
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;

int N;
vector<ld> seq;

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    seq.resize(N);
    for (int i = 0; i < N; i++)
        cin >> seq[i];

    for (int i = 1; i < N; i++)
        seq[i] = max(seq[i], seq[i-1] * seq[i]);

    cout << fixed << setprecision(3) << *max_element(seq.begin(), seq.end());

    return 0;
}