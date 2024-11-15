#include <bits/stdc++.h>
using namespace std;

#define INF 100000000

int n, m, q;
vector<vector<int>> graph;

inline void solve();

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    graph.resize(n + 1);
    while (m--) {
        int c1, c2;
        cin >> c1 >> c2;
        graph[c1].push_back(c2);
        graph[c2].push_back(c1);
    }

    cin >> q;
    while (q--) {
        int i, j;
        cin >> i >> j;
        graph[i].push_back(j);
        graph[j].push_back(i);

        solve();
    }

    return 0;
}

inline void solve() {
    queue<int> q;
    vector<int> dist(n + 1, -1);

    dist[1] = 0;
    q.push(1);
    while (!q.empty()) {
        int curr = q.front();
        q.pop();

        for (int neighbor : graph[curr])
            if (dist[neighbor] == -1) {
                dist[neighbor] = dist[curr] + 1;
                q.push(neighbor);
            }
    }

    for (int i = 1; i <= n; i++)
        cout << dist[i] << ' ';
    cout << '\n';
}