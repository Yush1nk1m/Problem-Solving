#include <bits/stdc++.h>
using namespace std;

#define INF     100000000
#define BEGIN   0
#define V1      1
#define V2      2

int N, E, v1, v2, d = INF;
vector<vector<pair<int, int>>> graph;
vector<vector<int>> dist;

inline void Dijkstra(vector<int>& dist, int start);

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> E;
    graph.resize(N + 1);
    // 0: vertex 1, 1: v1, 2: v2
    dist.resize(3, vector<int>(N + 1, INF));

    for (int _ = 0; _ < E; _++) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({ b, c });
        graph[b].push_back({ a, c });
    }
    cin >> v1 >> v2;

    Dijkstra(dist[BEGIN], 1);
    Dijkstra(dist[V1], v1);
    Dijkstra(dist[V2], v2);

    d = min(d, dist[BEGIN][v1] + dist[V1][v2] + dist[V2][N]);
    d = min(d, dist[BEGIN][v2] + dist[V2][v1] + dist[V1][N]);

    if (d == INF)
        cout << -1;
    else
        cout << d;

    return 0;
}

inline void Dijkstra(vector<int>& dist, int start) {
    vector<bool> visited(N + 1, false);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    dist[start] = 0;
    pq.push({ 0, start });
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
}