/**
 * @file 2776_BinarySearch.cpp
 * @brief 00:16:02
 * @date 2024-07-13
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <bits/stdc++.h>
using namespace std;

int T, N, M;

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> T;
    for (int _ = 0; _ < T; _++) {
        cin >> N;
        vector<int> note1(N);
        for (int i = 0; i < N; i++)
            cin >> note1[i];
        sort(note1.begin(), note1.end());

        cin >> M;
        vector<int> note2(M);
        for (int i = 0; i < M; i++)
            cin >> note2[i];

        for (int number : note2)
            cout << (*lower_bound(note1.begin(), note1.end(), number) == number) << '\n';
    }

    return 0;
}