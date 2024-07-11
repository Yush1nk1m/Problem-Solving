/**
 * @file 2343_BinarySearch.cpp
 * @brief 00:11:26
 * @date 2024-07-11
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <bits/stdc++.h>
using namespace std;

#define INF 100000000

int N, M, result = INF;
vector<int> lecture;

inline bool Fit(int size);

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    lecture.resize(N);
    for (int i = 0; i < N; i++)
        cin >> lecture[i];

    
    int l = *(max_element(lecture.begin(), lecture.end())), r = accumulate(lecture.begin(), lecture.end(), 0);
    while (l <= r) {
        int mid = (l + r) / 2;
        if (Fit(mid)) {
            result = min(result, mid);
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }

    cout << result;

    return 0;
}

inline bool Fit(int size) {
    int curr = 0, cnt = 0;
    for (int len : lecture) {
        curr += len;
        if (curr > size) {
            cnt++;
            curr = len;
        }
    }
    cnt += (curr > 0);
    
    return (cnt <= M);
}