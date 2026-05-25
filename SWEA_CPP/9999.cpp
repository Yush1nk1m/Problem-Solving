#include <bits/stdc++.h>
using namespace std;

int T, L, N;
vector<pair<int, int>> v;

inline void initialize();
inline void solve();

int main(int argc, char* argv[]) {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> T;
    for (int x = 1; x <= T; ++x) {
        cout << '#' << x << ' ';
        initialize();
        solve();
    }

    return 0;
}

inline void initialize() {
    cin >> L >> N;
    v = vector<pair<int, int>>(N);
    for (int i = 0; i < N; ++i)
        cin >> v[i].first >> v[i].second;
}

inline void solve() {
    int l = 0, r = 0, time = v[0].second - v[0].first, maximum = 0;
    while (r < N) {
        if (v[r].second - v[l].first <= L) {
            maximum = max(maximum, time);
            if (++r < N)
                time += v[r].second - v[r].first;
        } else {
            maximum = max(maximum, 
                time - (v[r].second - v[r].first) + max(0, v[l].first + L - v[r].first));
            time -= v[l].second - v[l].first;
            ++l;
        }
    }
    cout << maximum << '\n';
}