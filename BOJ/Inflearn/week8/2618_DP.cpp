/**
 * @file 2618_DP.cpp
 * @brief 01:09:01
 * @date 2024-07-22
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <bits/stdc++.h>
using namespace std;

#define INF 1000000000

int N, W;
vector<vector<int>> table;      // [max case number of car1][max case number of car2]
vector<pair<int, int>> crime;

int DFS(int max1, int max2, pair<int, int> car1, pair<int, int> car2);
void TraceRoute(int max1, int max2, pair<int, int> car1, pair<int, int> car2);

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> W;
    table.resize(W + 1, vector<int>(W + 1, INF));
    crime.resize(W + 1);
    for (int i = 1; i <= W; i++)
        cin >> crime[i].first >> crime[i].second;

    cout << DFS(0, 0, {1, 1}, {N, N}) << '\n';
    TraceRoute(0, 0, {1, 1}, {N, N});    

    return 0;
}

int DFS(int max1, int max2, pair<int, int> car1, pair<int, int> car2) {
    if (max1 == W || max2 == W)
        return 0;

    if (table[max1][max2] != INF)
        return table[max1][max2];

    int c = max(max1, max2) + 1;
    int& ret = table[max1][max2];
    
    int d1 = abs(car1.first - crime[c].first) + abs(car1.second - crime[c].second);
    ret = min(ret, DFS(c, max2, crime[c], car2) + d1);

    int d2 = abs(car2.first - crime[c].first) + abs(car2.second - crime[c].second);
    ret = min(ret, DFS(max1, c, car1, crime[c]) + d2);

    return ret;
}

void TraceRoute(int max1, int max2, pair<int, int> car1, pair<int, int> car2) {
    if (max1 == W || max2 == W)
        return;

    int c = max(max1, max2) + 1;
    int d1 = abs(car1.first - crime[c].first) + abs(car1.second - crime[c].second);
    int d2 = abs(car2.first - crime[c].first) + abs(car2.second - crime[c].second);

    if (table[c][max2] + d1 <= table[max1][c] + d2) {
        cout << "1\n";
        TraceRoute(c, max2, crime[c], car2);
    } else {
        cout << "2\n";
        TraceRoute(max1, c, car1, crime[c]);
    }
}