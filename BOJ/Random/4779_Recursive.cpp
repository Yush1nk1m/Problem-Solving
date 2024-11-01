#include <bits/stdc++.h>
using namespace std;

int N, length;

inline void eraseDash(int from, int to, string& line);
void solve(int from, int to, string& line);

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    while (cin >> N) {
        length = pow(3, N);
        string line(length, '-');
        solve(0, length, line);
        cout << line << '\n';
    }

    return 0;
}

inline void eraseDash(int from, int to, string& line) {
    for (int i = from; i < to; i++)
        line[i] = ' ';
}

void solve(int from, int to, string& line) {
    if (from + 1 == to)
        return;

    int chunk = (to - from) / 3;
    solve(from, from + chunk, line);
    eraseDash(from + chunk, from + 2 * chunk, line);
    solve(from + 2 * chunk, to, line);
}