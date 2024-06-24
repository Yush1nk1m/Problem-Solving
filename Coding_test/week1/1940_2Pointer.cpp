/**
 * @file 1940_2Pointer.cpp
 * @brief 00:05:29
 * @date 2024-06-24
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include <bits/stdc++.h>
using namespace std;

int N, M, cnt;
vector<int> materials;

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    materials.resize(N);
    for (int i = 0; i < N; i++)
        cin >> materials[i];

    sort(materials.begin(), materials.end());

    int pf = 0, pr = N - 1;
    while (pf < pr) {
        int sum = materials[pf] + materials[pr];

        if (sum > M) pr--;
        else if (sum < M) pf++;
        else {
            cnt++;
            pf++;
            pr--;
        }
    }

    cout << cnt;

    return 0;
}