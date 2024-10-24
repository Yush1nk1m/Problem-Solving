#include <bits/stdc++.h>
using namespace std;

#define NONE    -1

int N, M, t;
vector<vector<int>> graph;
vector<int> times;
queue<int> q;

inline bool canBelieve(int node);

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    graph.resize(N + 1);
    times.resize(N + 1, NONE);

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
        vector<int> candidates;

        while (qsize--) {
            int curr = q.front();
            q.pop();
            
            for (int neighbor : graph[curr])
                if (times[neighbor] == NONE && canBelieve(neighbor)) {
                    candidates.push_back(neighbor);
                    q.push(neighbor);
                }
        }

        for (int c : candidates)
            times[c] = t;
    }

    for (int i = 1; i <= N; i++)
        cout << times[i] << ' ';
    
    return 0;
}

inline bool canBelieve(int node) {
    int cnt = 0;
    for (int neighbor : graph[node])
        if (times[neighbor] != NONE)
            cnt++;
    
    if (graph[node].size() % 2 == 0)
        return graph[node].size() / 2 <= cnt;
    else
        return graph[node].size() / 2 < cnt;
}