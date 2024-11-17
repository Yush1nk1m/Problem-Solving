/**
 * @file 1484_Math.cpp
 * @brief 00:09:41
 * @date 2024-11-17
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <bits/stdc++.h>
using namespace std;

long G;

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> G;
    bool isExist = false;
    for (long prv = 1; prv <= 100000; prv++) {
        long powPrev = powl(prv, 2);
        long powCurr = powPrev + G;
        if (powl((long)sqrt(powCurr), 2) == powCurr) {
            isExist = true;
            cout << (long)sqrt(powCurr) << '\n';
        }
    }
        
    if (!isExist)
        cout << -1;

    return 0;
}