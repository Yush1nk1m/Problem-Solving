/**
 * @file 2747_DP.cpp
 * @brief 00:01:33
 * @date 2024-07-28
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;
vector<ll> table;

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    table.resize(n + 1);
    table[0] = 0;
    table[1] = 1;
    for (int i = 2; i <= n; i++)
        table[i] = table[i-1] + table[i-2];

    cout << table[n];

    return 0;
}