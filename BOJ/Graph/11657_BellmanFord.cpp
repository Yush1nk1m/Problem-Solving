/**
 * @file 11657_BellmanFord.cpp
 * @brief 00:22:07
 * @date 2024-07-26
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define INF 1e15

int N, M;
vector<ll> dist;
vector<tuple<int, int, ll>> edgeList;

inline void BellmanFord();

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    dist.resize(N + 1, INF);
    for (int _ = 0; _ < M; _++) {
        int A, B;
        ll C;
        cin >> A >> B >> C;
        edgeList.push_back(make_tuple(A, B, C));
    }

    BellmanFord();

    return 0;
}

inline void BellmanFord() {
    dist[1] = 0;
    for (int _ = 0; _ < N - 1; _++)
        for (tuple<int, int, ll>& edge : edgeList) {
            int src = get<0>(edge), dest = get<1>(edge);
            ll weight = get<2>(edge);
            
            if (dist[src] != INF && dist[src] + weight < dist[dest])
                dist[dest] = dist[src] + weight;
        }
    
    for (tuple<int, int, ll>& edge : edgeList) {
        int src = get<0>(edge), dest = get<1>(edge);
        ll weight = get<2>(edge);

        if (dist[src] != INF && dist[src] + weight < dist[dest]) {
            cout << -1;
            return;
        }
    }

    for (int i = 2; i <= N; i++) {
        if (dist[i] != INF)
            cout << dist[i] << '\n';
        else
            cout << "-1\n";
    }
}