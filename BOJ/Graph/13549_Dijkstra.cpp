/**
 * @file 13549_Dijkstra.cpp
 * @brief 00:19:07
 * @date 2024-07-26
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <bits/stdc++.h>
using namespace std;

#define INF 100000000

int N, K;
vector<vector<pair<int, int>>> graph;
vector<bool> visited;
vector<int> dist;
queue<int> q;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> K;
    graph.resize(200001);
    visited.resize(200001, false);
    dist.resize(200001, INF);

    visited[N] = true;
    q.push(N);
    while (!q.empty()) {
        int curr = q.front();
        q.pop();

        for (int t = curr * 2; t <= 200000 && t != curr; t *= 2)
            if (!visited[t]) {
                visited[t] = true;
                q.push(t);
                graph[curr].push_back({ t, 0 });
            }
        if (curr - 1 >= 0 && !visited[curr - 1]) {
            visited[curr - 1] = true;
            q.push(curr - 1);
            graph[curr].push_back({ curr - 1, 1 });
        }
        if (curr + 1 <= 200000 && !visited[curr + 1]) {
            visited[curr + 1] = true;
            q.push(curr + 1);
            graph[curr].push_back({ curr + 1, 1 });
        }
    }

    fill(visited.begin(), visited.end(), false);
    dist[N] = 0;
    pq.push({ 0, N });
    while (!pq.empty() && dist[K] == INF) {
        int w = pq.top().first, curr = pq.top().second;
        pq.pop();

        if (visited[curr]) continue;
        visited[curr] = true;

        for (pair<int, int>& p : graph[curr]) {
            int neighbor = p.first, nextw = p.second;
            if (w + nextw < dist[neighbor]) {
                dist[neighbor] = w + nextw;
                pq.push({ dist[neighbor], neighbor });
            }
        }
    }

    cout << dist[K];

    return 0;
}