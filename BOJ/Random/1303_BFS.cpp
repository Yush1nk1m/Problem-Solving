/**
 * @file 1303_BFS.cpp
 * @brief 00:12:11
 * @date 2024-09-17
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <bits/stdc++.h>
using namespace std;

#define WHITE   'W'
#define BLUE    'B'

int N, M;
int dr[4] = { -1, 0, 1, 0 };
int dc[4] = { 0, -1, 0, 1 };
vector<vector<char>> field;
vector<vector<bool>> visited;
queue<pair<int, int>> q;
map<char, int> m;

inline bool isValidPoint(int r, int c) {
    return (0 <= r && r < M && 0 <= c && c < N);
}

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    m[WHITE] = 0;
    m[BLUE] = 0;

    cin >> N >> M;
    field.resize(M, vector<char>(N));
    for (int r = 0; r < M; r++)
        for (int c = 0; c < N; c++)
            cin >> field[r][c];

    visited.resize(M, vector<bool>(N, false));
    for (int r = 0; r < M; r++)
        for (int c = 0; c < N; c++)
            if (!visited[r][c]) {
                int power = 1;
                visited[r][c] = true;
                q.push({ r, c });

                while (!q.empty()) {
                    pair<int, int> curr = q.front();
                    q.pop();

                    for (int d = 0; d < 4; d++) {
                        int nr = curr.first + dr[d], nc = curr.second + dc[d];
                        if (!isValidPoint(nr, nc) || visited[nr][nc] || field[nr][nc] != field[r][c]) continue;

                        power++;
                        visited[nr][nc] = true;
                        q.push({ nr, nc });
                    }
                }

                m[field[r][c]] += pow(power, 2);
            }

    cout << m[WHITE] << ' ' << m[BLUE];

    return 0;
}