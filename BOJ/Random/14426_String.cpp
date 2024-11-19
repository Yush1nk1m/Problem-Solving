/**
 * @file 14426_String.cpp
 * @brief 00:06:41
 * @date 2024-11-18
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <bits/stdc++.h>
using namespace std;

int N, M, cnt;
vector<string> words;

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    words.resize(N);
    for (int i = 0; i < N; i++)
        cin >> words[i];
    sort(words.begin(), words.end());

    while (M--) {
        string prefix;
        cin >> prefix;

        string originalSub = string(*lower_bound(words.begin(), words.end(), prefix)).substr(0, prefix.length());
        if (originalSub == prefix)
            cnt++;
    }

    cout << cnt;

    return 0;
}