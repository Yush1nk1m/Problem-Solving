/**
 * @file 11048_DP.cpp
 * @brief 00:07:58
 * @date 2024-07-29
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <bits/stdc++.h>
using namespace std;

#define NONE    -1

int N, M;
vector<vector<int>> maze;
vector<vector<int>> table;

int DFS(int r, int c);

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    maze.resize(N, vector<int>(M));
    table.resize(N, vector<int>(M, NONE));
    for (int r = 0; r < N; r++)
        for (int c = 0; c < M; c++)
            cin >> maze[r][c];

    cout << DFS(0, 0);

    return 0;
}

int DFS(int r, int c) {
    if (r >= N || c >= M)
        return 0;
    if (r == N - 1 && c == M - 1)
        return maze[r][c];

    int& ret = table[r][c];
    if (ret != NONE)
        return ret;

    ret = max(ret, DFS(r + 1, c));
    ret = max(ret, DFS(r, c + 1));
    ret = max(ret, DFS(r + 1, c + 1));
    ret += maze[r][c];

    return ret;
}