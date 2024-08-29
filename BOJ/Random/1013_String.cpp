#include <bits/stdc++.h>
using namespace std;

int T;
string input;

inline bool Match(string input);

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> T;
    while (T--) {
        cin >> input;
        if (Match(input))
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}

inline bool Match(string input) {
    regex e("(100+1+|01)+");
    return regex_match(input, e);
}