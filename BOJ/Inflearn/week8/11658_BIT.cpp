/**
 * @file 11658_BIT.cpp
 * @brief 00:44:52
 * @date 2024-07-23
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define UPDATE  0
#define SUM     1

int N, M;
vector<vector<ll>> table, tree;

inline void Update(int x, int y, ll value);
inline ll PrefixSum(int x, int y);
inline ll Sum(int x1, int y1, int x2, int y2);

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    table.resize(N + 1, vector<ll>(N + 1));
    tree.resize(N + 1, vector<ll>(N + 1, 0));
    for (int x = 1; x <= N; x++)
        for (int y = 1; y <= N; y++) {
            cin >> table[x][y];
            Update(x, y, table[x][y]);
        }
    
    for (int _ = 0; _ < M; _++) {
        int w;
        cin >> w;

        if (w == UPDATE) {
            int x, y, c;
            cin >> x >> y >> c;
            
            ll diff = c - table[x][y];
            table[x][y] += diff;
            Update(x, y, diff);
        }
        else if (w == SUM) {
            int x1, y1, x2, y2;
            cin >> x1 >> y1 >> x2 >> y2;
            cout << Sum(x1, y1, x2, y2) << '\n';
        }
    }

    return 0;
}

inline void Update(int x, int y, ll value) {
    for (int X = x; X <= N; X += (X & -X))
        for (int Y = y; Y <= N; Y += (Y & -Y))
            tree[X][Y] += value;
}

inline ll PrefixSum(int x, int y) {
    ll sum = 0;
    for (int X = x; X > 0; X -= (X & -X))
        for (int Y = y; Y > 0; Y -= (Y & -Y))
            sum += tree[X][Y];
    return sum;
}

inline ll Sum(int x1, int y1, int x2, int y2) {
    return (PrefixSum(x2, y2) - PrefixSum(x1-1, y2) - PrefixSum(x2, y1-1) + PrefixSum(x1-1, y1-1));
}