#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;

int n;
ll res;
vector<ll> A, B, C, D;
vector<ll> s1, s2;

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    A.resize(n);
    B.resize(n);
    C.resize(n);
    D.resize(n);

    for (int i = 0; i < n; i++)
        cin >> A[i] >> B[i] >> C[i] >> D[i];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            s1.push_back(A[i] + B[j]);
            s2.push_back(C[i] + D[j]);
        }

    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());

    for (ll number : s1)
        res += (ll)(upper_bound(s2.begin(), s2.end(), -number) - lower_bound(s2.begin(), s2.end(), -number));
    
    cout << res;

    return 0;
}