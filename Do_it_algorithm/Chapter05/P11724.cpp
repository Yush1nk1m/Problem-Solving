#include <iostream>
#include <stack>
#include <vector>
using namespace std;

vector<vector<int>> graph;
vector<bool> visited;

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    graph.resize(N + 1);
    visited.resize(N + 1, false);

    for (int _ = 0; _ < M; _++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    int result = 0;
    for (int start = 1; start <= N; start++) {
        if (visited[start]) continue;
        
        stack<int> stk;
        visited[start] = true;
        stk.push(start);
        while (!stk.empty()) {
            int curr = stk.top();
            stk.pop();

            for (auto it = graph[curr].begin(); it != graph[curr].end(); it++)
                if (!visited[*it]) {
                    visited[*it] = true;
                    stk.push(*it);
                }
        }
        result++;
    }

    cout << result;

    return 0;
}