/**
 * @file 9095_DP.cpp
 * @brief 00:06:19
 * @date 2024-07-30
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <bits/stdc++.h>
using namespace std;

#define NONE    -1

int T, N;
vector<vector<int>> table;

int Solve(int N);
int DFS(int N, vector<int>& table);

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    table.resize(11, vector<int>(11, NONE));

    cin >> T;
    for (int _ = 0; _ < T; _++) {
        cin >> N;
        cout << Solve(N) << '\n';
    }

    return 0;
}

int Solve(int N) {
    return DFS(N, table[N]);
}

int DFS(int N, vector<int>& table) {
    if (N < 0)
        return 0;
    else if (N == 0)
        return 1;

    int& ret = table[N];
    if (ret != NONE)
        return ret;

    ret = 0;
    for (int i = 1; i <= 3; i++)
        ret += DFS(N - i, table);

    return ret;
}