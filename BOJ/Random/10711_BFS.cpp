/**
 * @file 10711_BFS.cpp
 * @brief 00:29:56
 * @date 2024-11-09
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <bits/stdc++.h>
using namespace std;

#define EMPTY '.'

int H, W, waves;
int dr[8] = { -1, -1, -1, 0, 1, 1, 1, 0 };  // 8 row directions
int dc[8] = { -1, 0, 1, 1, 1, 0, -1, -1 };  // 8 col directions
vector<vector<char>> status;
queue<pair<int, int>> q;

inline bool isValidPoint(int r, int c);

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> H >> W;
    status.resize(H, vector<char>(W));
    for (int r = 0; r < H; r++)
        for (int c = 0; c < W; c++) {
            cin >> status[r][c];
            if (status[r][c] == EMPTY)
                q.push({ r, c });
        }

    while (!q.empty()) {
        bool changed = false;
        int qSize = q.size();
        while (qSize--) {
            pair<int, int> curr = q.front();
            q.pop();

            for (int d = 0; d < 8; d++) {
                int nr = curr.first + dr[d], nc = curr.second + dc[d];
                if (!isValidPoint(nr, nc) || status[nr][nc] == EMPTY)
                    continue;

                if (status[nr][nc] == '1') {
                    changed = true;
                    status[nr][nc] = EMPTY;
                    q.push({ nr, nc });
                } else {
                    status[nr][nc]--;
                }
            }
        }

        if (changed)
            waves++;
    }

    cout << waves;

    return 0;
}

inline bool isValidPoint(int r, int c) {
    return 0 <= r && r < H && 0 <= c && c < W;
}
