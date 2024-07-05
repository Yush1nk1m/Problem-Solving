/**
 * @file 14889_Bitmasking.cpp
 * @brief 00:17:37
 * @date 2024-07-06
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <bits/stdc++.h>
using namespace std;

#define INF 100000000

int N, mask, bound, minDiff = INF;
vector<vector<int>> S;

inline int CountBit(int mask);
inline int CalcDiff(int mask);

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    S.resize(N, vector<int>(N));
    for (int r = 0; r < N; r++)
        for (int c = 0; c < N; c++)
            cin >> S[r][c];
    
    mask = (1 << (N / 2)) - 1;
    bound = (1 << N);
    while (mask < bound) {
        if (CountBit(mask) == (N / 2))
            minDiff = min(minDiff, CalcDiff(mask));

        mask++;
    }

    cout << minDiff;

    return 0;
}

inline int CountBit(int mask) {
    int cnt = 0;
    for (int i = 0; i < N; i++)
        if (mask & (1 << i))
            cnt++;
    return cnt;
}

inline int CalcDiff(int mask) {
    vector<int> t0, t1;
    int s0 = 0, s1 = 0, tsize = N / 2;

    for (int i = 0; i < N; i++) {
        if (mask & (1 << i))
            t1.push_back(i);
        else
            t0.push_back(i);
    }

    for (int i = 0; i < tsize - 1; i++)
        for (int j = i + 1; j < tsize; j++) {
            s0 += (S[t0[i]][t0[j]] + S[t0[j]][t0[i]]);
            s1 += (S[t1[i]][t1[j]] + S[t1[j]][t1[i]]);
        }
    
    return abs(s0 - s1);
}