#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<int> inDegree;
vector<vector<int>> graph;
priority_queue<int, vector<int>, greater<int>> pq;

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    graph.resize(N + 1);
    inDegree.resize(N + 1, 0);
    while (M--) {
        int A, B;
        cin >> A >> B;
        graph[A].push_back(B);
        inDegree[B]++;
    }

    for (int i = 1; i <= N; i++)
        if (inDegree[i] == 0)
            pq.push(i);
    
    while (!pq.empty()) {
        int curr = pq.top();
        pq.pop();
        cout << curr << ' ';

        for (int ngbr : graph[curr])
            if (--inDegree[ngbr] == 0)
                pq.push(ngbr);
    }

    return 0;
}