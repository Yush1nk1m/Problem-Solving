/**
 * @file 16234_BFS_Implementation.cpp
 * @brief 00:23:46
 * @date 2024-06-29
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <bits/stdc++.h>
using namespace std;

int N, L, R, day;
int dr[4] = { 0, 0, -1, 1 };
int dc[4] = { -1, 1, 0, 0 };
vector<vector<int>> nations;
vector<vector<bool>> visited;

inline bool isValidPoint(int r, int c);
inline bool Move();
inline bool BFS(int r, int c);

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> L >> R;
    nations.resize(N, vector<int>(N));
    visited.resize(N, vector<bool>(N));

    for (int r = 0; r < N; r++)
        for (int c = 0; c < N; c++)
            cin >> nations[r][c];

    while (Move()) day++;

    cout << day;

    return 0;
}

inline bool isValidPoint(int r, int c) {
    return (0 <= r && r < N && 0 <= c && c < N);
}

inline bool Move() {
    bool isBorderOpened = false;
    fill(visited.begin(), visited.end(), vector<bool>(N, false));

    for (int r = 0; r < N; r++)
        for (int c = 0; c < N; c++)
            if (!visited[r][c] && BFS(r, c))
                isBorderOpened = true;
    
    return isBorderOpened;
}

inline bool BFS(int r, int c) {
    int total = 0, cnt = 0;
    vector<pair<int, int>> unions;
    queue<pair<int, int>> q;

    q.push({ r, c });
    visited[r][c] = true;
    while (!q.empty()) {
        pair<int, int> curr = q.front();
        q.pop();

        unions.push_back(curr);
        cnt++;
        total += nations[curr.first][curr.second];

        for (int dir = 0; dir < 4; dir++) {
            int nextr = curr.first + dr[dir], nextc = curr.second + dc[dir];
            if (!isValidPoint(nextr, nextc) || visited[nextr][nextc]) continue;
            int diff = abs(nations[curr.first][curr.second] - nations[nextr][nextc]);
            if (L <= diff && diff <= R) {
                q.push({ nextr, nextc });
                visited[nextr][nextc] = true;
            }
        }
    }

    for (pair<int, int>& loc : unions)
        nations[loc.first][loc.second] = total / cnt;

    return (unions.size() > 1);
}