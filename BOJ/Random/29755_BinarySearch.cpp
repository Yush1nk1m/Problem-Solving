/**
 * @file 29755_BinarySearch.cpp
 * @brief 00:19:13
 * @date 2024-08-13
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int N, M, P, low = 0, high = 200000001;
vector<ll> hole;
vector<pair<ll, ll>> planet;

inline bool Check(int P);

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    hole.resize(N);
    planet.resize(M);

    for (int i = 0; i < N; i++)
        cin >> hole[i];
    for (int i = 0; i < M; i++)
        cin >> planet[i].first >> planet[i].second;

    sort(hole.begin(), hole.end());
    sort(planet.begin(), planet.end());

    while (low <= high) {
        int mid = (low + high) / 2;
        if (Check(mid)) {
            P = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    cout << P;

    return 0;
}

inline bool Check(int P) {
    int i = 0, j = 0;
    while (i < hole.size() && j < planet.size()) {
        if (abs(hole[i] - planet[j].first) <= P / planet[j].second)
            j++;
        else
            i++;
    }

    return (j == planet.size());
}