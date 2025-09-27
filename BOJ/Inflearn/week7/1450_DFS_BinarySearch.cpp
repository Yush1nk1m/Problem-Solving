/**
 * @file 1450_DFS_BinarySearch.cpp
 * @brief 01:01:37
 * @date 2024-07-21
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int N, C;
ll result;
vector<ll> items;
vector<ll> sum1, sum2;

void DFS(ll low, ll high, ll sum, vector<ll>& sumv);

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> C;

    items.resize(N);
    for (int i = 0; i < N; i++)
        cin >> items[i];

    DFS(0, N/2, 0, sum1);
    DFS(N/2+1, N-1, 0, sum2);

    sort(sum1.begin(), sum1.end());
    sort(sum2.begin(), sum2.end());

    for (ll s1 : sum1) {
        ll remainder = C - s1;
        result += (upper_bound(sum2.begin(), sum2.end(), remainder) - sum2.begin());
    }

    cout << result;

    return 0;
}

void DFS(ll low, ll high, ll sum, vector<ll>& sumv) {
    if (low > high) {
        sumv.push_back(sum);
        return;
    }

    if (sum + items[low] <= C)
        DFS(low + 1, high, sum + items[low], sumv);
    DFS(low + 1, high, sum, sumv);
}