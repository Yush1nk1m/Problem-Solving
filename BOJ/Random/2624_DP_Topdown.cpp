#include <bits/stdc++.h>
using namespace std;

#define NONE    -1

int T, k;
vector<pair<int, int>> coin;
vector<vector<int>> table;

int DFS(int value, int maxIdx);

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> T >> k;
    coin.resize(k);
    for (int i = 0; i < k; i++)
        cin >> coin[i].first >> coin[i].second;

    table.resize(T + 1, vector<int>(k, NONE));
    cout << DFS(T, 0);

    return 0;
}

int DFS(int value, int maxIdx) {
    if (value == 0) {
        return 1;
    } else if (value < 0 || maxIdx >= k) {
        return 0;
    }

    int& ret = table[value][maxIdx];
    if (ret != NONE) {
        return ret;
    }

    ret = 0;
    int thisCoin = coin[maxIdx].first;
    for (int cnt = coin[maxIdx].second; cnt >= 0; cnt--)
        ret += DFS(value - (thisCoin * cnt), maxIdx + 1);

    return ret;
}