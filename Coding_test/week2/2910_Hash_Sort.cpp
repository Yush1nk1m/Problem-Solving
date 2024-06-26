/**
 * @file 2910_Hash_Sort.cpp
 * @brief 00:12:40
 * @date 2024-06-26
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <bits/stdc++.h>
using namespace std;

int N, C;
vector<int> numbers;
map<int, int> cnt;
map<int, int> indices;

inline bool compare(int n1, int n2) {
    if (cnt[n1] == cnt[n2]) {
        return (indices[n1] > indices[n2]);
    }
    else return cnt[n1] < cnt[n2];
}

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> C;
    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;

        numbers.push_back(num);
        if (cnt.find(num) == cnt.end())
            cnt[num] = 1;
        else
            cnt[num]++;
        if (indices.find(num) == indices.end())
            indices[num] = i;
    }

    sort(numbers.rbegin(), numbers.rend(), compare);
    for (int number : numbers)
        cout << number << ' ';

    return 0;
}