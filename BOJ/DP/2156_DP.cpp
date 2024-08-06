/**
 * @file 2156_DP.cpp
 * @brief 00:08:45
 * @date 2024-08-06
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <bits/stdc++.h>
using namespace std;

#define NONE    -1

int n;
vector<vector<int>> table;
vector<int> glass;

int DFS(int i, int seq);

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    glass.resize(n);
    for (int i = 0; i < n; i++)
        cin >> glass[i];

    table.resize(n, vector<int>(3, NONE));
    cout << DFS(0, 1);

    return 0;
}

int DFS(int i, int seq) {
    if (seq == 3 || i >= n)
        return 0;

    int& ret = table[i][seq];
    if (ret != NONE)
        return ret;

    ret = glass[i];
    ret += max(DFS(i + 1, seq + 1), DFS(i + 2, 1));
    ret = max(ret, DFS(i + 1, 1));

    return ret;
}