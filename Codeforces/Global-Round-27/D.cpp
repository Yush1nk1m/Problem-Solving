// FAILED

// #include <bits/stdc++.h>
// using namespace std;
// typedef long long ll;

// #define MOD 1000000007

// int t, n;

// inline void solve();

// int main(int argc, char* argv[]) {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     cout.tie(NULL);

//     cin >> t;
//     while (t--) {
//         cin >> n;
//         solve();
//     }
// }

// inline void solve() {
//     vector<ll> numbers(n);
    
//     for (int i = 0; i < n; i++)
//         cin >> numbers[i];
    
//     ll sum = 0;
//     sum = numbers[0];
//     cout << sum << ' ';

//     for (int i = 1; i < n; i++) {
//         ll origin = numbers[i-1];
//         while (numbers[i-1] % 2 == 0) {
//             numbers[i-1] /= 2;
//             numbers[i] *= 2;
//         }
//         sum -= (origin - numbers[i-1]) % MOD;
//         sum += numbers[i] % MOD;
//         sum %= MOD;
        
//         numbers[i] %= MOD;
//         cout << sum << ' ';
//     }

//     cout << '\n';
// }