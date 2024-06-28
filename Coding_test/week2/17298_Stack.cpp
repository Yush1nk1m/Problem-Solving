/**
 * @file 17298_Stack.cpp
 * @brief 00:25:33
 * @date 2024-06-28
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <bits/stdc++.h>
using namespace std;

int N, number;
vector<int> nge;
stack<pair<int, int>> stk;

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    nge.resize(N + 1, -1);
    for (int index = 1; index <= N; index++) {
        cin >> number;
        while (!stk.empty() && stk.top().second < number) {
            pair<int, int> curr = stk.top();
            stk.pop();
            nge[curr.first] = number;
        }
        stk.push({ index, number });
    }

    for (int i = 1; i <= N; i++)
        cout << nge[i] << ' ';

    return 0;
}