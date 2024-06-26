/**
 * @file 1992_Recursive.cpp
 * @brief 00:24:54
 * @date 2024-06-26
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <bits/stdc++.h>
using namespace std;

int N;
vector<vector<char>> tree;

string Compress(int r1, int c1, int r2, int c2);

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    tree.resize(N, vector<char>(N));
    
    for (int r = 0; r < N; r++)
        for (int c = 0; c < N; c++)
            cin >> tree[r][c];

    cout << Compress(0, 0, N, N);

    return 0;
}

string Compress(int r1, int c1, int r2, int c2) {
    if (r1 + 1 == r2 && c1 + 1 == c2) {
        if (tree[r1][c1] == '0') return "0";
        else return "1";
    }

    int cnt[2] = { 0, 0 };
    for (int r = r1; r < r2; r++)
        for (int c = c1; c < c2; c++)
            cnt[tree[r][c] - '0']++;
    
    if (cnt[0] == 0) return "1";
    else if (cnt[1] == 0) return "0";
    else {
        int rm = (r1 + r2) / 2;
        int cm = (c1 + c2) / 2;

        return "(" +
            Compress(r1, c1, rm, cm) +
            Compress(r1, cm, rm, c2) +
            Compress(rm, c1, r2, cm) +
            Compress(rm, cm, r2, c2) +
            ")";
    }
}