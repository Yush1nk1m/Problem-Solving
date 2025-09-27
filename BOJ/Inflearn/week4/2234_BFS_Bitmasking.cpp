/**
 * @file 2234_BFS_Bitmasking.cpp
 * @brief 00:45:46
 * @date 2024-07-02
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <bits/stdc++.h>
using namespace std;

#define WEST 0
#define NORTH 1
#define EAST 2
#define SOUTH 3

int N, M, nRoom, maxArea, maxDestructiveArea;
int mask[4] = { 1, 2, 4, 8 };
int dr[4] = { 0, -1, 0, 1 };
int dc[4] = { -1, 0, 1, 0 };
vector<vector<int>> castle;
vector<tuple<int, int, int>> walls;

inline void BFS();
inline void AppendWalls();
inline void DestructiveBFS();

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    castle.resize(M, vector<int>(N));
    for (int r = 0; r < M; r++)
        for (int c = 0; c < N; c++)
            cin >> castle[r][c];

    BFS();
    AppendWalls();
    DestructiveBFS();

    cout << nRoom << '\n';
    cout << maxArea << '\n';
    cout << maxDestructiveArea << '\n';

    return 0;
}

inline void BFS() {
    vector<vector<bool>> visited(M, vector<bool>(N, false));

    for (int r = 0; r < M; r++)
        for (int c = 0; c < N; c++)
            if (!visited[r][c]) {
                nRoom++;

                int area = 0;
                queue<pair<int, int>> q;

                q.push({ r, c });
                visited[r][c] = true;
                area++;
                while (!q.empty()) {
                    int cr, cc;
                    tie(cr, cc) = q.front();
                    q.pop();

                    for (int d : { WEST, NORTH, EAST, SOUTH }) {
                        if (mask[d] & castle[cr][cc]) continue;
                        
                        int nr = cr + dr[d], nc = cc + dc[d];
                        if (visited[nr][nc]) continue;
                        
                        q.push({ nr, nc });
                        visited[nr][nc] = true;
                        area++;
                    }
                }

                maxArea = max(maxArea, area);
            }
}

inline void AppendWalls() {
    for (int r = 0; r < M; r++)
        for (int c = 0; c < N; c++) {
            if (c < N - 1 && (castle[r][c] & mask[EAST]))
                walls.push_back(make_tuple(r, c, EAST));
            if (r < M - 1 && castle[r][c] & mask[SOUTH])
                walls.push_back(make_tuple(r, c, SOUTH));
        }
}

inline void DestructiveBFS() {
    vector<vector<int>> copyMap;
    vector<vector<bool>> visited(M, vector<bool>(N));

    for (tuple<int, int, int>& t : walls) {
        int tr = get<0>(t), tc = get<1>(t), wall = get<2>(t);

        copyMap = castle;
        copyMap[tr][tc] ^= mask[wall];
        fill(visited.begin(), visited.end(), vector<bool>(N, false));

        for (int r = 0; r < M; r++)
            for (int c = 0; c < N; c++)
                if (!visited[r][c]) {
                    int area = 0;
                    queue<pair<int, int>> q;
                    
                    q.push({ r, c });
                    visited[r][c] = true;
                    area++;
                    while (!q.empty()) {
                        int cr, cc;
                        tie(cr, cc) = q.front();
                        q.pop();

                        for (int d : { WEST, NORTH, EAST, SOUTH }) {
                            if (copyMap[cr][cc] & mask[d]) continue;
                            
                            int nr = cr + dr[d], nc = cc + dc[d];
                            if (visited[nr][nc]) continue;

                            q.push({ nr, nc });
                            visited[nr][nc] = true;
                            area++;
                        }
                    }

                    maxDestructiveArea = max(maxDestructiveArea, area);
                }
    }
}