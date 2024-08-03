/**
 * @file 24480_DFS.cpp
 * @brief 00:05:37
 * @date 2024-08-03
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <bits/stdc++.h>
using namespace std;

int N, M, R, order = 1;
vector<vector<int>> graph;
vector<int> visited;

void DFS(int v);

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M >> R;

    graph.resize(N + 1);
    visited.resize(N + 1, 0);

    for (int _ = 0; _ < M; _++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    for (int i = 1; i <= N; i++)
        sort(graph[i].rbegin(), graph[i].rend());

    DFS(R);

    for (int i = 1; i <= N; i++)
        cout << visited[i] << '\n';

    return 0;
}

void DFS(int v) {
    visited[v] = order++;
    for (int neighbor : graph[v])
        if (!visited[neighbor])
            DFS(neighbor);
}