/**
 * @file 1012_BFS.cpp
 * @brief 00:11:34
 * @date 2024-06-25
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <bits/stdc++.h>
using namespace std;

int T, N, M, K;
int dr[4] = { 0, 0, 1, -1 };
int dc[4] = { 1, -1, 0, 0 };

inline bool isValidPoint(int r, int c, int row, int col) {
    return (0 <= r && r < row && 0 <= c && c < col);
}

inline int BFS(int row, int col, int place) {
    int cnt = 0;
    vector<vector<bool>> visited(row, vector<bool>(col, true));
    
    for (int _ = 0; _ < place; _++) {
        int r, c;
        cin >> c >> r;
        visited[r][c] = false;
    }

    for (int r = 0; r < row; r++)
        for (int c = 0; c < col; c++)
            if (!visited[r][c]) {
                cnt++;
                queue<pair<int, int>> q;
                visited[r][c] = true;
                q.push({ r, c });
                while (!q.empty()) {
                    pair<int, int> curr = q.front();
                    q.pop();

                    for (int dir = 0; dir < 4; dir++) {
                        int nextr = curr.first + dr[dir], nextc = curr.second + dc[dir];
                        if (isValidPoint(nextr, nextc, row, col) && !visited[nextr][nextc]) {
                            visited[nextr][nextc] = true;
                            q.push({ nextr, nextc });
                        }
                    }
                }
            }
    return cnt;
}

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> T;
    for (int _ = 0; _ < T; _++) {
        cin >> M >> N >> K;
        cout << BFS(N, M, K) << '\n';
    }

    return 0;
}