/**
 * @file 15990_DP.cpp
 * @brief 00:11:03
 * @date 2024-09-02
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define NONE    -1
#define MOD     1000000009

int T, N;
vector<vector<ll>> table;

int DFS(int number, int prior);

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    table.resize(100001, vector<ll>(4, NONE));
    
    cin >> T;
    while (T--) {
        cin >> N;
        cout << DFS(N, 0) << '\n';
    }

    return 0;
}

int DFS(int number, int prior) {
    if (number == 0)
        return 1;
    else if (number < 0)
        return 0;

    ll& ret = table[number][prior];
    if (ret != NONE)
        return ret;

    ret = 0;
    for (ll i = 1; i <= 3; i++)
        if (i != prior) {
            ret += DFS(number - i, i);
            ret %= MOD;
        }

    return ret;
}