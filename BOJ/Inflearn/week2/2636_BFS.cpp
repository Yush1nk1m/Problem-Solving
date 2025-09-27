/**
 * @file 2636_BFS.cpp
 * @brief 00:26:42
 * @date 2024-06-28
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <bits/stdc++.h>
using namespace std;

#define AIR -1
#define CHEESE 1
#define NONAIR 0

int row, col;
int dr[4] = { 0, 0, -1, 1 };
int dc[4] = { -1, 1, 0, 0 };
vector<vector<int>> table;
vector<vector<bool>> visited;
queue<pair<int, int>> cheeseq;

inline bool isValidPoint(int r, int c);
inline void MarkAir(int r, int c);
inline int CountCheese();
inline pair<int, int> BFS();

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> row >> col;
    table.resize(row, vector<int>(col));
    visited.resize(row, vector<bool>(col, false));

    for (int r = 0; r < row; r++)
        for (int c = 0; c < col; c++)
            cin >> table[r][c];

    pair<int, int> result = BFS();

    cout << result.first << '\n' << result.second;

    return 0;
}

inline bool isValidPoint(int r, int c) {
    return (0 <= r && r < row && 0 <= c && c < col);
}

inline void MarkAir(int r, int c) {
    queue<pair<int, int>> q;
    
    table[r][c] = AIR;
    q.push({ r, c });
    while (!q.empty()) {
        pair<int, int> curr = q.front();
        q.pop();

        for (int dir = 0; dir < 4; dir++) {
            int nextr = curr.first + dr[dir], nextc = curr.second + dc[dir];
            if (isValidPoint(nextr, nextc)) {
                if (table[nextr][nextc] == NONAIR) {
                    table[nextr][nextc] = AIR;
                    q.push({ nextr, nextc });
                } else if (table[nextr][nextc] == CHEESE && !visited[nextr][nextc]) {
                    visited[nextr][nextc] = true;
                    cheeseq.push({ nextr, nextc });
                }
            }
        }
    }
}

inline int CountCheese() {
    int cnt = 0;
    for (int r = 0; r < row; r++)
        for (int c = 0; c < col; c++)
            cnt += (table[r][c] == CHEESE);
    return cnt;
}

inline pair<int, int> BFS() {
    MarkAir(0, 0);

    int time = 0, qsize = 0;

    while (!cheeseq.empty()) {
        qsize = cheeseq.size();
        vector<pair<int, int>> newAirs;

        for (int _ = 0; _ < qsize; _++) {
            pair<int, int> curr = cheeseq.front();
            cheeseq.pop();
            table[curr.first][curr.second] = AIR;

            for (int dir = 0; dir < 4; dir++) {
                int nextr = curr.first + dr[dir], nextc = curr.second + dc[dir];
                if (isValidPoint(nextr, nextc)) {
                    if (table[nextr][nextc] == CHEESE && !visited[nextr][nextc]) {
                        visited[nextr][nextc] = true;
                        cheeseq.push({ nextr, nextc });
                    }
                    else if (table[nextr][nextc] == NONAIR)
                        newAirs.push_back({ nextr, nextc });
                }
            }
        }

        for (pair<int, int>& air : newAirs)
            if (table[air.first][air.second] == NONAIR)
                MarkAir(air.first, air.second);

        time++;
    }
    
    return make_pair(time, qsize);
}