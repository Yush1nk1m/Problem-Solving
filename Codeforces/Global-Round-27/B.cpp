#include <bits/stdc++.h>
using namespace std;

int t, n;
vector<string> table(501);

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    table[1] = "-1";
    table[2] = "66";
    table[3] = "-1";
    table[4] = "3366";
    table[5] = "36366";

    for (int i = 6; i <= 500; i++)
        table[i] = "33" + table[i-2];
    
    cin >> t;
    while (t--) {
        cin >> n;
        cout << table[n] << '\n';
    }
}
