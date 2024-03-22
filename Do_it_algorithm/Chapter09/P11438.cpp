#include <iostream>
#include <cmath>
#include <stack>
#include <vector>
using namespace std;

void InitializeTable(vector<vector<int>>& table, vector<vector<int>>& graph, vector<int>& depth);
int LCA(vector<vector<int>>& table, vector<int>& depth, int node1, int node2);

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N;

    vector<vector<int>> graph(N + 1);
    int K = log2(N);
    vector<vector<int>> table(K + 1, vector<int>(N + 1, 0));
    vector<int> depth(N + 1, 0);
    
    for (int _ = 0; _ < N - 1; _++) {
        int v1, v2;
        cin >> v1 >> v2;

        graph[v1].push_back(v2);
        graph[v2].push_back(v1);
    }

    InitializeTable(table, graph, depth);
    
    cin >> M;

    for (int _ = 0; _ < M; _++) {
        int v1, v2;
        cin >> v1 >> v2;
        cout << LCA(table, depth, v1, v2) << '\n';
    }
}

void InitializeTable(vector<vector<int>>& table, vector<vector<int>>& graph, vector<int>& depth) {
    int K = table.size() - 1, N = table[0].size() - 1;

    stack<int> nodeStack;
    vector<bool> visited(N + 1, false);
    
    nodeStack.push(1);
    visited[1] = true;
    depth[1] = 0;
    while (!nodeStack.empty()) {
        int curr = nodeStack.top();
        bool isLeaf = true;

        for (int neighbor : graph[curr]) {
            if (!visited[neighbor]) {
                isLeaf = false;
                nodeStack.push(neighbor);
                visited[neighbor] = true;
                table[0][neighbor] = curr;
                depth[neighbor] = depth[curr] + 1;
                break;
            }
        }

        if (isLeaf) nodeStack.pop();
    }

    for (int k = 1; k <= K; k++)
        for (int node = 1; node <= N; node++)
            table[k][node] = table[k-1][table[k-1][node]];
}

int LCA(vector<vector<int>>& table, vector<int>& depth, int node1, int node2) {
    if (node1 == node2) return node1;

    int commonDepth;

    // 두 노드의 깊이를 동일하게 맞춘다.
    if (depth[node1] > depth[node2]) {
        commonDepth = depth[node2];
        int depthDiff = depth[node1] - depth[node2];

        while (depthDiff > 0) {
            int K = log2(depthDiff);
            depthDiff -= pow(2, K);
            node1 = table[K][node1];
        }
    }
    else {
        commonDepth = depth[node1];
        int depthDiff = depth[node2] - depth[node1];

        while (depthDiff > 0) {
            int K = log2(depthDiff);
            depthDiff -= pow(2, K);
            node2 = table[K][node2];
        }
    }

    if (node1 == node2) return node1;

    // 공통 부모를 찾아 올라간다.
    while (commonDepth > 0 && node1 != node2) {
        int K = log2(commonDepth);

        while (K > 0 && table[K][node1] == table[K][node2])
            K--;

        node1 = table[K][node1];
        node2 = table[K][node2];
        
        if (node1 != node2) {
            commonDepth -= pow(2, K);
        }
        else {
            break;
        }
    }

    return node1;
}