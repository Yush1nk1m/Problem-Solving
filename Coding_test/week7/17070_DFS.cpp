/**
 * @file 17070_DFS.cpp
 * @brief 00:22:00
 * @date 2024-07-14
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <bits/stdc++.h>
using namespace std;

#define EMPTY       0
#define WALL        1
#define RIGHT       1
#define DIAGONAL    2
#define DOWN        3

int N, cnt;
vector<vector<int>> status;

inline bool isValidPoint(int r, int c);
void DFS(int r, int c, int dir);

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    status.resize(N, vector<int>(N));
    for (int r = 0; r < N; r++)
        for (int c = 0; c < N; c++)
            cin >> status[r][c];
    
    DFS(0, 1, RIGHT);

    cout << cnt;

    return 0;
}

inline bool isValidPoint(int r, int c) {
    return (r < N && c < N && status[r][c] != WALL);
}

void DFS(int r, int c, int dir) {
    if (r == N - 1 && c == N - 1) {
        cnt++;
        return;
    }

    if (dir == RIGHT) {
        if (isValidPoint(r, c + 1))
            DFS(r, c + 1, RIGHT);
        if (isValidPoint(r, c + 1) && isValidPoint(r + 1, c + 1) && isValidPoint(r + 1, c))
            DFS(r + 1, c + 1, DIAGONAL);
    } else if (dir == DIAGONAL) {
        if (isValidPoint(r, c + 1))
            DFS(r, c + 1, RIGHT);
        if (isValidPoint(r + 1, c))
            DFS(r + 1, c, DOWN);
        if (isValidPoint(r, c + 1) && isValidPoint(r + 1, c + 1) && isValidPoint(r + 1, c))
            DFS(r + 1, c + 1, DIAGONAL);
    } else if (dir == DOWN) {
        if (isValidPoint(r, c + 1) && isValidPoint(r + 1, c + 1) && isValidPoint(r + 1, c))
            DFS(r + 1, c + 1, DIAGONAL);
        if (isValidPoint(r + 1, c))
            DFS(r + 1, c, DOWN);
    }
}