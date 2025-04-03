#include <bits/stdc++.h>
using namespace std;

#define AVAILABLE   '.'
#define NONE        -1

int C, N, M;
vector<vector<char>> table;
vector<vector<int>> cache;

int dfs(int col, int mask);
inline bool isValid(int prv, int curr, int col);

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> C;
    while (C--) {
        cin >> N >> M;
        table = vector<vector<char>>(10, vector<char>(10));
        cache = vector<vector<int>>(10, vector<int>(1 << 11, NONE));
        for (int r = 0; r < N; r++)
            for (int c = 0; c < M; c++)
                cin >> table[r][c];
        cout << dfs(0, 0) << '\n';
    }
}

int dfs(int col, int mask) {
    if (col == M)
        return 0;
    
    int& ret = cache[col][mask];
    if (ret != NONE)
        return ret;
        
    for (int curr = 0; curr < (1 << N); curr++)
        if (isValid(mask, curr, col)) {
            int b = 0;
            for (int i = 0; i < N; i++)
                if (curr & (1 << i))
                    b++;
            ret = max(ret, dfs(col + 1, curr) + b);
        }
            
    return ret;
}

inline bool isValid(int prv, int curr, int col) {
    for (int i = 0; i < N; i++)
        if (table[i][col] == AVAILABLE && curr & (1 << i) && (prv & (1 << i) || (prv & (1 << (i + 1)))))
            return false;
        else if (table[i][col] == AVAILABLE && curr & (1 << i) && i > 0 && (prv & (1 << (i - 1))))
            return false;
        else if (table[i][col] == UNAVAILABLE && curr & (1 << i))
            return false;
    return true;
}