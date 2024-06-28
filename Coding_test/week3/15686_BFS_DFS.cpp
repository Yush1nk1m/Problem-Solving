/**
 * @file 15686_BFS_DFS.cpp
 * @brief 00:28:13
 * @date 2024-06-28
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <bits/stdc++.h>
using namespace std;

#define EMPTY 0
#define HOUSE 1
#define CHICKEN 2
#define INF 100000000

int N, M, minDist = INF;
int dr[4] = { 0, 0, 1, -1 };
int dc[4] = { 1, -1, 0, 0 };
vector<vector<int>> city;
vector<pair<int, int>> chickens;
vector<pair<int, int>> selected;

inline bool isValidPoint(int r, int c);
void DFS(int start, int depth);
inline int BFS();

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    city.resize(N, vector<int>(N));
    for (int r = 0; r < N; r++)
        for (int c = 0; c < N; c++) {
            cin >> city[r][c];
            if (city[r][c] == CHICKEN)
                chickens.push_back({ r, c });
        }
    
    DFS(0, 0);
    cout << minDist;

    return 0;
}

inline bool isValidPoint(int r, int c) {
    return (0 <= r && r < N && 0 <= c && c < N);
}

void DFS(int start, int depth) {
    if (depth == M) {
        minDist = min(minDist, BFS());
        return;
    }

    for (int i = start; i <= chickens.size() - M + depth; i++) {
        selected.push_back(chickens[i]);   
        DFS(i + 1, depth + 1);
        selected.pop_back();
    }
}

inline int BFS() {
    queue<pair<int, int>> q;
    vector<vector<int>> copyMap(N, vector<int>(N, EMPTY));

    for (int r = 0; r < N; r++)
        for (int c = 0; c < N; c++)
            if (city[r][c] != CHICKEN)
                copyMap[r][c] = city[r][c];
    
    for (pair<int, int>& loc : selected) {
        copyMap[loc.first][loc.second] = CHICKEN;
        q.push(loc);
    }
    
    int totalDist = 0, dist = 0;
    while (!q.empty()) {
        int qsize = q.size();
        dist++;
        for (int _ = 0; _ < qsize; _++) {
            pair<int, int> curr = q.front();
            q.pop();

            for (int dir = 0; dir < 4; dir++) {
                int nextr = curr.first + dr[dir], nextc = curr.second + dc[dir];
                if (!isValidPoint(nextr, nextc)) continue;

                if (copyMap[nextr][nextc] == EMPTY) {
                    q.push({ nextr, nextc });
                    copyMap[nextr][nextc] = CHICKEN;
                } else if (copyMap[nextr][nextc] == HOUSE) {
                    q.push({ nextr, nextc });
                    copyMap[nextr][nextc] = CHICKEN;
                    totalDist += dist;
                }
            }
        }
    }

    return totalDist;
}