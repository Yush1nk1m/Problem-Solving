/**
 * @file 14627_BinarySearch.cpp
 * @brief 00:20:07
 * @date 2024-07-13
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int S, C;
ll low = 1, high = 1000000001, maxLen, result;
vector<ll> lens;

inline bool Available(ll len);
inline ll CalcResult(ll len);

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> S >> C;
    lens.resize(S);
    for (int i = 0; i < S; i++)
        cin >> lens[i];
    
    while (low <= high) {
        ll mid = (low + high) / 2;
        if (Available(mid)) {
            maxLen = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    cout << CalcResult(maxLen);

    return 0;
}

inline bool Available(ll len) {
    ll cnt = 0;
    for (ll l : lens)
        cnt += (l / len);
    return (cnt >= C);
}

inline ll CalcResult(ll len) {
    ll cnt = 0, result = 0;
    for (ll l : lens) {
        ll remainedChunk = C - cnt, divChunk = l / len;
        if (remainedChunk >= divChunk) {
            cnt += divChunk;
            result += (l % len);
        } else {
            cnt += remainedChunk;
            result += (l - (len * remainedChunk));
        }
    }
    return result;
}