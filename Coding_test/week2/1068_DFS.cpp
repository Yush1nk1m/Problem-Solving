/**
 * @file 1068_DFS.cpp
 * @brief 00:15:53
 * @date 2024-06-28
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <bits/stdc++.h>
using namespace std;

int N, root, delNode, leafCnt;
vector<int> parent;
vector<vector<int>> graph;

void DFS(int node);

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    parent.resize(N);
    graph.resize(N);

    for (int i = 0; i < N; i++) {
        cin >> parent[i];
        if (parent[i] != -1) graph[parent[i]].push_back(i);
        else root = i;
    }
    
    cin >> delNode;
    if (delNode == root) {
        cout << 0;
        return 0;
    }

    DFS(root);
    cout << leafCnt;

    return 0;
}

void DFS(int node) {
    if (graph[node].empty()) {
        leafCnt++;
        return;
    }

    bool hasChild = false;
    for (int child : graph[node])
        if (child != delNode) {
            DFS(child);
            hasChild = true;
        }
    if (!hasChild) leafCnt++;
}