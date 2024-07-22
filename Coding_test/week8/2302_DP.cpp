/**
 * @file 2302_DP.cpp
 * @brief 00:10:24
 * @date 2024-07-23
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int N, M;
ll result = 1;
vector<bool> vip;
vector<ll> table;

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    vip.resize(N + 1, false);
    table.resize(N + 1, 0);
    for (int _ = 0; _ < M; _++) {
        int v;
        cin >> v;
        vip[v] = true;
    }

    int i = 1;
    while (i <= N) {
        if (!vip[i]) {
            // first term
            if (i - 1 <= 0 || vip[i-1])
                table[i++] = 1;
            // second term
            else if (i - 2 <= 0 || vip[i-2])
                table[i++] = 2;
            // g.e. third term
            else
                table[i++] = table[i-1] + table[i-2];
        }
        else {
            if (table[i-1] > 0)
                result *= table[i-1];
            i++;
        }
    }
    if (table[N] > 0)
        result *= table[N];

    cout << result;

    return 0;
}