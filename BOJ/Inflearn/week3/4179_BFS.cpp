/**
 * @file 4179_BFS.cpp
 * @brief 00:21:20
 * @date 2024-06-29
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <bits/stdc++.h>
using namespace std;

int R, C;
int dr[4] = { 0, 0, -1, 1 };
int dc[4] = { -1, 1, 0, 0 };
vector<vector<char>> maze;
queue<pair<int, int>> jihoonQ;
queue<pair<int, int>> fireQ;

inline bool isValidPoint(int r, int c);
inline int BFS();

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> R >> C;
    maze.resize(R, vector<char>(C));
    for (int r = 0; r < R; r++)
        for (int c = 0; c < C; c++) {
            cin >> maze[r][c];
            if (maze[r][c] == 'J') jihoonQ.push({ r, c });
            else if (maze[r][c] == 'F') fireQ.push({ r, c });
        }

    int time = BFS();
    if (time < 0) cout << "IMPOSSIBLE";
    else cout << time;

    return 0;
}

inline bool isValidPoint(int r, int c) {
    return (0 <= r && r < R && 0 <= c && c < C);
}

inline int BFS() {
    int time = 0;

    while (!jihoonQ.empty() || !fireQ.empty()) {
        time++;

        // spread fire for the first
        int fqsize = fireQ.size();
        for (int _ = 0; _ < fqsize; _++) {
            pair<int, int> curr = fireQ.front();
            fireQ.pop();

            for (int dir = 0; dir < 4; dir++) {
                int nextr = curr.first + dr[dir], nextc = curr.second + dc[dir];
                if (!isValidPoint(nextr, nextc)) continue;
                if (maze[nextr][nextc] == '.' || maze[nextr][nextc] == 'J') {
                    maze[nextr][nextc] = 'F';
                    fireQ.push({ nextr, nextc });
                }
            }
        }

        // move jihoon for the second
        int jqsize = jihoonQ.size();
        for (int _ = 0; _ < jqsize; _++) {
            pair<int, int> curr = jihoonQ.front();
            jihoonQ.pop();

            if (curr.first == 0 || curr.first == R - 1 || curr.second == 0 || curr.second == C - 1)
                return time;

            for (int dir = 0; dir < 4; dir++) {
                int nextr = curr.first + dr[dir], nextc = curr.second + dc[dir];
                if (!isValidPoint(nextr, nextc)) continue;
                if (maze[nextr][nextc] == '.') {
                    maze[nextr][nextc] = 'J';
                    jihoonQ.push({ nextr, nextc });
                }
            }
        }
    }

    return -1;
}