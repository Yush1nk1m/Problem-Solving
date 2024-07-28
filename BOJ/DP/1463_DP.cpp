/**
 * @file 1463_DP.cpp
 * @brief 00:09:16
 * @date 2024-07-28
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <bits/stdc++.h>
using namespace std;

#define INF     100000000

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
    if (number < 1)
        return INF;
    if (number == 1)
        return 0;

    int& ret = table[number];
    if (ret != INF)
        return ret;

    if (number % 3 == 0)
        ret = min(ret, DFS(number / 3) + 1);
    if (number % 2 == 0)
        ret = min(ret, DFS(number / 2) + 1);
    ret = min(ret, DFS(number - 1) + 1);

    return ret;
}