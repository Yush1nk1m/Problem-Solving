/**
 * @file 2193_DP.cpp
 * @brief 00:05:10
 * @date 2024-07-29
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define NONE    -1

int N;
vector<vector<ll>> table;

ll DFS(int depth, int last);

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    table.resize(N + 1, vector<ll>(2, NONE));
    cout << DFS(1, 1);

    return 0;
}

ll DFS(int depth, int last) {
    if (depth == N)
        return 1LL;

    ll& ret = table[depth][last];
    if (ret != NONE)
        return ret;

    ret = 0;
    if (last != 1)
        ret += DFS(depth + 1, 1);
    ret += DFS(depth + 1, 0);

    return ret;
}