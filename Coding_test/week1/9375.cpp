/**
 * @file 9375.cpp
 * @brief 00:13:53
 * @date 2024-06-23
 * 
 * @copyright Copyright (c) 2024
 * 테스트 케이스를 나누는 문제는 shard variable을 최소화하자.
 */

#include <bits/stdc++.h>
using namespace std;

int T, N;

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> T;
    for (int _1 = 0; _1 < T; _1++) {
        cin >> N;
        if (N == 0) {
            cout << "0\n";
            continue;
        }
        
        map<string, int> cmap;
        vector<string> types;

        for (int _2 = 0; _2 < N; _2++) {
            string name, type;
            cin >> name >> type;

            if (cmap.find(type) == cmap.end()) {
                types.push_back(type);
                cmap[type] = 1;
            }
            else
                cmap[type]++;
        }

        int res = 1;
        for (string type : types)
            res *= (cmap[type] + 1);
        
        cout << res - 1 << '\n';
    }

    return 0;
}