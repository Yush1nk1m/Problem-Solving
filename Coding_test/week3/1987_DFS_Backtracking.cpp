/**
 * @file 1987_DFS_Backtracking.cpp
 * @brief 00:14:06
 * @date 2024-06-30
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <bits/stdc++.h>
using namespace std;

int R, C, maxDepth;
int dr[4] = { 0, 0, -1, 1 };
int dc[4] = { -1, 1, 0, 0 };
bool visited[26];
vector<vector<char>> board;

inline bool isValidPoint(int r, int c);
void DFS(int r, int c, int depth);

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> R >> C;
    board.resize(R, vector<char>(C));
    for (int r = 0; r < R; r++)
        for (int c = 0; c < C; c++)
            cin >> board[r][c];
    
    visited[board[0][0] - 'A'] = true;
    DFS(0, 0, 1);
    cout << maxDepth;

    return 0;
}

inline bool isValidPoint(int r, int c) {
    return (0 <= r && r < R && 0 <= c && c < C);
}

void DFS(int r, int c, int depth) {
    bool isPathExist = false;

    for (int d = 0; d < 4; d++) {
        int nr = r + dr[d], nc = c + dc[d];
        if (!isValidPoint(nr, nc) || visited[board[nr][nc] - 'A']) continue;
        isPathExist = true;

        visited[board[nr][nc] - 'A'] = true;
        DFS(nr, nc, depth + 1);
        visited[board[nr][nc] - 'A'] = false;
    }

    if (!isPathExist)
        maxDepth = max(maxDepth, depth);
}