#include <bits/stdc++.h>
using namespace std;

int N, L, R, X, mask = 1, cnt;
vector<int> A;

inline bool Evaluate(int mask);

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> L >> R >> X;
    A.resize(N);
    for (int i = 0; i < N; i++)
        cin >> A[i];
    sort(A.begin(), A.end());

    while (mask < (1 << N)) {
        cnt += Evaluate(mask++);
    }

    cout << cnt;

    return 0;
}

inline bool Evaluate(int mask) {
    vector<int> idx;
    for (int i = 0; i < N; i++) {
        if (mask & (1 << i)) {
            idx.push_back(i);
        }
    }

    int sum = 0, low, high;
    for (int i : idx) {
        sum += A[i];
    }
    low = A[idx[0]];
    high = A[idx[idx.size() - 1]];

    if (L <= sum && sum <= R && high - low >= X) {
        return true;
    }
    else {
        return false;
    }
}