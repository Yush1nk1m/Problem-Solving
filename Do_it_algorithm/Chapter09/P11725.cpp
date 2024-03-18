#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    vector<vector<int>> graph(N + 1);
    vector<int> parents(N + 1, -1);

    for (int _ = 0; _ < N - 1; _++) {
        int node1, node2;
        cin >> node1 >> node2;

        graph[node1].push_back(node2);
        graph[node2].push_back(node1);
    }

    vector<bool> visited(N + 1, false);
    visited[1] = true;

    stack<int> nodes;
    nodes.push(1);
    while (!nodes.empty()) {
        int curr = nodes.top();

        bool hasChild = false;
        for (int child : graph[curr]) {
            if (!visited[child]) {
                hasChild = true;
                visited[child] = true;
                parents[child] = curr;
                nodes.push(child);
            }
        }

        if (!hasChild)
            nodes.pop();
    }

    for (int i = 2; i <= N; i++)
        cout << parents[i] << '\n';

    return 0;
}