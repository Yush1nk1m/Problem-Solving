/**
 * @file 2583_BFS.cpp
 * @brief 00:29:46
 * @date 2024-06-25
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <bits/stdc++.h>
using namespace std;

int row, col, K;
int dr[4] = { 0, 0, 1, -1 };
int dc[4] = { 1, -1, 0, 0 };
vector<vector<bool>> visited;
vector<int> areas;

inline bool isValidPoint(int r, int c);
inline int BFS();

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> row >> col >> K;
    visited.resize(row, vector<bool>(col, false));

    for (int _ = 0; _ < K; _++) {
        int r1, c1, r2, c2;
        cin >> c1 >> r1 >> c2 >> r2;

        // adjust (x, y) scale to (r, c) scale
        r1 = row - r1 - 1;
        r2 = row - r2;  // r2 < r1
        c2--;           // c1 < c2

        for (int r = r2; r <= r1; r++)
            for (int c = c1; c <= c2; c++)
                visited[r][c] = true;
    }

    cout << BFS() << '\n';
    sort(areas.begin(), areas.end());
    for (int area : areas)
        cout << area << ' ';

    return 0;
}

inline bool isValidPoint(int r, int c) {
    return (0 <= r && r < row && 0 <= c && c < col);
}

inline int BFS() {
    int cnt = 0;

    for (int r = 0; r < row; r++)
        for (int c = 0; c < col; c++)
            if (!visited[r][c]) {
                cnt++;
                int area = 0;
                queue<pair<int, int>> q;
                
                visited[r][c] = true;
                q.push({ r, c });
                area++;

                while (!q.empty()) {
                    pair<int, int> curr = q.front();
                    q.pop();

                    for (int dir = 0; dir < 4; dir++) {
                        int nextr = curr.first + dr[dir], nextc = curr.second + dc[dir];
                        if (isValidPoint(nextr, nextc) && !visited[nextr][nextc]) {
                            visited[nextr][nextc] = true;
                            q.push({ nextr, nextc });
                            area++;
                        }
                    }
                }

                areas.push_back(area);
            }

    return cnt;
}