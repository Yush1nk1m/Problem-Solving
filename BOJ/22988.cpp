#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll N, X, result;
vector<ll> C;

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> X;
    for (int _ = 0; _ < N; _++) {
        ll c;
        cin >> c;
        
        if (c >= X) result++;
        else C.push_back(c);
    }
    sort(C.begin(), C.end());

    int l = 0, r = C.size() - 1, remain = 0;
    while (l <= r) {
        if (l < r && (C[l] + C[r]) * 2 >= X) {
            result++;
            l++;
            r--;
        } else {
            l++;
            remain++;
        }
    }

    result += (remain / 3);
    cout << result;

    return 0;
}