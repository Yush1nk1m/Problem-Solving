/**
 * @file 2294_DP.cpp
 * @brief 00:12:32
 * @date 2024-07-30
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <bits/stdc++.h>
using namespace std;

#define INF 100000000

int n, k;
set<int> coin;
vector<int> table;
vector<bool> visited;

int DFS(int value);

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> k;
    table.resize(k, INF);
    visited.resize(k, false);
    for (int i = 0; i < n; i++) {
        int v;
        cin >> v;
        coin.insert(v);
    }

    int res = DFS(0);
    if (res == INF)
        cout << -1;
    else
        cout << res;

    return 0;
}

int DFS(int value) {
    if (value > k)
        return INF;
    if (value == k)
        return 0;

    int& ret = table[value];

    if (visited[value])
        return ret;
    visited[value] = true;

    for (auto it = coin.rbegin(); it != coin.rend(); it++)
        ret = min(ret, DFS(value + *it) + 1);

    return ret;
}