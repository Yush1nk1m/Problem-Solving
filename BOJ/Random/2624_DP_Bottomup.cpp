#include <bits/stdc++.h>
using namespace std;

int T, k;
vector<pair<int, int>> coin;
vector<int> table;

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> T >> k;

    coin.resize(k);
    for (int i = 0; i < k; i++)
        cin >> coin[i].first >> coin[i].second;

    table.resize(T + 1, 0);
    table[0] = 1;
    for (int i = 0; i < k; i++) {
        int p = coin[i].first;
        int n = coin[i].second;

        for (int value = T; value >= 0; value--)
            for (int cnt = 1; cnt <= n && value - (p * cnt) >= 0; cnt++)
                table[value] += table[value - (p * cnt)];
    }

    cout << table[T];

    return 0;
}