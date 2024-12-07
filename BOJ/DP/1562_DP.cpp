#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define MOD     1000000000
#define NONE    -1

int N;
ll total;
vector<vector<vector<ll>>> cache(10, vector<vector<ll>>(101, vector<ll>(1 << 10, NONE)));

ll dfs(int number, int depth, int mask);

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for (int i = 1; i <= 9; i++) {
        total += dfs(i, 1, 1 << i) % MOD;
        total %= MOD;
    }

    cout << total;

    return 0;
}

ll dfs(int number, int depth, int mask) {
    if (depth == N) {
        if (mask == (1 << 10) - 1)
            return 1;
        else
            return 0;
    }

    ll& ret = cache[number][depth][mask];
    if (ret != NONE)
        return ret;

    if (number == 0)
        ret = dfs(1, depth + 1, mask | (1 << 1)) % MOD;
    else if (number == 9)
        ret = dfs(8, depth + 1, mask | (1 << 8)) % MOD;
    else
        ret = ((dfs(number - 1, depth + 1, mask | 1 << (number - 1)) % MOD) + (dfs(number + 1, depth + 1, mask | 1 << (number + 1)) % MOD)) % MOD;
    ret %= MOD;

    return ret;
}