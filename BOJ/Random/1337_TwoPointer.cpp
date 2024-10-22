/**
 * @file 1337.cpp
 * @brief 00:26:04
 * @date 2024-10-22
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <bits/stdc++.h>
using namespace std;

int N, minCount = 4;
vector<int> numbers;

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    numbers.resize(N);
    for (int i = 0; i < N; i++)
        cin >> numbers[i];
    sort(numbers.begin(), numbers.end());
    numbers.push_back(0);

    for (int i = 0; i < N; i++) {
        int j = i + 1, cnt = 0, curr = numbers[i];
        for (int adder = 1; adder < 5; adder++) {
            if (numbers[j] == curr + adder)
                j++;
            else
                cnt++;
        }
        minCount = min(minCount, cnt);
    }

    cout << minCount;

    return 0;
}