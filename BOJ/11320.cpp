#include <bits/stdc++.h>
using namespace std;

int T, A, B;

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> T;
    for (int _ = 0; _ < T; _++) {
        cin >> A >> B;
        cout << (A * A) / (B * B) << '\n';
    }

    return 0;
}