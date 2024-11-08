/**
 * @file 1358_Math.cpp
 * @brief 00:09:26
 * @date 2024-11-08
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <bits/stdc++.h>
using namespace std;

int cnt;
double W, H, X, Y, P, R;

inline double distance(double x1, double y1, double x2, double y2);
inline bool isIn(double x, double y);

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> W >> H >> X >> Y >> P;
    R = H / 2.0;
    while (P--) {
        double x, y;
        cin >> x >> y;
        cnt += isIn(x, y);
    }

    cout << cnt;

    return 0;
}

inline double distance(double x1, double y1, double x2, double y2) {
    return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}

inline bool isIn(double x, double y) {
    return (X <= x && x <= X + W && Y <= y && y <= Y + H)
        || (distance(X, Y + R, x, y) <= R) || (distance(X + W, Y + R, x, y) <= R);
}