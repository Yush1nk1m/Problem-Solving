/**
 * @file 9084_DP.cpp
 * @brief 00:26:47
 * @date 2024-08-15
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <bits/stdc++.h>
using namespace std;

#define NONE    -1

int T, N, M;
vector<int> coin(21);
vector<vector<int>> table(10001, vector<int>(21));

int DFS(int total, int maxi);

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> T;
    while (T--) {
        cin >> N;
        fill(table.begin(), table.end(), vector<int>(21, NONE));
        for (int i = 1; i <= N; i++)
            cin >> coin[i];
        cin >> M;
        cout << DFS(0, 0) << '\n';
    }
}

int DFS(int total, int maxi) {
    if (total > M)
        return 0;
    else if (total == M)
        return 1;

    int& ret = table[total][maxi];
    if (ret != NONE)
        return ret;

    ret = 0;
    for (int i = maxi; i <= N; i++)
        ret += DFS(total + coin[i], i);

    return ret;
}