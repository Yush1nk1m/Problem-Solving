#include <iostream>
#include <vector>
#include <queue>
using namespace std;

static int N, M;
static vector<int> incomingCount;
static vector<vector<int>> graph;
static vector<int> result;
static queue<int> nodes;

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    incomingCount.resize(N + 1, 0);
    graph.resize(N + 1);

    for (int _ = 0; _ < M; _++) {
        int numNode;
        cin >> numNode;

        int from, to;
        cin >> from;
        
        for (int i = 1; i < numNode; i++) {
            cin >> to;

            incomingCount[to]++;
            graph[from].push_back(to);
            
            from = to;
        }
    }

    for (int i = 1; i <= N; i++)
        if (incomingCount[i] == 0)
            nodes.push(i);
    
    while (!nodes.empty()) {
        int curr = nodes.front();
        result.push_back(curr);
        nodes.pop();

        for (int next : graph[curr]) {
            incomingCount[next]--;

            if (incomingCount[next] == 0) {
                nodes.push(next);
            }
        }
    }

    bool isValid = true;
    for (int i = 1; i <= N; i++)
        if (incomingCount[i] > 0)
            isValid = false;
    
    if (!isValid) {
        cout << 0;
    } else {
        for (int node : result)
            cout << node << '\n';
    }

    return 0;
}