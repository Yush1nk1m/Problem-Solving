/**
 * @file 14567_TopoSort.cpp
 * @brief 00:15:53
 * @date 2024-08-23
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <bits/stdc++.h>
using namespace std;

int N, M, sem = 1;
vector<vector<int>> graph;
vector<int> indegree;
vector<int> semester;
queue<int> q;

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    graph.resize(N + 1);
    indegree.resize(N + 1, 0);
    semester.resize(N + 1);
    while (M--) {
        int A, B;
        cin >> A >> B;
        graph[A].push_back(B);
        indegree[B]++;
    }

    for (int node = 1; node <= N; node++)
        if (indegree[node] == 0) {
            semester[node] = sem;
            q.push(node);
        }

    while (!q.empty()) {
        sem++;
        int qsize = q.size();
        while (qsize--) {
            int curr = q.front();
            q.pop();

            for (int neighbor : graph[curr]) {
                indegree[neighbor]--;
                if (indegree[neighbor] == 0) {
                    semester[neighbor] = sem;
                    q.push(neighbor);
                }
            }
        }
    }

    for (int node = 1; node <= N; node++)
        cout << semester[node] << ' ';

    return 0;
}