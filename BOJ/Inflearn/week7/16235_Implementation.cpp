/**
 * @file 16235_Implementation.cpp
 * @brief 01:01:45
 * @date 2024-07-17
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <bits/stdc++.h>
using namespace std;

int N, M, K;
int dr[8] = { -1, -1, -1, 0, 0, 1, 1, 1 };
int dc[8] = { -1, 0, 1, -1, 1, -1, 0, 1 };
vector<vector<int>> nutr, ground, deadnutr;
vector<vector<deque<int>>> tree, cptree;

inline bool CheckValidPoint(int r, int c);
inline void Spring();
inline void Summer();
inline void Fall();
inline void Winter();
inline int CountingTree();

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N >> M >> K;
    nutr.resize(N, vector<int>(N));
    ground.resize(N, vector<int>(N, 5));
    deadnutr.resize(N, vector<int>(N, 0));
    tree.resize(N, vector<deque<int>>(N));
    
    for (int r = 0; r < N; r++)
        for (int c = 0; c < N; c++)
            cin >> nutr[r][c];
    
    for (int _ = 0; _ < M; _++) {
        int r, c, age;
        cin >> r >> c >> age;
        tree[r-1][c-1].push_back(age);
    }

    for (int r = 0; r < N; r++)
        for (int c = 0; c < N; c++)
            sort(tree[r][c].begin(), tree[r][c].end());

    for (int _ = 0; _ < K; _++) {
        Spring();
        Summer();
        Fall();
        Winter();
    }

    cout << CountingTree();

    return 0;
}

inline bool CheckValidPoint(int r, int c) {
    return (0 <= r && r < N && 0 <= c && c < N);
}

inline void Spring() {
    queue<int> grown;

    for (int r = 0; r < N; r++)
        for (int c = 0; c < N; c++) {
            // drain
            while (!tree[r][c].empty()) {
                int curr = tree[r][c].front();
                tree[r][c].pop_front();

                if (ground[r][c] >= curr) {
                    grown.push(curr + 1);
                    ground[r][c] -= curr;
                } else {
                    deadnutr[r][c] += (curr / 2);
                }
            }

            // update tree
            while (!grown.empty()) {
                tree[r][c].push_back(grown.front());
                grown.pop();
            }
        }
}

inline void Summer() {
    for (int r = 0; r < N; r++)
        for (int c = 0; c < N; c++)
            ground[r][c] += deadnutr[r][c];
    
    fill(deadnutr.begin(), deadnutr.end(), vector<int>(N, 0));
}

inline void Fall() {
    cptree = tree;

    for (int r = 0; r < N; r++)
        for (int c = 0; c < N; c++)
            while (!cptree[r][c].empty()) {
                int curr = cptree[r][c].front();
                cptree[r][c].pop_front();

                if (curr % 5 == 0)
                    for (int d = 0; d < 8; d++) {
                        int nr = r + dr[d], nc = c + dc[d];
                        if (CheckValidPoint(nr, nc))
                            tree[nr][nc].push_front(1);
                    }
            }
}

inline void Winter() {
    for (int r = 0; r < N; r++)
        for (int c = 0; c < N; c++)
            ground[r][c] += nutr[r][c];
}

inline int CountingTree() {
    int cnt = 0;
    for (int r = 0; r < N; r++)
        for (int c = 0; c < N; c++)
            cnt += tree[r][c].size();
    return cnt;
}