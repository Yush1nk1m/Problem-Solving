/**
 * @file 2012_Greedy.cpp
 * @brief 00:09:12
 * @date 2024-10-11
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int N;
ll total;
vector<int> table(500001);

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    while (N--) {
        int rank;
        cin >> rank;
        table[rank]++;
    }

    int rank = 1, idx = 1;
    while (idx <= 500000) {
        if (table[idx]) {
            total += abs(rank - idx);
            table[idx]--;
            rank++;
        } else {
            idx++;
        }
    }

    cout << total;

    return 0;
}