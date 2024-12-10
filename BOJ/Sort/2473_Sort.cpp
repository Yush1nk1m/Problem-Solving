#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define INF 3000000001LL

int N;
ll minAbs = INF;
tuple<ll, ll, ll> result;
vector<ll> v;

inline ll bSearch(int l, int r, ll target);

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    v.resize(N);
    for (int i = 0; i < N; i++)
        cin >> v[i];
    sort(v.begin(), v.end());

    for (int l = 0; l < N - 2; l++)
        for (int r = l + 2; r < N; r++) {
            ll amount = v[l] + v[r];
            ll target = bSearch(l + 1, r - 1, -amount);
            amount += target;

            if (llabs(amount) < minAbs) {
                minAbs = llabs(amount);
                result = make_tuple(v[l], target, v[r]);
            }
        }

    cout << get<0>(result) << ' ' << get<1>(result) << ' ' << get<2>(result);

    return 0;
}

inline ll bSearch(int l, int r, ll target) {
    if (l == r)
        return v[l];

    auto b = v.begin() + l;
    auto e = v.begin() + r + 1;
    auto it = lower_bound(b, e, target);

    if (it == b)
        return *it;
    else if (it == e)
        return *(it - 1);
    else
        return (llabs(*it - target) < llabs(*(it - 1) - target) ? *it : *(it - 1));
}