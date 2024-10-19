#include <bits/stdc++.h>
using namespace std;

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        if (n == 1)
            cout << "0\n";
        else if (n == 2)
            cout << "01\n";
        else {
            string zeros(n - 2, '0');
            cout << "01" << zeros << '\n';
        }
    }
}
