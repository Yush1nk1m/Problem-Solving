/**
 * @file 2589_BFS.cpp
 * @brief 00:38:34
 * @date 2024-06-29
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <bits/stdc++.h>
using namespace std;

#define GROUND 'L'
#define OCEAN 'W'

int row, col, maxDist;
int dr[4] = { 0, 0, 1, -1 };
int dc[4] = { 1, -1, 0, 0 };
vector<vector<char>> table;

inline bool isValidPoint(int r, int c);
inline int BFS(int r, int c);

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> row >> col;
    table.resize(row, vector<char>(col));
    for (int r = 0; r < row; r++)
        for (int c = 0; c < col; c++)
            cin >> table[r][c];
    
    for (int r = 0; r < row; r++)
        for (int c = 0; c < col; c++)
            if (table[r][c] == GROUND) {
                maxDist = max(maxDist, BFS(r, c));
            }
    
    cout << maxDist;

    return 0;
}

inline bool isValidPoint(int r, int c) {
    return (0 <= r && r < row && 0 <= c && c < col);
}

inline int BFS(int r, int c) {
    vector<vector<char>> copyMap = table;
    vector<vector<int>> distTable(row, vector<int>(col, 0));
    queue<pair<int, int>> q;
    int dist = -1;

    copyMap[r][c] = OCEAN;
    q.push({ r, c });
    while (!q.empty()) {
        dist++;
        int qsize = q.size();
        for (int _ = 0; _ < qsize; _++) {
            pair<int, int> curr = q.front();
            q.pop();

            for (int dir = 0; dir < 4; dir++) {
                int nextr = curr.first + dr[dir], nextc = curr.second + dc[dir];
                if (isValidPoint(nextr, nextc) && copyMap[nextr][nextc] == GROUND) {
                    copyMap[nextr][nextc] = OCEAN;
                    q.push({ nextr, nextc });

                    distTable[nextr][nextc] = distTable[curr.first][curr.second] + 1;
                }
            }
        }
    }

    return dist;
}