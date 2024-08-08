/**
 * @file 17271_DP.cpp
 * @brief 00:09:06
 * @date 2024-08-08
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define SKILLA  1
#define SKILLB  2
#define NONE    -1

#define MOD 1000000007

int N, B;
vector<vector<ll>> table;

ll DFS(int second, int prior);

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> B;
    table.resize(N, vector<ll>(3, NONE));
    cout << DFS(0, 0);

    return 0;
}

ll DFS(int second, int prior) {
    if (second > N)
        return 0;
    else if (second == N)
        return 1;

    ll& ret = table[second][prior];
    if (ret != NONE)
        return ret;

    ret = 0;
    ret += DFS(second + 1, SKILLA);
    ret %= MOD;
    ret += DFS(second + B, SKILLB);
    ret %= MOD;

    return ret;
}