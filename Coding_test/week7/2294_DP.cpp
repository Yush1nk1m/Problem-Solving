/**
 * @file 2294_DP.cpp
 * @brief 00:59:41
 * @date 2024-07-15
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <bits/stdc++.h>
using namespace std;

#define INF 100000000

int n, k, cnt;
vector<int> coin;
vector<vector<int>> table;

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> k;
    coin.resize(n + 1, 0);
    table.resize(n + 1, vector<int>(k + 1, INF));

    for (int i = 0; i <= k; i++)
        table[0][i] = INF;
    for (int i = 0; i <= n; i++)
        table[i][0] = 0;

    for (int i = 1; i <= n; i++)
        cin >> coin[i];
    sort(coin.begin(), coin.end());

    for (int c = 1; c <= n; c++)
        for (int v = 1; v <= k; v++) {
            if (coin[c] > v)
                table[c][v] = table[c-1][v];
            else
                table[c][v] = min(table[c][v - coin[c]] + 1, table[c-1][v]);
        }

    if (table[n][k] == INF)
        cout << -1;
    else
        cout << table[n][k];

    return 0;
}