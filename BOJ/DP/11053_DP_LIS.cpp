/**
 * @file 11053_DP_LIS.cpp
 * @brief 00:06:18
 * @date 2024-07-29
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <bits/stdc++.h>
using namespace std;

int N;
vector<int> numbers;
vector<int> len;

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    numbers.resize(N);
    for (int i = 0; i < N; i++)
        cin >> numbers[i];
    len.push_back(0);

    for (int n : numbers) {
        int l = lower_bound(len.begin(), len.end(), n) - len.begin();
        if (l == len.size())
            len.push_back(n);
        else
            len[l] = min(len[l], n);
    }

    cout << len.size() - 1;

    return 0;
}