/**
 * @file 2170_Sweeping.cpp
 * @brief 00:24:55
 * @date 2024-07-09
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll len, sum, maxr;
int N;
vector<pair<ll, ll>> line;

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    line.resize(N);
    for (int i = 0; i < N; i++)
        cin >> line[i].first >> line[i].second;
    sort(line.begin(), line.end());

    len = line[0].second - line[0].first;
    maxr = line[0].second;
    for (int i = 1; i < line.size(); i++) {
        if (line[i].first <= maxr) {
            if (maxr < line[i].second) {
                len += (line[i].second - maxr);
                maxr = line[i].second;
            }
        }
        else {
            sum += len;
            len = line[i].second - line[i].first;
            maxr = line[i].second;
        }
    }
    sum += len;

    cout << sum;

    return 0;
}