#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int T, n, m;
ll cnt;
vector<int> A, B, asum, bsum;

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> T;

    cin >> n;
    A.resize(n + 1, 0);
    for (int i = 1; i <= n; i++)
        cin >> A[i];
    for (int i = 2; i <= n; i++)
        A[i] += A[i-1];
    for (int i = 0; i <= n; i++)
        for (int j = i + 1; j <= n; j++)
            asum.push_back(A[j] - A[i]);
    sort(asum.begin(), asum.end());

    cin >> m;
    B.resize(m + 1);
    for (int i = 1; i <= m; i++)
        cin >> B[i];
    for (int i = 2; i <= m; i++)
        B[i] += B[i-1];
    for (int i = 0; i <= m; i++)
        for (int j = i + 1; j <= m; j++)
            bsum.push_back(B[j] - B[i]);
    sort(bsum.begin(), bsum.end());

    for (int adder : asum)
        cnt += upper_bound(bsum.begin(), bsum.end(), T - adder) - lower_bound(bsum.begin(), bsum.end(), T - adder);

    cout << cnt;

    return 0;
}