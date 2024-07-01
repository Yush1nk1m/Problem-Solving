/**
 * @file 1285_Bitmasking_Bruteforce.cpp
 * @brief 01:26:30
 * @date 2024-07-01
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <bits/stdc++.h>
using namespace std;

#define INF 100000000

int call;
int N, minT = INF;
vector<int> coin;

inline int CountRow(int r);
inline int CountCol(int c);
inline void FlipRow(int r);
inline void FlipCol(int c);
inline void Combination();

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    coin.resize(N, 0);
    for (int r = 0; r < N; r++)
        for (int c = 0; c < N; c++) {
            char co;
            cin >> co;
            if (co == 'T')
                coin[r] |= (1 << c);
        }

    Combination();
    cout << minT;

    return 0;
}

inline int CountRow(vector<int>& mask, int r) {
    int cnt = 0;
    for (int c = 0; c < N; c++)
        if (mask[r] & (1 << c))
            cnt++;
    return cnt;
}

inline int CountCol(vector<int>& mask, int c) {
    int cnt = 0;
    for (int r = 0; r < N; r++)
        if (mask[r] & (1 << c))
            cnt++;
    return cnt;
}

inline void FlipRow(vector<int>& mask, int r) {
    mask[r] ^= (1 << N) - 1;
}

inline void FlipCol(vector<int>& mask, int c) {
    for (int r = 0; r < N; r++)
        mask[r] ^= (1 << c);
}

inline void Combination() {
    int mask = 0, bound = 1 << N;
    while (mask < bound) {
        vector<int> v = coin;
        for (int s = 0; s < N; s++)
            if (mask & (1 << s))
                FlipRow(v, s);
        
        int t = 0;
        for (int c = 0; c < N; c++) {
            int colcnt = CountCol(v, c);
            t += min(colcnt, N - colcnt);
        }
        minT = min(minT, t);

        mask++;
    }
}