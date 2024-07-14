/**
 * @file 4811_DP.cpp
 * @brief 01:03:34
 * @date 2024-07-14
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int N;
vector<vector<ll>> table(31, vector<ll>(31, 0));

ll DFS(int whole, int half);

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    table[0][0] = 1;
    DFS(30, 0);

    while (cin >> N) {
        if (N == 0) break;
        cout << table[N][0] << '\n';
    }

    return 0;
}

ll DFS(int whole, int half) {
    if (table[whole][half] > 0)
        return table[whole][half];

    if (whole > 0)
        table[whole][half] += DFS(whole - 1, half + 1);
    if (half > 0)
        table[whole][half] += DFS(whole, half - 1);

    return table[whole][half];
}