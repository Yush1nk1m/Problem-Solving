/**
 * @file 2611_TopoSort.cpp
 * @brief 01:10:00
 * @date 2024-10-23
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<vector<pair<int, int>>> graph;   // [source]<destination, cost>
vector<pair<int, int>> candidates;      // []<source, cost>
vector<int> inDegree, parent, dist;
queue<int> sources;

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    graph.resize(N + 1);
    inDegree.resize(N + 1, 0);
    parent.resize(N + 1);
    dist.resize(N + 1, 0);
    while (M--) {
        int p, q, r;
        cin >> p >> q >> r;

        if (q == 1) {
            candidates.push_back({ p, r });
            continue;
        }

        graph[p].push_back({ q, r });
        inDegree[q]++;
    }

    sources.push(1);
    while (!sources.empty()) {
        int curr = sources.front();
        sources.pop();

        for (pair<int, int>& p : graph[curr]) {
            int neighbor = p.first, cost = p.second;

            if (dist[neighbor] < dist[curr] + cost) {
                dist[neighbor] = dist[curr] + cost;
                parent[neighbor] = curr;
            }
            
            if (--inDegree[neighbor] == 0) {
                sources.push(neighbor);
            }
        }
    }

    for (pair<int, int>& candidate : candidates) {
        int source = candidate.first, cost = candidate.second;

        if (dist[1] < dist[source] + cost) {
            dist[1] = dist[source] + cost;
            parent[1] = source;
        }
    }

    cout << dist[1] << '\n';

    stack<int> route;
    route.push(1);
    for (int i = parent[1]; i != 1; i = parent[i])
        route.push(i);
    route.push(1);

    while (!route.empty()) {
        cout << route.top() << ' ';
        route.pop();
    }

    return 0;
}