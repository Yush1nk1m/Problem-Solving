/**
 * @file 2098_DP.cpp
 * @brief 00:54:12
 * @date 2024-07-14
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <bits/stdc++.h>
using namespace std;

#define START 0
#define INF 1000000000
#define NONE -1

int N;
vector<vector<int>> W;
vector<vector<int>> table;

int TSP(int curr, int visited);

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    W.resize(N, vector<int>(N));
    table.resize(N, vector<int>(1 << N, NONE));
    for (int r = 0; r < N; r++)
        for (int c = 0; c < N; c++)
            cin >> W[r][c];

    cout << TSP(START, 1 << START);

    return 0;
}

int TSP(int curr, int visited) {
    if (visited == (1 << N) - 1)
        return (W[curr][START] > 0) ? W[curr][START] : INF;

    if (table[curr][visited] != NONE)
        return table[curr][visited];

    table[curr][visited] = INF;
    for (int nxt = 0; nxt < N; nxt++)
        if (!(visited & (1 << nxt)) && W[curr][nxt]) {
            table[curr][visited] = min(table[curr][visited], W[curr][nxt] + TSP(nxt, visited | (1 << nxt)));
        }
    return table[curr][visited];
}