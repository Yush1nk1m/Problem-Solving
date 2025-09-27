/**
 * @file 14502_BFS.cpp
 * @brief 00:13:52
 * @date 2024-06-28
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <bits/stdc++.h>
using namespace std;

#define EMPTY 0
#define WALL 1
#define VIRUS 2

int N, M, maxSafe;
int dr[4] = { 0, 0, 1, -1 };
int dc[4] = { 1, -1, 0, 0 };
vector<vector<int>> labmap;
vector<pair<int, int>> availables;

inline bool isValidPoint(int, int);
inline int BFS(pair<int, int>, pair<int, int>, pair<int, int>);

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    labmap.resize(N, vector<int>(M));

    for (int r = 0; r < N; r++)
        for (int c = 0; c < M; c++) {
            cin >> labmap[r][c];
            if (labmap[r][c] == EMPTY)
                availables.push_back({ r, c });
        }
    
    int asize = availables.size();
    for (int w1 = 0; w1 < asize; w1++)
        for (int w2 = w1 + 1; w2 < asize; w2++)
            for (int w3 = w2 + 1; w3 < asize; w3++)
                maxSafe = max(maxSafe, BFS(availables[w1], availables[w2], availables[w3]));

    cout << maxSafe;

    return 0;
}

inline bool isValidPoint(int r, int c) {
    return (0 <= r && r < N && 0 <= c && c < M);
}

inline int BFS(pair<int, int> w1, pair<int, int> w2, pair<int, int> w3) {
    vector<vector<int>> copyMap(labmap);
    copyMap[w1.first][w1.second] = copyMap[w2.first][w2.second] = copyMap[w3.first][w3.second] = WALL;

    queue<pair<int, int>> q;
    for (int r = 0; r < N; r++)
        for (int c = 0; c < M; c++)
            if (copyMap[r][c] == VIRUS)
                q.push({ r, c });

    while (!q.empty()) {
        pair<int, int> curr = q.front();
        q.pop();

        for (int dir = 0; dir < 4; dir++) {
            int nextr = curr.first + dr[dir], nextc = curr.second + dc[dir];
            if (isValidPoint(nextr, nextc) && copyMap[nextr][nextc] == EMPTY) {
                copyMap[nextr][nextc] = VIRUS;
                q.push({ nextr, nextc });
            }
        }
    }

    int cnt = 0;
    for (int r = 0; r < N; r++)
        for (int c = 0; c < M; c++)
            cnt += (copyMap[r][c] == EMPTY);
    
    return cnt;
}