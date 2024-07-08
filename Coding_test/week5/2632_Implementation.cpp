/**
 * @file 2632.cpp
 * @brief 00:55:27
 * @date 2024-07-08
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll cnt;
int need, m, n;
int Asum[2000001], Bsum[2000001];
vector<int> A, B;

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> need >> m >> n;
    A.resize(m);
    B.resize(n);

    for (int i = 0; i < m; i++)
        cin >> A[i];

    for (int i = 0; i < n; i++)
        cin >> B[i];

    for (int window = 1; window < m; window++) {
        vector<int> v = A;
        for (int i = 0; i < m; i++) {
            Asum[accumulate(v.begin(), v.begin() + window, 0)]++;
            rotate(v.begin(), v.begin() + 1, v.end());
        }
    }
    Asum[0] = 1;
    Asum[accumulate(A.begin(), A.end(), 0)] = 1;

    for (int window = 1; window < n; window++) {
        vector<int> v = B;
        for (int i = 0; i < n; i++) {
            Bsum[accumulate(v.begin(), v.begin() + window, 0)]++;
            rotate(v.begin(), v.begin() + 1, v.end());
        }
    }
    Bsum[0] = 1;
    Bsum[accumulate(B.begin(), B.end(), 0)] = 1;

    for (int i = 0; i <= need; i++)
        cnt += (Asum[i] * Bsum[need - i]);

    cout << cnt;

    return 0;
}