/**
 * @file 14496_BFS.cpp
 * @brief 00:13:01
 * @date 2024-08-16
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <bits/stdc++.h>
using namespace std;

#define NONE    -1

int N, M, from, to;
vector<int> dist;
vector<vector<int>> graph;
queue<int> q;

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> from >> to >> N >> M;
    dist.resize(N + 1, NONE);
    graph.resize(N + 1);

    while (M--) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    dist[from] = 0;
    q.push(from);
    while (!q.empty()) {
        int curr = q.front();
        q.pop();

        for (int neighbor : graph[curr])
            if (dist[neighbor] == NONE) {
                dist[neighbor] = dist[curr] + 1;
                q.push(neighbor);
            }
    }

    cout << dist[to];

    return 0;
}