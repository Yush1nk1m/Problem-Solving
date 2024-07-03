#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int N;
ll height, cnt, sum;
stack<pair<ll, ll>> stk;

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for (int _ = 0; _ < N; _++) {
        cin >> height;
        cnt = 1;
        while (!stk.empty() && stk.top().first <= height) {
            sum += stk.top().second;

            if (stk.top().first == height)
                cnt = stk.top().second + 1;

            stk.pop();
        }

        if (!stk.empty())
            sum++;
            
        stk.push({ height, cnt });
    }

    cout << sum;

    return 0;
}