/**
 * @file 2293_DP.cpp
 * @brief 00:22:15
 * @date 2024-07-31
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <bits/stdc++.h>
using namespace std;

int n, k;
vector<int> coin;
vector<int> table;

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> k;
    
    coin.resize(n);
    for (int i = 0; i < n; i++)
        cin >> coin[i];
    sort(coin.begin(), coin.end());

    table.resize(k + 1, 0);
    table[0] = 1;
    for (int v = coin[0]; v <= k; v += coin[0])
        table[v] = 1;

    for (int i = 1; i < n; i++)
        for (int v = coin[i]; v <= k; v++)
            table[v] += table[v-coin[i]];

    cout << table[k];

    return 0;
}