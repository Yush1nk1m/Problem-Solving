/**
 * @file 1189_Backtracking.cpp
 * @brief 00:12:39
 * @date 2024-06-30
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <bits/stdc++.h>
using namespace std;

int R, C, K, cnt;
int dr[4] = { 0, 0, -1, 1 };
int dc[4] = { -1, 1, 0, 0 };
vector<vector<bool>> visited;

inline bool isValidPoint(int r, int c);
void DFS(int distance, int r, int c);

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> R >> C >> K;
    visited.resize(R, vector<bool>(C, false));
    for (int r = 0; r < R; r++)
        for (int c = 0; c < C; c++) {
            char p;
            cin >> p;
            if (p == 'T') visited[r][c] = true;
        }

    visited[R-1][0] = true;
    DFS(1, R-1, 0);
    cout << cnt;

    return 0;
}

inline bool isValidPoint(int r, int c) {
    return (0 <= r && r < R && 0 <= c && c < C);
}

void DFS(int distance, int r, int c) {
    if (distance == K) {
        if (r == 0 && c == C - 1) cnt++;
        return;
    }

    for (int d = 0; d < 4; d++) {
        int nr = r + dr[d], nc = c + dc[d];
        if (!isValidPoint(nr, nc) || visited[nr][nc]) continue;

        visited[nr][nc] = true;
        DFS(distance + 1, nr, nc);
        visited[nr][nc] = false;
    }
}