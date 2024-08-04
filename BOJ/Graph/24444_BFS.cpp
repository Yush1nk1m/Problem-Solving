/**
 * @file 24444_BFS.cpp
 * @brief 00:04:27
 * @date 2024-08-04
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <bits/stdc++.h>
using namespace std;

int N, M, R, order = 1;
vector<vector<int>> graph;
vector<int> visited;
queue<int> q;

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
        sort(graph[i].begin(), graph[i].end());

    visited[R] = order++;
    q.push(R);
    while (!q.empty()) {
        int curr = q.front();
        q.pop();

        for (int neighbor : graph[curr])
            if (!visited[neighbor]) {
                visited[neighbor] = order++;
                q.push(neighbor);
            }
    }

    for (int i = 1; i <= N; i++)
        cout << visited[i] << '\n';

    return 0;
}