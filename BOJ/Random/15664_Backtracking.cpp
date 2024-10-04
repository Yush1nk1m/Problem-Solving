/**
 * @file 15664_Backtracking.cpp
 * @brief 00:40:45
 * @date 2024-10-04
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<int> numbers, result;

void DFS(int selected, int idx);

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    numbers.resize(N);
    for (int i = 0; i < N; i++)
        cin >> numbers[i];
    sort(numbers.begin(), numbers.end());

    DFS(0, 0);
    
    return 0;
}

void DFS(int selected, int idx) {
    if (selected == M) {
        for (int number : result)
            cout << number << ' ';
        cout << '\n';
        return;
    } else if (idx == N) {
        return;
    }

    int prior = 0;
    for (int i = idx; i < N; i++)
        if (numbers[i] != prior) {
            result.push_back(numbers[i]);
            DFS(selected + 1, i + 1);
            result.pop_back();
            prior = numbers[i];
        }
}