/**
 * @file 1912_DP.cpp
 * @brief 00:08:20
 * @date 2024-07-08
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> numbers, result;

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    numbers.resize(n);
    result.resize(n, 0);
    for (int i = 0; i < n; i++)
        cin >> numbers[i];

    result[0] = numbers[0];
    for (int i = 1; i < n; i++)
        result[i] = max(numbers[i], result[i-1] + numbers[i]);

    cout << *(max_element(result.begin(), result.end()));

    return 0;
}