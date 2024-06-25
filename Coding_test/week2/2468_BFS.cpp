/**
 * @file 2468_BFS.cpp
 * @brief 00:12:40
 * @date 2024-06-25
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include <bits/stdc++.h>
using namespace std;

int N, maxh;
int dr[4] = { 0, 0, 1, -1 };
int dc[4] = { 1, -1, 0, 0 };
vector<vector<int>> area;
set<int> heights;

inline bool isValidPoint(int r, int c);
inline int BFS(int height);

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    area.resize(N, vector<int>(N));
    for (int r = 0; r < N; r++)
        for (int c = 0; c < N; c++) {
            cin >> area[r][c];
            heights.insert(area[r][c]);
        }

    for (int height : heights)
        maxh = max(maxh, BFS(height));

    cout << maxh;

    return 0;
}

inline bool isValidPoint(int r, int c) {
    return (0 <= r && r < N && 0 <= c && c < N);
}

inline int BFS(int height) {
    int cnt = 0;
    vector<vector<bool>> visited(N, vector<bool>(N, true));
    
    for (int r = 0; r < N; r++)
        for (int c = 0; c < N; c++)
            if (area[r][c] >= height)
                visited[r][c] = false;
    
    for (int r = 0; r < N; r++)
        for (int c = 0; c < N; c++)
            if (!visited[r][c]) {
                cnt++;
                queue<pair<int, int>> q;
                q.push({ r, c });
                while (!q.empty()) {
                    pair<int, int> curr = q.front();
                    q.pop();

                    for (int dir = 0; dir < 4; dir++) {
                        int nextr = curr.first + dr[dir], nextc = curr.second + dc[dir];
                        if (isValidPoint(nextr, nextc) && !visited[nextr][nextc]) {
                            visited[nextr][nextc] = true;
                            q.push({ nextr, nextc });
                        }
                    }
                }
            }

    return cnt;
}