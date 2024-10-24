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

        if (n % 2 == 0)
            cout << "Sakurako\n";
        else
            cout << "Kosuke\n";
    }
}