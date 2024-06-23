/**
 * @file 2559_PrefixSum.cpp
 * @brief 00:11:41
 * @date 2024-06-23
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <bits/stdc++.h>
using namespace std;

int N, K, maxTemp = -100000000;
vector<int> temps;

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> K;

    temps.resize(N + 1, 0);
    for (int i = 1; i <= N; i++)
        cin >> temps[i];

    for (int i = 2; i <= N; i++)
        temps[i] += temps[i-1];

    for (int start = 0; start <= N - K; start++)
        maxTemp = max(maxTemp, temps[start + K] - temps[start]);
    
    cout << maxTemp;

    return 0;
}