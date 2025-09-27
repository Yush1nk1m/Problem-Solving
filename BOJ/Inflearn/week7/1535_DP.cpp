/**
 * @file 1535_DP.cpp
 * @brief 00:08:56
 * @date 2024-07-16
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <bits/stdc++.h>
using namespace std;

int N;
vector<pair<int, int>> info;
vector<vector<int>> table;

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    info.resize(N + 1, { 0, 0 });
    for (int i = 1; i <= N; i++)   
        cin >> info[i].first;
    for (int i = 1; i <= N; i++)
        cin >> info[i].second;

    table.resize(N + 1, vector<int>(101, 0));
    for (int men = 1; men <= N; men++) {
        for (int hp = 1; hp <= info[men].first; hp++)
            table[men][hp] = table[men-1][hp];
        for (int hp = info[men].first + 1; hp <= 100; hp++)
            table[men][hp] = max(table[men-1][hp], table[men-1][hp-info[men].first] + info[men].second);
    }

    cout << table[N][100];

    return 0;
}