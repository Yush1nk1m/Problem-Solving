/**
 * @file 11052_DP.cpp
 * @brief 00:21:16
 * @date 2024-07-30
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <bits/stdc++.h>
using namespace std;

#define INF     100000000
#define NONE    -1

int N;
vector<int> pack;
vector<vector<int>> table;

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    table.resize(N + 1, vector<int>(N + 1, 0));
    pack.resize(N + 1, 0);
    for (int i = 1; i <= N; i++)
        cin >> pack[i];

    for (int card = 1; card <= N; card++) {
        for (int cnt = 1; cnt < card; cnt++)
            table[card][cnt] = table[card-1][cnt];
        for (int cnt = card; cnt <= N; cnt++)
            table[card][cnt] = max(table[card-1][cnt], table[card][cnt-card] + pack[card]);
    }

    cout << table[N][N];

    return 0;
}