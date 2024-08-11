/**
 * @file 25513_BFS.cpp
 * @brief 00:51:44
 * @date 2024-08-11
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <bits/stdc++.h>
using namespace std;

#define NONE    -1

int r, c, r6, c6;
int dr[4] = { -1, 0, 1, 0 };
int dc[4] = { 0, -1, 0, 1 };
vector<vector<int>> board(5, vector<int>(5));
vector<vector<vector<int>>> visited(7, vector<vector<int>>(5, vector<int>(5, NONE)));
queue<tuple<int, int, int>> q;

inline bool CheckValidPoint(int r, int c) {
    return (0 <= r && r < 5 && 0 <= c && c < 5);
}

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for (int r = 0; r < 5; r++)
        for (int c = 0; c < 5; c++) {
            cin >> board[r][c];
            if (board[r][c] == 6) {
                r6 = r;
                c6 = c;
            }
        }

    cin >> r >> c;

    visited[0][r][c] = 0;
    q.push(make_tuple(0, r, c));
    while (!q.empty()) {
        tuple<int, int, int> curr = q.front();
        q.pop();

        int maxn = get<0>(curr), cr = get<1>(curr), cc = get<2>(curr);
        int dist = visited[maxn][cr][cc];

        for (int d = 0; d < 4; d++) {
            int nr = cr + dr[d], nc = cc + dc[d], nextn = maxn;
            if (!CheckValidPoint(nr, nc) || board[nr][nc] == -1) continue;
            
            if (board[nr][nc] == maxn + 1)
                nextn++;

            if (visited[nextn][nr][nc] == NONE) {
                visited[nextn][nr][nc] = dist + 1;
                q.push(make_tuple(nextn, nr, nc));
            }
        }
    }

    if (visited[6][r6][c6] != NONE)
        cout << visited[6][r6][c6];
    else
        cout << -1;

    return 0;
}