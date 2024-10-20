#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll N, cnt;

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    ll i = 1;
    while (powl(i, 2) <= N) {
        cnt++;
        i++;
    }

    cout << cnt;

    return 0;
}
