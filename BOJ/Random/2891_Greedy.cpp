/**
 * @file 2891_Greedy.cpp
 * @brief 00:08:41
 * @date 2024-11-12
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <bits/stdc++.h>
using namespace std;

int N, S, R, result;
vector<int> cnt;

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> S >> R;
    cnt.resize(N + 1, 1);
    while (S--) {
        int n;
        cin >> n;
        cnt[n]--;
    }
    while (R--) {
        int n;
        cin >> n;
        cnt[n]++;
    }

    for (int i = 1; i <= N; i++)
        if (cnt[i] > 1) {
            if (cnt[i-1] == 0) {
                cnt[i-1]++;
                cnt[i]--;
            } else if (cnt[i+1] == 0) {
                cnt[i+1]++;
                cnt[i]--;
            }
        }
    
    for (int i = 1; i <= N; i++)
        if (cnt[i] == 0)
            result++;
    
    cout << result;

    return 0;
}