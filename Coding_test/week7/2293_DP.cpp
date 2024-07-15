/**
 * @file 2293_DP.cpp
 * @brief 00:44:32
 * @date 2024-07-15
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, k;
vector<int> coin;
vector<ll> table;

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> k;
    coin.resize(n);
    table.resize(k + 1, 0);
    for (int i = 0; i < n; i++)
        cin >> coin[i];

    table[0] = 1;
    for (int v = coin[0]; v <= k; v += coin[0])
        table[v] = 1;
    
    for (int i = 1; i < n; i++)
        for (int v = coin[i]; v <= k; v++)
            table[v] += table[v - coin[i]];

    cout << table[k];

    return 0;
}