#include <bits/stdc++.h>
#define FASTIO cin.tie(NULL);ios_base::sync_with_stdio(false);

using namespace std;
typedef long long ll;

inline void initialize();
inline void solve();

int TC, N;
vector<ll> v;

int main(int argc, char* argv[]) {
    FASTIO;
    cin >> TC;
    for (int _ = 0; _ < TC; ++_) {
        initialize();
        solve();
    }
}

inline void initialize() {
    cin >> N;
    v = vector<ll>((N * (N - 1)) >> 1);
    for (int i = 0; i < v.size(); ++i)
        cin >> v[i];
    sort(v.begin(), v.end());
}

inline void solve() {
    ll minimum = accumulate(v.begin(), v.begin() + N - 1, 0LL);
    ll maximum = 0;

    for (int i = 0, step = 1, s = 0; s < N - 1; i += step, ++step, ++s)
        maximum += v[i];

    cout << minimum << ' ' << maximum << '\n';
}