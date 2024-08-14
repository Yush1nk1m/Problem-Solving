/**
 * @file 1446_DP.cpp
 * @brief 00:12:51
 * @date 2024-08-14
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <bits/stdc++.h>
using namespace std;

#define INF 10000000

class Path {
    public:
        int start;
        int end;
        int cost;
};

int N, D;
vector<Path> path;
vector<int> table;

int DFS(int curr);

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> D;
    path.resize(N);
    for (int i = 0; i < N; i++)
        cin >> path[i].start >> path[i].end >> path[i].cost;

    table.resize(D, INF);
    cout << DFS(0);

    return 0;
}

int DFS(int curr) {
    if (curr > D)
        return INF;
    else if (curr == D)
        return 0;

    int& ret = table[curr];
    if (ret != INF)
        return ret;

    for (Path& p : path)
        if (curr <= p.start)
            ret = min(ret, DFS(p.end) + p.cost + (p.start - curr));
    ret = min(ret, DFS(D) + (D - curr));

    return ret;
}