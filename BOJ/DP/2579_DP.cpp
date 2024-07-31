/**
 * @file 2579_DP.cpp
 * @brief 00:33:54
 * @date 2024-07-31
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <bits/stdc++.h>
using namespace std;

#define NONE    -1
#define INF     10000000

int N;
vector<int> stair;
vector<vector<int>> table;

int DFS(int floor, int cnt);

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    stair.resize(N + 1, 0);
    for (int i = 1; i <= N; i++)
        cin >> stair[i];

    table.resize(N + 1, vector<int>(3, NONE));
    cout << DFS(0, 0);

    return 0;
}

int DFS(int floor, int cnt) {
    if (cnt == 3)
        return -INF;

    if (floor == N)
        return stair[N];
    else if (floor > N)
        return -INF;

    int& ret = table[floor][cnt];
    if (ret != NONE)
        return ret;

    ret = stair[floor] + max(DFS(floor + 1, cnt + 1), DFS(floor + 2, 1));

    return ret;
}