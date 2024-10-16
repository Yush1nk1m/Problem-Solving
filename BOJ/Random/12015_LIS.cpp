/**
 * @file 12015_LIS.cpp
 * @brief 00:15:00
 * @date 2024-10-16
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <bits/stdc++.h>
using namespace std;

int N;
vector<int> A;
vector<int> sequence(1, 0);

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    A.resize(N);
    for (int i = 0; i < N; i++)
        cin >> A[i];

    for (int number : A) {
        int idx = lower_bound(sequence.begin(), sequence.end(), number) - sequence.begin();

        if (idx == sequence.size())
            sequence.push_back(number);
        else
            sequence[idx] = min(sequence[idx], number);
    }

    cout << sequence.size() - 1;

    return 0;
}