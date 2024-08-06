/**
 * @file 2606_BFS.cpp
 * @brief 00:04:23
 * @date 2024-08-06
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<vector<int>> graph;
vector<bool> visited;
queue<int> q;

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    
    graph.resize(N + 1);
    visited.resize(N + 1, false);

    for (int _ = 0; _ < M; _++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    visited[1] = true;
    q.push(1);
    while (!q.empty()) {
        int curr = q.front();
        q.pop();

        for (int neighbor : graph[curr])
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
    }

    cout << accumulate(visited.begin(), visited.end(), -1);

    return 0;
}