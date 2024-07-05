#include <bits/stdc++.h>
using namespace std;

int T, L, R;

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> T;
    for (int t = 1; t <= T; t++) {
        cin >> L >> R;
        int m = min(L, R);
        cout << "Case #" << t << ": " << m * (m + 1) / 2 << '\n';
    }

    return 0;
}