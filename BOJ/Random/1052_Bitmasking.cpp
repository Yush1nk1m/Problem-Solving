/**
 * @file 1052_Bitmasking.cpp
 * @brief 00:33:38
 * @date 2024-09-07
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <bits/stdc++.h>
using namespace std;

#define INF 100000000

int N, K, mask, result = INF;

inline int CountBits(int mask);

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> K;

    mask = N;
    while (CountBits(mask) > K)
        mask++;

    cout << mask - N;

    return 0;
}

inline int CountBits(int mask) {
    int cnt = 0;
    for (int i = 0; i < 27; i++)
        if (mask & (1 << i))
            cnt++;
    return cnt;
}