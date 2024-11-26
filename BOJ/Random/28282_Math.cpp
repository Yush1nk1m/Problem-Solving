#include <bits/stdc++.h>
using namespace std;

long X, K, result;
vector<long> s1, s2;

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> X >> K;
    s1.resize(X, 0);
    s2.resize(K + 1, 0);
    for (int i = 0; i < X; i++)
        cin >> s1[i];
    for (int i = 0; i < X; i++) {
        int socks;
        cin >> socks;
        s2[socks]++;
    }

    for (int socks : s1)
        result += (X - s2[socks]);

    cout << result;

    return 0;
}