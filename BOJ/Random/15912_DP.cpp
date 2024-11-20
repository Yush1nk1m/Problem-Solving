/**
 * @file 15912_DP.cpp
 * @brief 00:35:08
 * @date 2024-11-20
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <bits/stdc++.h>
using namespace std;

int N;
vector<pair<long, long>> items;
map<tuple<int, long, long>, long> cache;

long dfs(int order, long maxW, long maxE);

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    items.resize(N + 1);
    for (int i = 1; i <= N; i++)
        cin >> items[i].first;
    for (int i = 1; i <= N; i++)
        cin >> items[i].second;

    cout << dfs(1, 0, 0);
    
    return 0;
}

long dfs(int order, long maxW, long maxE) {
    if (order > N)
        return maxW * maxE;

    long currW = max(maxW, items[order].first);
    long currE = max(maxE, items[order].second);

    if (cache.find(make_tuple(order, currW, currE)) != cache.end())
        return cache[make_tuple(order, currW, currE)];

    // purchase now vs. future
    long minValue = min(currW * currE + dfs(order + 1, 0, 0), dfs(order + 1, currW, currE));
    cache[make_tuple(order, currW, currE)] = minValue;

    return minValue;
}