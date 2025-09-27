/**
 * @file 14497_BFS.cpp
 * @brief 00:28:04
 * @date 2024-06-30
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <bits/stdc++.h>
using namespace std;

#define EMPTY '0'
#define FRIEND '1'
#define JUNAN '*'
#define TARGET '#'

int N, M;
int dr[4] = { 0, 0, -1, 1 };
int dc[4] = { -1, 1, 0, 0 };
pair<int, int> junan, target;
vector<vector<char>> table;
vector<vector<bool>> visited;

inline bool isValidPoint(int r, int c);
inline int BFS();

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    table.resize(N, vector<char>(M));
    visited.resize(N, vector<bool>(M));
    
    cin >> junan.first >> junan.second >> target.first >> target.second;
    junan.first--; junan.second--; target.first--; target.second--;
    for (int r = 0; r < N; r++)
        for (int c = 0; c < M; c++)
            cin >> table[r][c];

    cout << BFS();

    return 0;
}

inline bool isValidPoint(int r, int c) {
    return (0 <= r && r < N && 0 <= c && c < M);
}

inline int BFS() {
    int jump = 0;
    queue<pair<int, int>> q;
    q.push(junan);
    visited[junan.first][junan.second] = true;

    while (!visited[target.first][target.second]) {
        jump++;
        vector<pair<int, int>> nexts;
        while (!q.empty()) {
            pair<int, int> curr = q.front();
            q.pop();

            for (int dir = 0; dir < 4; dir++) {
                int nextr = curr.first + dr[dir], nextc = curr.second + dc[dir];
                if (!isValidPoint(nextr, nextc)) continue;
                if (visited[nextr][nextc]) continue;

                visited[nextr][nextc] = true;
                if (table[nextr][nextc] == EMPTY) {
                    q.push({ nextr, nextc });
                }
                else if (table[nextr][nextc] == FRIEND) {
                    table[nextr][nextc] = EMPTY;
                    nexts.push_back({ nextr, nextc });
                }
                else if (table[nextr][nextc] == TARGET) {
                    return jump;
                }
            }
        }

        for (pair<int, int>& nextp : nexts) {
            q.push(nextp);
        }
    }

    return jump;
}