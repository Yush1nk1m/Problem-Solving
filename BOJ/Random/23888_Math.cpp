/**
 * @file 23888_Math.cpp
 * @brief 01:00:00
 * @date 2024-08-07
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll a, d, q, query, l, r;

inline ll Term(int i);
inline ll Sum(int l, int r);
inline ll GCD(int l, int r);

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> a >> d >> q;

    for (int _ = 0; _ < q; _++) {
        cin >> query >> l >> r;

        if (query == 1)
            cout << Sum(l, r) << '\n';
        else
            cout << GCD(l, r) << '\n';
    }

    return 0;
}

inline ll Term(int i) {
    return (a + (d * (i - 1)));
}

inline ll Sum(int l, int r) {
    return ((Term(l) + Term(r)) * (r - l + 1) / 2);
}

inline ll GCD(int l, int r) {
    if (l == r)
        return Term(l);

    ll a = Term(l), b = d;

    while (b) {
        ll temp = a;
        a = b;
        b = temp % b;
    }

    return a;
}