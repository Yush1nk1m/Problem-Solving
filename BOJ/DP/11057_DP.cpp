/**
 * @file 11057_DP.cpp
 * @brief 00:08:56
 * @date 2024-07-29
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <bits/stdc++.h>
using namespace std;

#define MOD 10007

int N;
vector<vector<int>> table;

int DFS(int depth, int last);

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    table.resize(N + 1, vector<int>(10, 0));
    cout << DFS(0, 1) + 1;

    return 0;
}

int DFS(int depth, int last) {
    if (depth == N)
        return 0;

    int& ret = table[depth][last];
    if (ret)
        return ret;

    for (int i = last; i <= 9; i++) {
        ret += DFS(depth + 1, i) + 1;
        ret %= MOD;
    }

    return ret;
}