/**
 * @file 2811_DP_Implementation.cpp
 * @brief 00:39:06
 * @date 2024-07-21
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <bits/stdc++.h>
using namespace std;

int N;
vector<int> mood;
vector<int> table;
vector<pair<int, int>> flowers;

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    mood.resize(N + 1, 0);
    table.resize(N + 1, 0);
    for (int i = 1; i <= N; i++)
        cin >> mood[i];

    for (int day = 1; day <= N; day++)
        if (mood[day] < 0)
            table[day] = table[day-1] + 1;
        else if (table[day-1] > 0)
            flowers.push_back({ table[day-1], day - (table[day-1] + 1) });
    if (mood[N] < 0)
        flowers.push_back({ table[N], N - table[N] });

    fill(table.begin(), table.end(), 0);
    sort(flowers.rbegin(), flowers.rend());
    
    int maxExtra = 0;
    if (!flowers.empty()) {
        for (int i = 0; i < flowers.size(); i++) {
            int f, day;
            tie(f, day) = flowers[i];
            f *= 2;
            for (int d = day; d > 0 && f > 0; d--, f--)
                table[d] = 1;
        }

        int maxf = flowers[0].first, maxfi = 0;
        while (flowers[maxfi].first == maxf) maxfi++;
        for (int i = 0; i < maxfi; i++) {
            int f, day, extra = 0;
            tie(f, day) = flowers[i];

            for (int d = day - 2*f; d > 0 && d > day - 3*f; d--)
                if (!table[d])
                    extra++;
            maxExtra = max(maxExtra, extra);
        }
    }

    cout << accumulate(table.begin(), table.end(), maxExtra);

    return 0;
}