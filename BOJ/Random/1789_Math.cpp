/**
 * @file 1789_Math.cpp
 * @brief 00:11:17
 * @date 2024-08-29
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll S, N = 1;

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> S;
    while ((N + 1) * (N + 2) / 2 <= S)
        N++;
    cout << N;

    return 0;
}