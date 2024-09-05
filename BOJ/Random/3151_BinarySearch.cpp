/**
 * @file 3151_BinarySearch.cpp
 * @brief 00:36:21
 * @date 2024-09-04
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int N;
ll cnt;
vector<int> A;

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    A.resize(N);
    for (int i = 0; i < N; i++)
        cin >> A[i];
    sort(A.begin(), A.end());

    for (int i1 = 0; i1 < N - 1; i1++)
        for (int i2 = i1 + 1; i2 < N; i2++) {
            int target = -(A[i1] + A[i2]);
            int sidx = lower_bound(A.begin() + i2, A.end(), target) - A.begin();
            int eidx = upper_bound(A.begin() + i2, A.end(), target) - A.begin();
            
            if (sidx != eidx) {
                cnt += (eidx - sidx - (sidx <= i1 && i1 <= eidx) - (sidx <= i2 && i2 <= eidx));
            }
        }

    cout << cnt;

    return 0;
}