#include <bits/stdc++.h>
using namespace std;

#define NONE    -1
#define UNABLE  0
#define ABLE    1

int n, dmask;
vector<vector<int>> table;
vector<vector<int>> cache(1 << 20, vector<int>(20, NONE));

inline bool isValidPoint(int r, int c);
int dfs(int diagonal);

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    table.resize(n, vector<int>(n));


    for (int r = 0; r < n; r++)
        for (int c = 0; c < n; c++)
            cin >> table[r][c];

    cout << dfs(0);

    return 0;
}

inline bool isValidPoint(int r, int c) {
    return 0 <= r && r < n && 0 <= c && c < n;
}

int dfs(int diagonal) {
    if (diagonal == 2 * n - 1)
        return 0;
    else if (cache[dmask][diagonal] != NONE)
        return cache[dmask][diagonal];
    
    int& maxMark = cache[dmask][diagonal];
    int r = min(n - 1, diagonal), c = max(0, diagonal - n + 1);
    while (isValidPoint(r, c)) {
        if (table[r][c] == ABLE && !(dmask & (1 << (r - c + n)))) {
            dmask |= (1 << (r - c + n));
            maxMark = max(maxMark, dfs(diagonal + 1) + 1);
            dmask ^= (1 << (r - c + n));
        }

        r--;
        c++;
    }
    maxMark = max(maxMark, dfs(diagonal + 1));

    return maxMark;
}