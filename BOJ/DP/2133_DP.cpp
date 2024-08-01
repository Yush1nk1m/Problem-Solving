/**
 * @file 2133_DP.cpp
 * @brief 00:04:31
 * @date 2024-08-01
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int N;
vector<ll> table;

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    table.resize(N + 1, 0);
    table[0] = 1;

    for (int curr = 2; curr <= N; curr += 2) {
        if (curr - 2 >= 0)
            table[curr] += table[curr - 2] * 3;
        for (int prv = 4; prv <= N; prv += 2)
            table[curr] += table[curr - prv] * 2;
    }

    cout << table[N];

    return 0;
}