/**
 * @file 11727_DP_BottomUp.cpp
 * @brief 00:02:43
 * @date 2024-07-28
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <bits/stdc++.h>
using namespace std;

#define MOD 10007

int n;
vector<int> table;

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    table.resize(max(n + 1, 3), 0);
    table[1] = 1;
    table[2] = 3;

    for (int i = 3; i <= n; i++)
        table[i] = ((table[i-1] % MOD) + (table[i-2] * 2 % MOD)) % MOD;

    cout << table[n];

    return 0;
}