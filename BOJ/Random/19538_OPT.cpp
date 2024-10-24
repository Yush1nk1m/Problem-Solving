#include <bits/stdc++.h>
using namespace std;

#define NONE    -1

int N, M, t;
vector<vector<int>> graph;
vector<int> inDegree;
vector<int> times;
queue<int> q;

inline bool canBelieve(int neighbor);

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    
    graph.resize(N + 1);
    times.resize(N + 1, NONE);
    inDegree.resize(N + 1, 0);

    for (int i = 1; i <= N; i++) {
        int neighbor;
        while (cin >> neighbor) {
            if (neighbor == 0)
                break;
            graph[i].push_back(neighbor);
        }
    }

    cin >> M;
    while (M--) {
        int trigger;
        cin >> trigger;
        times[trigger] = 0;
        q.push(trigger);
    }

    while (!q.empty()) {
        t++;

        int qsize = q.size();
        while (qsize--) {
            int curr = q.front();
            q.pop();

            for (int neighbor : graph[curr])
                if (times[neighbor] == NONE && canBelieve(neighbor)) {
                    times[neighbor] = t;
                    q.push(neighbor);
                }
        }
    }

    for (int i = 1; i <= N; i++)
        cout << times[i] << ' ';

    return 0;
}

inline bool canBelieve(int neighbor) {
    int gsize = graph[neighbor].size();
    inDegree[neighbor]++;

    if (gsize % 2 == 0)
        return gsize / 2 <= inDegree[neighbor];
    else
        return gsize / 2 < inDegree[neighbor];
}