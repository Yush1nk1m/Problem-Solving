/**
 * @file 13701_Bitmasking.cpp
 * @brief 00:24:26
 * @date 2024-10-15
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <bits/stdc++.h>
using namespace std;

int mask[(1 << 20)];

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    while (cin >> n) {
        if (!(mask[n / 32] & (1 << (n % 32)))) {
            mask[n / 32] |= (1 << (n % 32));
            cout << n << ' ';
        }
    }

    return 0;
}