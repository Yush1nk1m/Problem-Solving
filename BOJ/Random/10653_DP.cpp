/**
 * @file 10653_DP.cpp
 * @brief 01:27:00
 * @date 2024-11-24
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

#define INF 100000000

int N, K;
vector<vector<vector<int>>> cache;
vector<pii> checkpoints;

inline int getDistance(int idx1, int idx2);
int dfs(int curr, int prev, int skip);

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> K;
    cache.resize(N, vector<vector<int>>(N, vector<int>(K + 1, INF)));
    checkpoints.resize(N);
    for (int i = 0; i < N; i++)
        cin >> checkpoints[i].first >> checkpoints[i].second;

    cout << dfs(1, 0, 0);

    return 0;
}

inline int getDistance(int idx1, int idx2) {
    if (idx1 >= N || idx2 >= N)
        return INF;

    return abs(checkpoints[idx1].first - checkpoints[idx2].first) + abs(checkpoints[idx1].second - checkpoints[idx2].second);
}

int dfs(int curr, int prev, int skip) {
    if (curr == N - 1 && skip <= K)
        return getDistance(curr, prev);
    else if (curr >= N || skip > K)
        return INF;

    int& ret = cache[curr][prev][skip];
    if (ret != INF)
        return ret;

    return ret = min(
        dfs(curr + 1, curr, skip) + getDistance(curr, prev),
        dfs(curr + 1, prev, skip + 1)
    );
}