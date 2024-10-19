/**
 * @file 3649_TwoPointer.cpp
 * @brief 00:12:02
 * @date 2024-10-19
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <bits/stdc++.h>
using namespace std;

inline void solve(int x, int n, vector<int>& l);

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int x, n;
    vector<int> l;
    while (cin >> x) {
        x *= 10000000;
        cin >> n;
        l = vector<int>(n);
        for (int i = 0; i < n; i++)
            cin >> l[i];
        solve(x, n, l);
    }

    return 0;
}

inline void solve(int x, int n, vector<int>& l) {
    int left = 0, right = l.size() - 1;
    sort(l.begin(), l.end());

    while (left < right) {
        if (l[left] + l[right] < x) {
            left++;
        } else if (l[left] + l[right] > x) {
            right--;
        } else {
            cout << "yes " << l[left] << ' ' << l[right] << '\n';
            return;
        }
    }
    cout << "danger\n";
}