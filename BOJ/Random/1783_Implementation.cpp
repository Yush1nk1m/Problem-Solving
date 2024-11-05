#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll N, M;

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    if (N == 1)
        cout << 1;
    else if (N == 2)
        cout << min((M + 1) / 2, 4LL);
    else {
        if (M < 5)
            cout << M;
        else
            cout << max(4LL, M - 2);
    }
}