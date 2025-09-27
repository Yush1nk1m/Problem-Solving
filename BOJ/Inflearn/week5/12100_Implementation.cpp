/**
 * @file 12100_Implementation.cpp
 * @brief 00:53:58
 * @date 2024-07-06
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include <bits/stdc++.h>
using namespace std;

#define EMPTY   0
#define RIGHT   0
#define LEFT    1
#define UP      2
#define DOWN    3

int N, maxBlock;
vector<vector<int>> table;

inline int GetMaxBlock(vector<vector<int>>& table);
inline void Move(vector<vector<int>>& table, int dir);
void DFS(vector<vector<int>> table, int depth);

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    table.resize(N, vector<int>(N));
    for (int r = 0; r < N; r++)
        for (int c = 0; c < N; c++)
            cin >> table[r][c];
    
    DFS(table, 0);
    cout << maxBlock;
    
    return 0;
}

inline int GetMaxBlock(vector<vector<int>>& table) {
    int res = 0;
    for (int r = 0; r < N; r++)
        for (int c = 0; c < N; c++)
            res = max(res, table[r][c]);
    return res;
}

inline void Move(vector<vector<int>>& table, int dir) {
    queue<int> q;

    if (dir == RIGHT) {
        for (int r = 0; r < N; r++) {
            for (int c = N - 1; c >= 0; c--)
                if (table[r][c] != EMPTY)
                    q.push(table[r][c]);
            
            for (int c = N - 1; c >= 0; c--) {
                if (q.empty()) {
                    table[r][c] = EMPTY;
                } else {
                    int n = q.front();
                    q.pop();

                    if (!q.empty() && q.front() == n) {
                        table[r][c] = n * 2;
                        q.pop();
                    } else {
                        table[r][c] = n;
                    }
                }
            }
        }
    }
    else if (dir == LEFT) {
        for (int r = 0; r < N; r++) {
            for (int c = 0; c < N; c++)
                if (table[r][c] != EMPTY)
                    q.push(table[r][c]);
            
            for (int c = 0; c < N; c++) {
                if (q.empty()) {
                    table[r][c] = EMPTY;
                } else {
                    int n = q.front();
                    q.pop();

                    if (!q.empty() && q.front() == n) {
                        table[r][c] = n * 2;
                        q.pop();
                    } else {
                        table[r][c] = n;
                    }
                }
            }
        }
    }
    else if (dir == UP) {
        for (int c = 0; c < N; c++) {
            for (int r = 0; r < N; r++)
                if (table[r][c] != EMPTY)
                    q.push(table[r][c]);

            for (int r = 0; r < N; r++) {
                if (q.empty()) {
                    table[r][c] = EMPTY;
                } else {
                    int n = q.front();
                    q.pop();

                    if (!q.empty() && q.front() == n) {
                        table[r][c] = n * 2;
                        q.pop();
                    } else {
                        table[r][c] = n;
                    }
                }
            }
        }
    }
    else if (dir == DOWN) {
        for (int c = 0; c < N; c++) {
            for (int r = N - 1; r >= 0; r--)
                if (table[r][c] != EMPTY)
                    q.push(table[r][c]);

            for (int r = N - 1; r >= 0; r--) {
                if (q.empty()) {
                    table[r][c] = EMPTY;
                } else {
                    int n = q.front();
                    q.pop();

                    if (!q.empty() && q.front() == n) {
                        table[r][c] = n * 2;
                        q.pop();
                    } else {
                        table[r][c] = n;
                    }
                }
            }
        }
    }
}

void DFS(vector<vector<int>> table, int depth) {
    if (depth == 5) {
        maxBlock = max(maxBlock, GetMaxBlock(table));
        return;
    }

    vector<vector<int>> copyTable;

    for (int dir = 0; dir < 4; dir++) {
        copyTable = table;
        Move(copyTable, dir);
        DFS(copyTable, depth + 1);
    }
}