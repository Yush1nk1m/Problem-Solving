/**
 * @file 3273_2Pointer.cpp
 * @brief 00:06:34
 * @date 2024-07-05
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <bits/stdc++.h>
using namespace std;

int n, x, l, r, cnt;
vector<int> seq;

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    seq.resize(n);
    for (int i = 0; i < n; i++)
        cin >> seq[i];
    cin >> x;

    sort(seq.begin(), seq.end());
    r = seq.size() - 1;
    while (l < r) {
        int sum = seq[l] + seq[r];
        if (sum < x) {
            l++;
        } else if (sum > x) {
            r--;
        } else {
            cnt++;
            l++;
            r--;
        }
    }

    cout << cnt;

    return 0;
}