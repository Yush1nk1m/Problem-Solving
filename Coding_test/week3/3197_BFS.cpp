/**
 * @file 3197_BFS.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2024-06-30
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <bits/stdc++.h>
using namespace std;

#define WATER '.'
#define SWAN 'L'
#define ICE 'X'

int R, C;
int dr[4] = { 0, 0, -1, 1 };
int dc[4] = { -1, 1, 0, 0 };
pair<int, int> swan;
vector<vector<char>> lake;
vector<vector<bool>> visitedLake;
vector<vector<bool>> visitedSwan;
queue<pair<int, int>> waterQ;
queue<pair<int, int>> swanQ;

inline bool isValidPoint(int r, int c);
inline bool Move();
inline int BFS();

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> R >> C;
    
    lake.resize(R, vector<char>(C));
    visitedLake.resize(R, vector<bool>(C, false));
    visitedSwan.resize(R, vector<bool>(C, false));

    for (int r = 0; r < R; r++)
        for (int c = 0; c < C; c++) {
            cin >> lake[r][c];
            if (lake[r][c] == SWAN) {
                swan = { r, c };
            }
            
            if (lake[r][c] != ICE) {
                visitedLake[r][c] = true;
                waterQ.push({ r, c });
            }
        }
    visitedSwan[swan.first][swan.second] = true;
    swanQ.push(swan);

    cout << BFS();

    return 0;
}

inline bool isValidPoint(int r, int c) {
    return (0 <= r && r < R && 0 <= c && c < C);
}

inline bool Move() {
    queue<pair<int, int>> nextQ;

    while (!swanQ.empty()) {
        int r, c;
        tie(r, c) = swanQ.front();
        swanQ.pop();

        for (int d = 0; d < 4; d++) {
            int nextr = r + dr[d], nextc = c + dc[d];
            if (!isValidPoint(nextr, nextc) || visitedSwan[nextr][nextc]) continue;
            visitedSwan[nextr][nextc] = true;

            if (lake[nextr][nextc] == WATER) {
                swanQ.push({ nextr, nextc });
            }
            else if (lake[nextr][nextc] == ICE) {
                nextQ.push({ nextr, nextc });
            }
            else if (lake[nextr][nextc] == SWAN) {
                return true;
            }
        }
    }

    while (!nextQ.empty()) {
        swanQ.push(nextQ.front());
        nextQ.pop();
    }

    return false;
}

inline int BFS() {
    int day = 0;

    while (!Move()) {
        day++;
        queue<pair<int, int>> iceQ;
        while (!waterQ.empty()) {
            int r, c;
            tie(r, c) = waterQ.front();
            waterQ.pop();

            for (int d = 0; d < 4; d++) {
                int nextr = r + dr[d], nextc = c + dc[d];
                if (!isValidPoint(nextr, nextc) || visitedLake[nextr][nextc]) continue;

                if (lake[nextr][nextc] == ICE) {
                    visitedLake[nextr][nextc] = true;
                    iceQ.push({ nextr, nextc });
                }
            }
        }

        while (!iceQ.empty()) {
            int r, c;
            tie(r, c) = iceQ.front();
            waterQ.push({ r, c });
            iceQ.pop();
            lake[r][c] = WATER;
        }
    }

    return day;
}