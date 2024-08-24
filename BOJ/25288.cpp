#include <bits/stdc++.h>
using namespace std;

long double n;

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    while (1) {
        cin >> n;
        if (n == 0) break;
        long double total = 0;
        for (int i = 0; i < 5; i++)
            total += pow(n, i);
        cout << fixed << setprecision(2) << total << '\n';
    }

    return 0;
}