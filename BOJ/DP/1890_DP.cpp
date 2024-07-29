/**
 * @file 1890_DP.cpp
 * @brief 00:08:41
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
vector<vector<int>> board;
vector<vector<ll>> table;

ll DFS(int r, int c);

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    table.resize(N, vector<ll>(N, NONE));
    board.resize(N, vector<int>(N));
    for (int r = 0; r < N; r++)
        for (int c = 0; c < N; c++)
            cin >> board[r][c];

    cout << DFS(0, 0);

    return 0;
}

ll DFS(int r, int c) {
    if (r >= N || c >= N)
        return 0;
    if (r == N - 1 && c == N - 1)
        return 1;

    ll& ret = table[r][c];
    if (ret != NONE)
        return ret;

    ret = 0;
    int jmp = board[r][c];
    ret += DFS(r + jmp, c);
    ret += DFS(r, c + jmp);

    return ret;
}