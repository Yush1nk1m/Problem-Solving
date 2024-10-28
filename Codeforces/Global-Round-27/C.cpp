// FAILED

// #include <bits/stdc++.h>
// using namespace std;

// int t, n;
// vector<int> bits(200001);

// inline void constructBitCount();
// inline void solve();

// int main(int argc, char* argv[]) {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     cout.tie(NULL);

//     constructBitCount();

//     cin >> t;
//     while (t--) {
//         cin >> n;
//         solve();
//     }
// }

// inline void constructBitCount() {
//     for (int i = 0; i <= 200000; i++) {
//         int cnt = 0;
//         for (int s = 0; s <= log2(i); s++)
//             if (i & (1 << s))
//                 cnt++;
//         bits[i] = cnt;
//     }
// }

// inline void solve() {
//     vector<bool> visited(n + 1, false);
//     deque<int> v(n);
//     deque<pair<int, int>> bv(n); // <bits, number>
//     vector<int> result(n + 1);

//     for (int i = 0; i < n; i++) {
//         bv[i].first = bits[i + 1];
//         bv[i].second = i + 1;
//         v[i] = n - i;
//     }

//     sort(bv.rbegin(), bv.rend());

//     cout << "bits order: ";
//     for (auto p : bv)
//         cout << "(" << p.first << ", " << p.second << ") ";
//     cout << endl;

//     for (int i = 1; i <= n; i++) {
//         // if it is odd(&), select the maximum number
//         if (i % 2 == 1) {
//             while (visited[v.back()])
//                 v.pop_back();
//             result[i] = v.back();
//             visited[v.back()] = true;
//             v.pop_back();
//         }
//         // if it is even(|), select the number with the maximum bits
//         else {
//             while (visited[bv.back().second])
//                 bv.pop_back();
//             result[i] = bv.back().second;
//             visited[bv.back().second] = true;
//             bv.pop_back();
//         }
//     }

//     int sum = 0;
//     for (int i = 1; i <= n; i++) {
//         if (i % 2 == 1)
//             sum = sum & result[i];
//         else
//             sum = sum | result[i];
//     }

//     cout << "sum: " << sum << '\n';
//     for (int i = 1; i <= n; i++)
//         cout << result[i] << ' ';
//     cout << '\n';
// }