/**
 * @file 4781_DP.cpp
 * @brief 00:13:06
 * @date 2024-07-15
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<pair<int, int>> candy;

inline int DP(int n, int m);

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    while (1) {
        double temp;
        cin >> n >> temp;
        m = temp * 100;

        if (!n && !m) break;

        cout << DP(n, m) << '\n';
    }

    return 0;
}

inline int DP(int n, int m) {
    vector<vector<int>> table(n + 1, vector<int>(m + 1, 0));
    vector<pair<int, int>> candy;
    candy.resize(n + 1, { 0, 0 });
    for (int i = 1; i <= n; i++) {
        double temp;
        cin >> candy[i].second >> temp;
        candy[i].first = (int)(temp * 100 + 0.5);
    }
    sort(candy.begin(), candy.end());

    for (int c = 1; c <= n; c++) {
        for (int price = 1; price < candy[c].first; price++)
            table[c][price] = table[c-1][price];

        for (int price = candy[c].first; price <= m; price++)
            table[c][price] = max(table[c-1][price], table[c][price - candy[c].first] + candy[c].second);
    }

    return table[n][m];
}