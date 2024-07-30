/**
 * @file 1912_DP.cpp
 * @brief 00:02:55
 * @date 2024-07-30
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> table;

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    table.resize(n);
    for (int i = 0; i < n; i++)
        cin >> table[i];

    for (int i = 1; i < n; i++)
        table[i] = max(table[i], table[i] + table[i-1]);

    cout << *(max_element(table.begin(), table.end()));

    return 0;
}