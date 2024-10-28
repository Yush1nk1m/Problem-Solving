#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll t, n, m, r, c;

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> t;
    while (t--) {
        cin >> n >> m >> r >> c;
        cout << (n - r) * (m - 1) + (m - c) + (n - r) * m << '\n';
    }
}