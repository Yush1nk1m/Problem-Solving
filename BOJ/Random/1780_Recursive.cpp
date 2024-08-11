/**
 * @file 1780_Recursive.cpp
 * @brief 00:19:35
 * @date 2024-08-11
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <bits/stdc++.h>
using namespace std;

int N;
vector<vector<int>> paper;
map<int, int> cnt;

// [(r1, c1), (r2, c2))
void Split(int r1, int c1, int r2, int c2);
inline bool CheckSame(int r1, int c1, int r2, int c2);

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cnt[-1] = cnt[0] = cnt[1] = 0;

    cin >> N;
    paper.resize(N, vector<int>(N));

    for (int r = 0; r < N; r++)
        for (int c = 0; c < N; c++)
            cin >> paper[r][c];

    Split(0, 0, N, N);

    for (int i = -1; i <= 1; i++)
        cout << cnt[i] << '\n';

    return 0;
}

void Split(int r1, int c1, int r2, int c2) {
    if (CheckSame(r1, c1, r2, c2)) {
        cnt[paper[r1][c1]]++;
        return;
    }

    int interval = (r2 - r1) / 3;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            Split(r1 + (interval * i), c1 + (interval * j), r1 + (interval * (i + 1)), c1 + (interval * (j + 1)));
}

inline bool CheckSame(int r1, int c1, int r2, int c2) {
    int base = paper[r1][c1];
    for (int r = r1; r < r2; r++)
        for (int c = c1; c < c2; c++)
            if (paper[r][c] != base)
                return false;
    return true;
}