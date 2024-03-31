#include <iostream>
#include <vector>
#include <queue>
using namespace std;

static vector<vector<int>> graph;
static vector<bool> visited;
static vector<int> depth;

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    graph.resize(n + 1);
    visited.resize(n + 1);
    depth.resize(n + 1, 0);
    for (int _ = 0; _ < m; _++) {
        int src, dest;
        cin >> src >> dest;

        graph[src].push_back(dest);
        graph[dest].push_back(src);
    }

    queue<int> friends;
    int inviteNum = 0;

    visited[1] = true;
    friends.push(1);
    while (!friends.empty()) {
        int curr = friends.front();
        friends.pop();

        for (int neighbor : graph[curr]) {
            if (!visited[neighbor]) {
                depth[neighbor] = depth[curr] + 1;
                if (depth[neighbor] <= 2)
                    inviteNum++;
                visited[neighbor] = true;
                friends.push(neighbor);
            }
        }
    }

    cout << inviteNum;
    
    return 0;
}