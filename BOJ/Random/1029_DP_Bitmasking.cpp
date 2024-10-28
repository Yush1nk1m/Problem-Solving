/**
 * @file 1029_DP_Bitmasking.cpp
 * @brief 00:27:41
 * @date 2024-10-28
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <bits/stdc++.h>
using namespace std;

#define NONE    0

int N, maxCount;
vector<vector<int>> graph;
int cache[16][10][1<<16];   // [prev][maxPrice][visited mask]

int dfs(int prev, int maxPrice, int visited);

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    graph.resize(N, vector<int>(N));
    for (int r = 0; r < N; r++)
        for (int c = 0; c < N; c++) {
            char input;
            cin >> input;
            graph[r][c] = input - '0';
        }

    cout << dfs(0, 0, 1);

    return 0;
}

int dfs(int prev, int maxPrice, int visited) {
    int& ret = cache[prev][maxPrice][visited];
    if (ret != NONE)
        return ret;

    for (int i = 1; i < N; i++)
        if (!(visited & (1 << i)) && graph[prev][i] >= maxPrice) {
            ret = max(ret, dfs(i, graph[prev][i], visited | (1 << i)));
        }

    return ++ret;
}