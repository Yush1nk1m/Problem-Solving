/**
 * @file 26168_BinarySearch.cpp
 * @brief 00:07:31
 * @date 2024-08-08
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, m;
vector<ll> numbers;

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    numbers.resize(n);
    for (int i = 0; i < n; i++)
        cin >> numbers[i];
    sort(numbers.begin(), numbers.end());

    while (m--) {
        ll command, i, j, k;
        cin >> command;

        if (command == 1) {
            cin >> k;
            cout << numbers.end() - lower_bound(numbers.begin(), numbers.end(), k) << '\n';
        } else if (command == 2) {
            cin >> k;
            cout << numbers.end() - upper_bound(numbers.begin(), numbers.end(), k) << '\n';
        } else if (command == 3) {
            cin >> i >> j;
            cout << upper_bound(numbers.begin(), numbers.end(), j) - lower_bound(numbers.begin(), numbers.end(), i) << '\n';
        }
    }

    return 0;
}