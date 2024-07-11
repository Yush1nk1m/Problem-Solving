/**
 * @file 6236_BinarySearch.cpp
 * @brief 00:38:59
 * @date 2024-07-11
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <bits/stdc++.h>
using namespace std;

#define INF 1000000000

int N, M, low, high, result = INF;
vector<int> spend;

inline bool Affordable(int withdrawn);

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    spend.resize(N);
    for (int i = 0; i < N; i++)
        cin >> spend[i];

    low = *(max_element(spend.begin(), spend.end()));
    high = accumulate(spend.begin(), spend.end(), 1);
    while (low <= high) {
        int mid = (low + high) / 2;
        if (Affordable(mid)) {
            high = mid - 1;
            result = min(result, mid);
        } else {
            low = mid + 1;
        }
    }

    cout << result;

    return 0;
}

inline bool Affordable(int withdrawn) {
    int curr = withdrawn, cnt = 1;
    for (int amount : spend) {
        curr -= amount;
        if (curr < 0) {
            curr = withdrawn - amount;
            cnt++;
        }
    }
    
    return (cnt <= M);
}