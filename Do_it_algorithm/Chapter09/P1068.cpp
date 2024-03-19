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

    vector<vector<bool>> graph(N, vector<bool>(N, false));
    vector<int> parents(N);
    int root;

    for (int child = 0; child < N; child++) {
        int parent;
        cin >> parent;

        parents[child] = parent;

        if (parent != -1)
            graph[parent][child] = true;
        else
            root = child;
    }

    int delNode;
    cin >> delNode;
    
    if (parents[delNode] != -1)
        graph[parents[delNode]][delNode] = false;
    else {
        cout << 0;
        return 0;
    }

    vector<int> numChilds(N, 0);
    vector<bool> visited(N, false);
    stack<int> dfsStk;

    numChilds[delNode] = -1;
    dfsStk.push(root);
    visited[root] = true;
    while (!dfsStk.empty()) {
        int curr = dfsStk.top();
        bool hasChild = false;

        for (int child = 0; child < N; child++) {
            if (graph[curr][child] && !visited[child]) {
                dfsStk.push(child);
                visited[child] = true;
                hasChild = true;
                numChilds[curr]++;
                break;
            }
        }

        if (!hasChild)
            dfsStk.pop();
    }

    int count = 0;
    for (int node = 0; node < N; node++)
        if (visited[node] && numChilds[node] == 0)
            count++;

    cout << count;

    return 0;
}