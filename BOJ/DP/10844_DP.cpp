/**
 * @file 10844_DP.cpp
 * @brief 00:08:44
 * @date 2024-07-29
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define MOD 1000000000

int N;
vector<vector<ll>> table;

ll DFS(int depth, int last);

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    table.resize(N + 1, vector<ll>(10, 0));

    ll result = 0;
    for (int i = 1; i <= 9; i++) {
        result += DFS(1, i);
        result %= MOD;
    }
    cout << result;

    return 0;
}

ll DFS(int depth, int last) {
    if (depth == N)
        return 1;
    
    ll& ret = table[depth][last];
    if (ret)
        return ret;

    if (last > 0) {
        ret += DFS(depth + 1, last - 1);
        ret %= MOD;
    }
    if (last < 9) {
        ret += DFS(depth + 1, last + 1);
        ret %= MOD;
    }

    return ret;
}