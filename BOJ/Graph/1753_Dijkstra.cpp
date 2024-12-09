/**
 * @file 1753_Dijkstra.cpp
 * @brief 00:21:33
 * @date 2024-07-24
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <bits/stdc++.h>
using namespace std;

#define INF 1000000000

int V, E, K;
vector<int> dist;
vector<bool> visited;
vector<vector<pair<int, int>>> graph;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> V >> E >> K;
    dist.resize(V + 1, INF);
    visited.resize(V + 1, false);
    graph.resize(V + 1);
    for (int _ = 0; _ < E; _++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({ v, w });
    }

    dist[K] = 0;
    pq.push({ 0, K });
    while (!pq.empty()) {
        int w = pq.top().first, curr = pq.top().second;
        pq.pop();

        if (visited[curr]) continue;
        visited[curr] = true;

        for (pair<int, int>& p : graph[curr]) {
            int neighbor = p.first, nw = p.second;
            if (w + nw < dist[neighbor]) {
                dist[neighbor] = w + nw;
                pq.push({ w + nw, neighbor });
            }
        }
    }

    for (int i = 1; i <= V; i++) {
        if (dist[i] != INF)
            cout << dist[i] << '\n';
        else
            cout << "INF\n";
    }

    return 0;
}