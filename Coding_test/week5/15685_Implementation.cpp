/**
 * @file 15685_Implementation.cpp
 * @brief 00:28:44
 * @date 2024-07-07
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <bits/stdc++.h>
using namespace std;

#define RIGHT   0
#define UP      1
#define LEFT    2
#define DOWN    3

class Curve {
    public:
        int x;
        int y;
        int dir;
        int gen;
};

int N, cnt;
bool table[101][101];
vector<Curve> curves;

inline void ConstructCurve(Curve& c);

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    curves.resize(N);
    for (int i = 0; i < N; i++)
        cin >> curves[i].x >> curves[i].y >> curves[i].dir >> curves[i].gen;

    for (Curve& c : curves)
        ConstructCurve(c);

    for (int y = 1; y <= 100; y++)
        for (int x = 1; x <= 100; x++)
            cnt += (table[y][x] && table[y-1][x] && table[y][x-1] && table[y-1][x-1]);

    cout << cnt;

    return 0;
}

inline void ConstructCurve(Curve& c) {
    vector<pair<int, int>> coord;

    coord.push_back({ c.x, c.y });
    if (c.dir == RIGHT)
        coord.push_back({ c.x + 1, c.y });
    else if (c.dir == UP)
        coord.push_back({ c.x, c.y - 1 });
    else if (c.dir == LEFT)
        coord.push_back({ c.x - 1, c.y });
    else if (c.dir == DOWN)
        coord.push_back({ c.x, c.y + 1 });

    for (pair<int, int>& crd : coord)
        table[crd.second][crd.first] = true;

    for (int g = 0; g < c.gen; g++) {
        pair<int, int> center = coord[coord.size() - 1];
        for (int i = coord.size() - 2; i >= 0; i--) {
            pair<int, int> point = coord[i];
            pair<int, int> diff = { point.first - center.first, point.second - center.second };
            pair<int, int> nextp = { center.first - diff.second, center.second + diff.first };
            table[nextp.second][nextp.first] = true;
            coord.push_back(nextp);
        }
    }
}