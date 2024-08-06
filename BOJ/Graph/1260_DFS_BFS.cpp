/**
 * @file 1260_DFS_BFS.cpp
 * @brief 00:05:58
 * @date 2024-08-06
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <bits/stdc++.h>
using namespace std;

int N, M, V;
vector<vector<int>> graph;
vector<bool> visited;

void DFS(int node);
inline void BFS();

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M >> V;

    graph.resize(N + 1);
    visited.resize(N + 1, false);

    for (int _ = 0; _ < M; _++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    for (int i = 1; i <= N; i++)
        sort(graph[i].begin(), graph[i].end());

    DFS(V);
    cout << '\n';
    fill(visited.begin(), visited.end(), false);
    BFS();

    return 0;
}

void DFS(int node) {
    visited[node] = true;
    cout << node << ' ';
    for (int neighbor : graph[node])
        if (!visited[neighbor])
            DFS(neighbor);
}

inline void BFS() {
    queue<int> q;

    visited[V] = true;
    cout << V << ' ';
    q.push(V);
    while (!q.empty()) {
        int curr = q.front();
        q.pop();

        for (int neighbor : graph[curr])
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                cout << neighbor << ' ';
                q.push(neighbor);
            }
    }
}