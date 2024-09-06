/**
 * @file 1449_Greedy.cpp
 * @brief 00:06:06
 * @date 2024-09-06
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <bits/stdc++.h>
using namespace std;

int N, L, tape;
double curr;
vector<int> leak;

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> L;
    leak.resize(N);
    for (int i = 0; i < N; i++)
        cin >> leak[i];
    sort(leak.begin(), leak.end());

    for (int loc : leak)
        if (curr < loc) {
            tape++;
            curr = loc - 0.5 + L;
        }
    
    cout << tape;

    return 0;
}