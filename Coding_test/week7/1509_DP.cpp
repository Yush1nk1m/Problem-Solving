/**
 * @file 1509_DP.cpp
 * @brief 00:49:10
 * @date 2024-07-19
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <bits/stdc++.h>
using namespace std;

#define INF     100000000

int N;
string input;
vector<vector<bool>> pd;
map<int, int> cnt;

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> input;
    N = input.length();
    pd.resize(N, vector<bool>(N, false));

    for (int mid = 0; mid < N; mid++) {
        for (int l = mid, r = mid; l >= 0 && r < N; l--, r++) {
            if (input[l] == input[r])
                pd[l][r] = true;
            else
                break;
        }

        for (int l = mid, r = mid + 1; l >= 0 && r < N; l--, r++) {
            if (input[l] == input[r])
                pd[l][r] = true;
            else
                break;
        }
    }

    cnt[-1] = 0;
    for (int i = 0; i < N; i++)
        cnt[i] = INF;

    for (int e = 0; e < N; e++)
        for (int s = 0; s <= e; s++)
            if (pd[s][e])
                cnt[e] = min(cnt[e], cnt[s-1] + 1);

    cout << cnt[N-1];

    return 0;
}
