/**
 * @file 2309_Recursive.cpp
 * @brief 00:04:03
 * @date 2024-06-22
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <bits/stdc++.h>
using namespace std;

vector<int> dwarfs(9);
vector<int> res;
int sum = 0;

void Print() {
    for (int number : res)
        cout << number << '\n';
    exit(0);
}

void Find(int start, int depth) {
    if (depth == 7 && sum == 100)
        Print();

    for (int i = start; i < 9; i++) {
        res.push_back(dwarfs[i]);
        sum += dwarfs[i];
        Find(i + 1, depth + 1);
        sum -= dwarfs[i];
        res.pop_back();
    }
}

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for (int i = 0; i < 9; i++)
        cin >> dwarfs[i];

    sort(dwarfs.begin(), dwarfs.end());

    Find(0, 0);
}