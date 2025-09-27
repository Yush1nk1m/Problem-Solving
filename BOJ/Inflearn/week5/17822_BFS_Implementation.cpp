/**
 * @file 17822_BFS_Implementation.cpp
 * @brief 00:50:00
 * @date 2024-07-09
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <bits/stdc++.h>
using namespace std;

#define NONE    0

int N, M, T, x, d, k;
int dr[4] = { -1, 0, 1, 0 };
int dc[4] = { 0, -1, 0, 1 };
vector<vector<int>> table;
vector<vector<bool>> visited;

inline void Rotate(int x, int d, int k);
inline bool RemoveAdjacent();
inline void Averaging();
inline int Sum();

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M >> T;
    table.resize(N + 1, vector<int>(M, 0));
    visited.resize(N + 1, vector<bool>(M));
    for (int r = 1; r <= N; r++)
        for (int i = 0; i < M; i++)
            cin >> table[r][i];
    
    for (int _ = 0; _ < T; _++) {
        cin >> x >> d >> k;
        Rotate(x, d, k);
        if (!RemoveAdjacent())
            Averaging();
    }

    cout << Sum();

    return 0;
}

inline void Rotate(int x, int d, int k) {
    for (int r = x; r <= N; r += x) {
        if (d)
            rotate(table[r].begin(), table[r].begin() + k, table[r].end());
        else
            rotate(table[r].rbegin(), table[r].rbegin() + k, table[r].rend());
    }
}

inline bool RemoveAdjacent() {
    fill(visited.begin(), visited.end(), vector<bool>(M, false));

    for (int r = 1; r <= N; r++)
        for (int i = 0; i < M; i++)
            if (!visited[r][i] && table[r][i] != NONE) {
                queue<pair<int, int>> q;

                q.push({ r, i });
                while (!q.empty()) {
                    int cr, cc;
                    tie(cr, cc) = q.front();
                    q.pop();

                    for (int d = 0; d < 4; d++) {
                        int nr = cr + dr[d], nc = (cc + dc[d] + M) % M;
                        if (nr <= 0 || nr > N || visited[nr][nc] || table[nr][nc] != table[cr][cc]) continue;
                        visited[nr][nc] = true;
                        q.push({ nr, nc });
                    }
                }
            }
    
    bool removed = false;
    for (int r = 1; r <= N; r++)
        for (int i = 0; i < M; i++)
            if (visited[r][i]) {
                removed = true;
                table[r][i] = NONE;
            }

    return removed;
}

inline void Averaging() {
    int tot = 0, cnt = 0;

    for (int r = 1; r <= N; r++)
        for (int i = 0; i < M; i++)
            if (table[r][i] != NONE) {
                cnt++;
                tot += table[r][i];
            }
    
    double avg = (double)tot / (double)cnt;
    for (int r = 1; r <= N; r++)
        for (int i = 0; i < M; i++) {
            if (table[r][i] != NONE && (double)table[r][i] > avg)
                table[r][i]--;
            else if (table[r][i] != NONE && (double)table[r][i] < avg)
                table[r][i]++;
        }
}

inline int Sum() {
    int sum = 0;
    for (int r = 1; r <= N; r++)
        for (int i = 0; i < M; i++)
            sum += table[r][i];
    return sum;
}