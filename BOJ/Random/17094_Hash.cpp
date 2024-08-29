#include <bits/stdc++.h>
using namespace std;

int s;
map<char, int> m;

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    m['2'] = 0;
    m['e'] = 0;

    cin >> s;
    for (int _ : s) {
        char c;
        cin >> c;
        m[c]++;
    }

    if (m['2'] > m['e'])
        cout << 2;
    else if (m['2'] < m['e'])
        cout << 'e';
    else
        cout << "yee";

    return 0;
}