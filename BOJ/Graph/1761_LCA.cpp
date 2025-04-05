#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int N, M;
vector<int> depth;
vector<vector<pair<int, ll>>> parent;
vector<bool> visited;
vector<vector<pair<int, ll>>> graph;

inline void initializeTree();
inline ll getDistance(int u, int v);

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    graph = vector<vector<pair<int, ll>>>(N + 1);
    for (int _ = 0; _ < N - 1; _++) {
        int u, v;
        ll c;
        cin >> u >> v >> c;
        graph[u].push_back({ v, c });
        graph[v].push_back({ u, c });
    }

    initializeTree();

    cin >> M;
    while (M--) {
        int u, v;
        cin >> u >> v;
        cout << getDistance(u, v) << '\n';
    }

    return 0;
}

inline void initializeTree() {
    parent = vector<vector<pair<int, ll>>>(N + 1, vector<pair<int, ll>>(17, { 0, 0 }));
    depth = vector<int>(N + 1, 0);
    visited = vector<bool>(N + 1, false);

    queue<int> q;
    q.push(1);
    visited[1] = true;
    depth[1] = 0;
    while (!q.empty()) {
        int curr = q.front();
        q.pop();

        for (pair<int, ll>& ngbr : graph[curr])
            if (!visited[ngbr.first]) {
                q.push(ngbr.first);
                visited[ngbr.first] = true;
                depth[ngbr.first] = depth[curr] + 1;
                parent[ngbr.first][0] = { curr, ngbr.second };
            }
    }

    for (int k = 1; k <= 16; k++)
        for (int node = 1; node <= N; node++)
            if (floor(log2(depth[node])) >= k)
                parent[node][k] = { parent[parent[node][k-1].first][k-1].first, parent[node][k-1].second + parent[parent[node][k-1].first][k-1].second };
}

inline ll getDistance(int u, int v) {
    ll res = 0;
    int depthDiff, k;
    if (depth[u] < depth[v]) {
        depthDiff = depth[v] - depth[u];
        while (depthDiff) {
            k = floor(log2(depthDiff));
            res += parent[v][k].second;
            v = parent[v][k].first;
            depthDiff -= pow(2, k);
        }
    } else if (depth[u] > depth[v]) {
        depthDiff = depth[u] - depth[v];
        while (depthDiff) {
            k = floor(log2(depthDiff));
            res += parent[u][k].second;
            u = parent[u][k].first;
            depthDiff -= pow(2, k);
        }
    }

    // both of depths are equal
    while (u != v) {
        int k = floor(log2(depth[u]));
        while (k) {
            if (parent[u][k].first != parent[v][k].first)
                break;
            k--;
        }
        res += parent[u][k].second + parent[v][k].second;
        u = parent[u][k].first;
        v = parent[v][k].first;
    }

    return res;
}