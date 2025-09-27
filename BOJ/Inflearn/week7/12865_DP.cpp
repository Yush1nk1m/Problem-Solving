/**
 * @file 12865_DP.cpp
 * @brief 00:12:38
 * @date 2024-07-15
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <bits/stdc++.h>
using namespace std;

int N, K;
vector<pair<int, int>> item;
vector<vector<int>> table;

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> K;
    item.resize(N + 1, { 0, 0 });
    table.resize(N + 1, vector<int>(K + 1, 0));

    for (int i = 1; i <= N; i++)
        cin >> item[i].first >> item[i].second;
    sort(item.begin(), item.end());

    for (int i = 1; i <= N; i++) {
        for (int w = 1; w < item[i].first; w++)
            table[i][w] = table[i-1][w];
        for (int w = item[i].first; w <= K; w++)
            table[i][w] = max(table[i-1][w], table[i-1][w-item[i].first] + item[i].second);
    }

    cout << table[N][K];

    return 0;
}