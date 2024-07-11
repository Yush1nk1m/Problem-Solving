/**
 * @file 7795_BinarySearch.cpp
 * @brief 00:11:36
 * @date 2024-07-12
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <bits/stdc++.h>
using namespace std;

int T, N, M;
vector<int> A, B;

inline int CountEdible(int size);

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> T;
    for (int _ = 0; _ < T; _++) {
        cin >> N >> M;
        A.resize(N);
        for (int i = 0; i < N; i++)
            cin >> A[i];
        sort(A.begin(), A.end());

        B.resize(M);
        for (int i = 0; i < M; i++)
            cin >> B[i];
        sort(B.begin(), B.end());

        int cnt = 0;
        for (int size : A)
            cnt += CountEdible(size);
        cout << cnt << '\n';
    }

    return 0;
}

inline int CountEdible(int size) {
    return (lower_bound(B.begin(), B.end(), size) - B.begin());
}