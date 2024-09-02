#include <bits/stdc++.h>
using namespace std;

int N;
vector<vector<char>> table;

inline void Record(int r1, int c1, int r2, int c2);

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    table.resize(N, vector<char>(N, ' '));
    Record(0, 0, N, N);

    for (int r = 0; r < N; r++) {
        for (int c = 0; c < N; c++)
            cout << table[r][c];
        cout << '\n';
    }

    return 0;
}

inline void Record(int r1, int c1, int r2, int c2) {
    if (r1 + 1 == r2 && c1 + 1 == c2)
        table[r1][c1] = '*';
    else {
        int rgap = (r2 - r1) / 3, cgap = (c2 - c1) / 3;
        for (int r = r1; r < r2; r += rgap)
            for (int c = c1; c < c2; c += cgap)
                if (r != r1 + rgap || c != c1 + cgap)
                    Record(r, c, r + rgap, c + cgap);
    }
}