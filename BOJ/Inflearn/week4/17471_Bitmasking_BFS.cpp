/**
 * @file 17471_Bitmasking_BFS.cpp
 * @brief 00:32:30
 * @date 2024-07-01
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <bits/stdc++.h>
using namespace std;

#define INF 100000000

int N, minDiff = INF;
vector<int> population;
vector<vector<bool>> graph;

inline bool Connect(vector<int>& group);
inline int Count(vector<int>& group);
inline void FindMinDiff();

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    
    population.resize(N);
    for (int i = 0; i < N; i++)
        cin >> population[i];

    graph.resize(N, vector<bool>(N, false));
    for (int r = 0; r < N; r++) {
        int adj;
        cin >> adj;
        for (int _ = 0; _ < adj; _++) {
            int c;
            cin >> c;
            graph[r][c-1] = true;
            graph[c-1][r] = true;
        }
    }

    FindMinDiff();
    if (minDiff == INF) cout << -1;
    else cout << minDiff;

    return 0;
}

inline bool Connect(vector<int>& group) {
    vector<bool> visited(group.size(), false);
    queue<int> q;

    visited[0] = true;
    q.push(group[0]);
    while (!q.empty()) {
        int curr = q.front();
        q.pop();

        for (int i = 0; i < group.size(); i++) {
            if (!visited[i] && graph[curr][group[i]]) {
                visited[i] = true;
                q.push(group[i]);
            }
        }
    }

    return (accumulate(visited.begin(), visited.end(), 0) == group.size());
}

inline int Count(vector<int>& group) {
    int cnt = 0;
    for (int node : group)
        cnt += population[node];
    return cnt;
}

inline void FindMinDiff() {
    int mask = 1, bound = (1 << N) - 1;
    while (mask < bound) {
        vector<int> g0, g1;

        for (int s = 0; s < N; s++) {
            if (mask & (1 << s)) g1.push_back(s);
            else g0.push_back(s);
        }

        if (Connect(g0) && Connect(g1)) {
            int diff = abs(Count(g0) - Count(g1));
            minDiff = min(minDiff, diff);
        }

        mask++;
    }
}