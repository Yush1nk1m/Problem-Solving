/**
 * @file 10942_DP.cpp
 * @brief 00:25:41
 * @date 2024-07-19
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<int> sequence;
vector<vector<bool>> table;

inline void DP();

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    sequence.resize(N + 1, 0);
    table.resize(N + 1, vector<bool>(N + 1, false));

    for (int i = 1; i <= N; i++)
        cin >> sequence[i];

    DP();

    cin >> M;
    for (int _ = 0; _ < M; _++) {
        int s, e;
        cin >> s >> e;
        cout << table[s][e] << '\n';
    }

    return 0;
}

inline void DP() {
    for (int mid = 1; mid <= N; mid++) {
        for (int l = mid, r = mid; l > 0 && r <= N; l--, r++) {
            if (sequence[l] == sequence[r])
                table[l][r] = true;
            else
                break;
        }

        for (int l = mid, r = mid + 1; l > 0 && r <= N; l--, r++) {
            if (sequence[l] == sequence[r])
                table[l][r] = true;
            else
                break;
        }
    }
}