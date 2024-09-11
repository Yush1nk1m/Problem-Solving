/**
 * @file 17829_Recursive.cpp
 * @brief 00:09:53
 * @date 2024-09-11
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <bits/stdc++.h>
using namespace std;

int N;
vector<vector<int>> matrix;

int getMax(int r1, int c1, int r2, int c2);

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    matrix.resize(N, vector<int>(N));
    for (int r = 0; r < N; r++)
        for (int c = 0; c < N; c++)
            cin >> matrix[r][c];

    cout << getMax(0, 0, N, N);

    return 0;
}

int getMax(int r1, int c1, int r2, int c2) {
    if (r1 + 1 == r2 && c1 + 1 == c2)
        return matrix[r1][c1];

    int rmid = (r1 + r2) / 2;
    int cmid = (c1 + c2) / 2;

    vector<int> res;
    res.push_back(getMax(r1, c1, rmid, cmid));
    res.push_back(getMax(r1, cmid, rmid, c2));
    res.push_back(getMax(rmid, c1, r2, cmid));
    res.push_back(getMax(rmid, cmid, r2, c2));
    sort(res.rbegin(), res.rend());
    return res[1];
}