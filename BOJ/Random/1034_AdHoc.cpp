/**
 * @file 1034_AdHoc.cpp
 * @brief 00:45:59
 * @date 2024-09-14
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <bits/stdc++.h>
using namespace std;

#define OFF '0'
#define ON  '1'
#define INF 100000000

int N, M, K;
vector<vector<char>> lamps;
map<vector<char>, int> m;

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    lamps.resize(N, vector<char>(M));
    for (int r = 0; r < N; r++)
        for (int c = 0; c < M; c++)
            cin >> lamps[r][c];
    cin >> K;

    for (vector<char>& row : lamps) {
        int offs = 0;
        for (char lamp : row)
            offs += (lamp == OFF);

        if (offs <= K && K % 2 == offs % 2) {
            if (m.find(row) == m.end())
                m[row] = 1;
            else
                m[row]++;
        }
    }

    int ret = 0;
    for (auto it = m.begin(); it != m.end(); it++)
        ret = max(ret, it->second);
    cout << ret;

    return 0;
}