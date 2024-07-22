#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define UPDATE  1
#define SUM     2

int N, M, K;
vector<ll> sequence;
vector<ll> tree;

inline void Update(int i, ll value);
inline ll PrefixSum(int i);

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M >> K;
    sequence.resize(N + 1);
    tree.resize(N + 1, 0);
    for (int i = 1; i <= N; i++) {
        cin >> sequence[i];
        Update(i, sequence[i]);
    }

    for (int _ = 0; _ < M + K; _++) {
        ll a, b, c;
        cin >> a >> b >> c;

        if (a == UPDATE) {
            ll diff = c - sequence[b];
            sequence[b] += diff;
            Update(b, diff);
        }
        else if (a == SUM) {
            cout << PrefixSum(c) - PrefixSum(b-1) << '\n';
        }
    }

    return 0;
}

inline void Update(int i, ll value) {
    while (i <= N) {
        tree[i] += value;
        i += (i & -i);
    }
}

inline ll PrefixSum(int i) {
    ll sum = 0;
    while (i > 0) {
        sum += tree[i];
        i -= (i & -i);
    }
    return sum;
}