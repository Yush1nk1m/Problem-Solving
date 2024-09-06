/**
 * @file 15661_Backtracking.cpp
 * @brief 00:28:28
 * @date 2024-09-06
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <bits/stdc++.h>
using namespace std;

#define INF 100000000

int N, visitedMask, minDiff = INF;
vector<vector<int>> graph;

void DFS(int curr, int selected);
inline int CalcDiff(int mask);

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    graph.resize(N, vector<int>(N));
    for (int r = 0; r < N; r++)
        for (int c = 0; c < N; c++)
            cin >> graph[r][c];

    DFS(0, 0);

    cout << minDiff;

    return 0;
}

void DFS(int curr, int selected) {
    if (curr == N || selected == N / 2) {
        if (visitedMask != 0 && visitedMask != (1 << N) - 1)
            minDiff = min(minDiff, CalcDiff(visitedMask));
        return;
    }

    // Not select
    DFS(curr + 1, selected);

    // Select
    visitedMask |= (1 << curr);
    DFS(curr + 1, selected + 1);
    visitedMask &= ~(1 << curr);
}

inline int CalcDiff(int mask) {
    vector<int> v0, v1;
    int s0 = 0, s1 = 0;
    
    for (int i = 0; i < N; i++) {
        if (mask & (1 << i))
            v1.push_back(i);
        else
            v0.push_back(i);
    }

    for (int i = 0; i < v0.size() - 1; i++)
        for (int j = i + 1; j < v0.size(); j++)
            s0 += graph[v0[i]][v0[j]] + graph[v0[j]][v0[i]];

    for (int i = 0; i < v1.size() - 1; i++)
        for (int j = i + 1; j < v1.size(); j++)
            s1 += graph[v1[i]][v1[j]] + graph[v1[j]][v1[i]];

    return abs(s0 - s1);
}