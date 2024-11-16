/**
 * @file 15975_Sweeping.cpp
 * @brief 00:14:09
 * @date 2024-11-16
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define INF 100000000

ll N, x, y, sum;

vector<vector<int>> pointList;  // [color][x coords]

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    pointList.resize(N + 1);
    for (int _ = 0; _ < N; _++) {
        cin >> x >> y;
        pointList[y].push_back(x);
    }

    for (int i = 1; i <= N; i++) {
        if (pointList[i].size() < 2)
            continue;

        sort(pointList[i].begin(), pointList[i].end());

        // add edge cases
        sum += abs(pointList[i][0] - pointList[i][1]);
        sum += abs(pointList[i][pointList[i].size() - 1] - pointList[i][pointList[i].size() - 2]);

        for (int j = 1; j < pointList[i].size() - 1; j++)
            sum += min(abs(pointList[i][j] - pointList[i][j-1]), abs(pointList[i][j] - pointList[i][j+1]));
    }

    cout << sum;

    return 0;
}