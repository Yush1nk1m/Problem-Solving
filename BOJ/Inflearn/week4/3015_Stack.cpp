/**
 * @file 3015_Stack.cpp
 * @brief 01:21:38
 * @date 2024-07-04
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int N;
ll sum;
stack<pair<ll, ll>> stk;    // { [height], [same seq.] }

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; i++) {
        ll height;
        cin >> height;
        
        ll cnt = 1;
        while (!stk.empty() && stk.top().first <= height) {
            sum += stk.top().second;

            if (stk.top().first < height) {
                cnt = 1;
            }
            else {
                cnt = stk.top().second + 1;
            }

            stk.pop();
        }

        if (!stk.empty())
            sum++;

        stk.push({ height, cnt });
    }

    cout << sum;

    return 0;
}