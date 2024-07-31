/**
 * @file 2225_DP.cpp
 * @brief 00:14:20
 * @date 2024-07-31
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define NONE    -1
#define MOD     1000000000

int N, K;
vector<vector<ll>> table;

int DFS(int depth, int sum);

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> K;
    table.resize(K + 1, vector<ll>(N + 1, NONE));

    cout << DFS(0, 0);

    return 0;
}

int DFS(int depth, int sum) {
    if (sum > N)
        return 0;
    if (depth == K) {
        if (sum == N)
            return 1;
        else
            return 0;
    }

    ll& ret = table[depth][sum];
    if (ret != NONE)
        return ret;

    ret = 0;
    for (int n = 0; n <= N; n++) {
        ret += DFS(depth + 1, sum + n);
        ret %= MOD;
    }
    
    return ret;
}