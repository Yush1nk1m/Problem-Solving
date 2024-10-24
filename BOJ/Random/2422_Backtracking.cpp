/**
 * @file 2422_Backtracking.cpp
 * @brief 00:11:32
 * @date 2024-10-24
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<vector<bool>> graph;

int dfs(int i, int depth, int prev);

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    graph.resize(N + 1, vector<bool>(N + 1, true));
    for (int i = 1; i <= N; i++)
        graph[i][i] = false;

    while (M--) {
        int i1, i2;
        cin >> i1 >> i2;
        graph[i1][i2] = graph[i2][i1] = false;
    }

    cout << dfs(0, 0, 0);

    return 0;
}

int dfs(int i, int depth, int prev) {
    if (depth == 3) {
        return 1;
    } else if (i > N) {
        return 0;
    }

    int sum = 0;
    for (int nxt = i + 1; nxt <= N; nxt++)
        if (graph[i][nxt] && graph[prev][nxt])
            sum += dfs(nxt, depth + 1, i);

    return sum;
}