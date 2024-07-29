/**
 * @file 1520_DP.cpp
 * @brief 00:08:57
 * @date 2024-07-29
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <bits/stdc++.h>
using namespace std;

#define NONE    -1

int M, N;
int dr[4] = { 0, -1, 0, 1 };
int dc[4] = { -1, 0, 1, 0 };
vector<vector<int>> height;
vector<vector<int>> table;

inline bool CheckValidPoint(int r, int c);
int DFS(int r, int c);

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> M >> N;
    table.resize(M, vector<int>(N, NONE));
    height.resize(M, vector<int>(N));
    for (int r = 0; r < M; r++)
        for (int c = 0; c < N; c++)
            cin >> height[r][c];

    cout << DFS(0, 0);

    return 0;
}

inline bool CheckValidPoint(int r, int c) {
    return (0 <= r && r < M && 0 <= c && c < N);
}

int DFS(int r, int c) {
    if (r == M - 1 && c == N - 1)
        return 1;

    int& ret = table[r][c];
    if (ret != NONE)
        return ret;

    ret = 0;
    for (int d = 0; d < 4; d++) {
        int nr = r + dr[d], nc = c + dc[d];
        if (CheckValidPoint(nr, nc) && height[nr][nc] < height[r][c])
            ret += DFS(nr, nc);
    }

    return ret;
}