#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;

ll res1, res2;
pll p1, p2, p3, p4;

inline ll ccw(pll p1, pll p2, pll p3);
inline ll compress(ll number);

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> p1.first >> p1.second >> p2.first >> p2.second;
    cin >> p3.first >> p3.second >> p4.first >> p4.second;

    if (p1 > p2) {
        pll temp = p1;
        p1 = p2;
        p2 = temp;
    }
    if (p3 > p4) {
        pll temp = p3;
        p3 = p4;
        p4 = temp;
    }

    res1 = compress(ccw(p1, p2, p3)) * compress(ccw(p1, p2, p4));
    res2 = compress(ccw(p3, p4, p1)) * compress(ccw(p3, p4, p2));

    if (res1 == 0 && res2 == 0) {
        if (p3 <= p2 && p1 <= p4)
            cout << 1;
        else
            cout << 0;
    } else if (res1 <= 0 && res2 <= 0) {
        cout << 1;
    } else {
        cout << 0;
    }
}

inline ll ccw(pll p1, pll p2, pll p3) {
    ll x1 = p1.first, x2 = p2.first, x3 = p3.first;
    ll y1 = p1.second, y2 = p2.second, y3 = p3.second;

    return (x1*y2 + x2*y3 + x3*y1) - (x2*y1 + x3*y2 + x1*y3);
}

inline ll compress(ll number) {
    if (number > 0)
        return 1;
    else if (number < 0)
        return -1;
    else
        return number;
}