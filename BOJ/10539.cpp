#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int N;
ll sum;
vector<ll> v;

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for (ll i = 1; i <= N; i++) {
        ll number;
        cin >> number;
        v.push_back(number * i - sum);
        sum += number * i - sum;
    }

    for (ll number : v)
        cout << number << ' ';

    return 0;
}