/**
 * @file 1072_BinarySearch.cpp
 * @brief 00:13:19
 * @date 2024-07-12
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll X, Y, Z, low = 1, high = 1000000001, result;

inline bool Changed(long game);

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> X >> Y;
    Z = (Y * 100 / X);
    if (Z >= 99) {
        cout << -1;
        return 0;
    }

    while (low <= high) {
        int mid = (low + high) / 2;
        if (Changed(mid)) {
            high = mid - 1;
            result = mid;
        } else {
            low = mid + 1;
        }
    }

    cout << result;
    
    return 0;
}

inline bool Changed(long game) {
    return ((Y + game) * 100 / (X + game) != Z); 
}