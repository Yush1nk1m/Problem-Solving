/**
 * @file 17209_BipartiteGraph.cpp
 * @brief 01:14:44
 * @date 2024-11-23
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <bits/stdc++.h>
using namespace std;

#define OLDBIE  true
#define NEWBIE  false

int N, cnt;
vector<bool> visited;
vector<vector<int>> graph;

pair<int, int> dfs(int root, bool type);

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    visited.resize(N + 1, false);
    graph.resize(N + 1);
    for (int r = 1; r <= N; r++)
        for (int c = 1; c <= N; c++) {
            char input;
            cin >> input;
            if (input == '1') {
                graph[r].push_back(c);
                graph[c].push_back(r);
            }
        }

    for (int p = 1; p <= N; p++)
        if (!visited[p]) {
            pair<int, int> res = dfs(p, OLDBIE);
            cnt += max(res.first, res.second);
        }

    cout << cnt;

    return 0;
}

pair<int, int> dfs(int root, bool type) {
    visited[root] = true;

    int oldbie = 0, newbie = 0;
    if (type) oldbie++;
    else newbie++;
    for (int ngbr : graph[root])
        if (!visited[ngbr]) {
            pair<int, int> res = dfs(ngbr, !type);
            oldbie += res.first;
            newbie += res.second;
        }
    
    return make_pair(oldbie, newbie);
}