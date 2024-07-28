/**
 * @file 11727_DP.cpp
 * @brief 00:09:21
 * @date 2024-07-28
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <bits/stdc++.h>
using namespace std;

#define MOD 10007

int n;
vector<int> table;

int DFS(int depth);

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    table.resize(n + 1, 0);

    table[2] = 3;
    cout << DFS(n);

    return 0;
}

int DFS(int depth) {
    if (depth <= 1)
        return depth;

    int& ret = table[depth];
    if (ret)
        return ret;

    ret = ((DFS(depth - 1) % MOD) + ((DFS(depth - 2) * 2) % MOD)) % MOD;
    return ret;
}