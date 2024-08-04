/**
 * @file 2206_BFS.cpp
 * @brief 01:09:22
 * @date 2024-08-04
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <bits/stdc++.h>
using namespace std;

#define AVAILABLE   '0'
#define WALL        '1'
#define NONBROKEN   0
#define BROKEN      1
#define INF         100000000

int N, M, res;
int dr[4] = { -1, 0, 1, 0 };
int dc[4] = { 0, -1, 0, 1 };
vector<vector<char>> m;
vector<vector<vector<int>>> dist;
queue<pair<int, pair<int, int>>> q;     // < isBroken, <r, c> > 

inline bool CheckValidPoint(int r, int c) {
    return (0 < r && r <= N && 0 < c && c <= M);
}

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    m.resize(N + 1, vector<char>(M + 1));
    dist.resize(2, vector<vector<int>>(N + 1, vector<int>(M + 1, INF)));
    for (int r = 1; r <= N; r++)
        for (int c = 1; c <= M; c++)
            cin >> m[r][c];

    dist[NONBROKEN][1][1] = 1;
    q.push({ NONBROKEN, { 1, 1 } });
    while (!q.empty()) {
        int broken = q.front().first;
        int r = q.front().second.first, c = q.front().second.second;
        q.pop();

        for (int d = 0; d < 4; d++) {
            int nr = r + dr[d], nc = c + dc[d];

            if (!CheckValidPoint(nr, nc)) continue;
            if (dist[broken][nr][nc] != INF) continue;

            if (m[nr][nc] == AVAILABLE) {
                dist[broken][nr][nc] = dist[broken][r][c] + 1;
                q.push({ broken, { nr, nc } });
            } else if (m[nr][nc] == WALL && !broken) {
                dist[!broken][nr][nc] = dist[broken][r][c] + 1;
                q.push({ !broken, { nr, nc } });
            } 
        }
    }

    res = min(dist[NONBROKEN][N][M], dist[BROKEN][N][M]);
    if (res == INF)
        cout << -1;
    else
        cout << res;

    return 0;
}