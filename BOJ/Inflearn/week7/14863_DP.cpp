/**
 * @file 14863_DP.cpp
 * @brief 00:51:04
 * @date 2024-07-21
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define INF 1000000000

class Cost {
    public:
        int cost1;
        int money1;
        int cost2;
        int money2;
};

int N, K;
vector<Cost> cost;
vector<vector<ll>> table;

ll DFS(int city, ll totalCost);

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> K;

    cost.resize(N + 1, { 0, 0, 0, 0 });
    for (int i = 1; i <= N; i++)
        cin >> cost[i].cost1 >> cost[i].money1 >> cost[i].cost2 >> cost[i].money2;

    table.resize(N + 1, vector<ll>(K + 1, 0));
    cout << DFS(1, 0);

    return 0;
}

ll DFS(int city, ll totalCost) {
    if (city > N)
        return 0;

    if (table[city][totalCost] > 0)
        return table[city][totalCost];

    ll& ret = table[city][totalCost];
    bool isValid = false;

    if (totalCost + cost[city].cost1 <= K) {
        isValid = true;
        ret = max(ret, DFS(city + 1, totalCost + cost[city].cost1) + cost[city].money1);
    }
    if (totalCost + cost[city].cost2 <= K) {
        isValid = true;
        ret = max(ret, DFS(city + 1, totalCost + cost[city].cost2) + cost[city].money2);
    }

    if (!isValid)
        return -INF;
    else
        return ret;
}