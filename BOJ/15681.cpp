#include <bits/stdc++.h>
using namespace std;

int numNode, root, query;

vector<int> cnt;
vector<vector<int>> adjList;
vector<bool> visited;

int CountSubtree(int root) {
    visited[root] = true;
    cnt[root]++;
    bool isLeaf = true;

    for (int neighbor : adjList[root])
        if (!visited[neighbor]) {
            isLeaf = false;
            cnt[root] += CountSubtree(neighbor);
        }
    
    return cnt[root];
}

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> numNode >> root >> query;
    cnt.resize(numNode + 1, 0);
    adjList.resize(numNode + 1);
    visited.resize(numNode + 1, false);

    for (int _ = 0; _ < numNode - 1; _++) {
        int u, v;
        cin >> u >> v;

        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    CountSubtree(root);

    for (int _ = 0; _ < query; _++) {
        int u;
        cin >> u;
        cout << cnt[u] << '\n';
    }

    return 0;
}