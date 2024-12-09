/**
 * @file 9370_Dijkstra.cpp
 * @brief 00:21:16
 * @date 2024-07-26
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <bits/stdc++.h>
using namespace std;

#define INF 100000000

int T, n, m, t, s, g, h;

vector<int> Solve();
vector<int> Dijkstra(vector<vector<pair<int, int>>>& graph, int n, int s);

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> T;
    for (int _ = 0; _ < T; _++) {
        vector<int> result = Solve();
        for (int dest : result)
            cout << dest << ' ';
        cout << '\n';
    }
}

vector<int> Solve() {
    int n, m, t, s, g, h;
    cin >> n >> m >> t >> s >> g >> h;

    vector<vector<pair<int, int>>> graph(n + 1);
    vector<int> candidates(t);
    vector<int> dest;

    for (int _ = 0; _ < m; _++) {
        int a, b, d;
        cin >> a >> b >> d;
        graph[a].push_back({ b, d });
        graph[b].push_back({ a, d });
    }

    for (int i = 0; i < t; i++)
        cin >> candidates[i];
    sort(candidates.begin(), candidates.end());

    vector<int> distS = Dijkstra(graph, n, s);
    vector<int> distG = Dijkstra(graph, n, g);
    vector<int> distH = Dijkstra(graph, n, h);

    for (int& c : candidates)
        if (distS[g] + distG[h] + distH[c] == distS[c] || distS[h] + distH[g] + distG[c] == distS[c])
            dest.push_back(c);

    return dest;
}

vector<int> Dijkstra(vector<vector<pair<int, int>>>& graph, int n, int s) {
    vector<int> dist(n + 1, INF);
    vector<bool> visited(n + 1, false);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    dist[s] = 0;
    pq.push({ 0, s });
    while (!pq.empty()) {
        int w = pq.top().first, curr = pq.top().second;
        pq.pop();

        if (visited[curr]) continue;
        visited[curr] = true;

        for (pair<int, int>& p : graph[curr]) {
            int neighbor = p.first, nextw = p.second;
            if (w + nextw < dist[neighbor]) {
                dist[neighbor] = w + nextw;
                pq.push({ w + nextw, neighbor });
            }
        }
    }

    return dist;
}