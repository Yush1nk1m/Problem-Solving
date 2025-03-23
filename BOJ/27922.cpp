#include <bits/stdc++.h>
using namespace std;

int N, K, s1, s2, s3;
vector<int> v1, v2, v3;

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        v1.push_back(a + b);
        v2.push_back(b + c);
        v3.push_back(a + c);
    }
    
    sort(v1.rbegin(), v1.rend());
    sort(v2.rbegin(), v2.rend());
    sort(v3.rbegin(), v3.rend());

    s1 = accumulate(v1.begin(), v1.begin() + K, 0);
    s2 = accumulate(v2.begin(), v2.begin() + K, 0);
    s3 = accumulate(v3.begin(), v3.begin() + K, 0);

    cout << max(s1, max(s2, s3));

    return 0;
}