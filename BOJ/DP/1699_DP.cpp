/**
 * @file 1699_DP.cpp
 * @brief 00:04:59
 * @date 2024-07-30
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <bits/stdc++.h>
using namespace std;
#define INF 100000000

int N;
vector<int> table;

int DFS(int number);

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    table.resize(N + 1, INF);
    cout << DFS(N);

    return 0;
}

int DFS(int number) {
    if (number < 0)
        return INF;
    else if (number == 0)
        return 0;

    int& ret = table[number];
    if (ret != INF)
        return ret;

    for (int i = sqrt(number); i > 0; i--)
        ret = min(ret, DFS(number - pow(i, 2)) + 1);

    return ret;
}